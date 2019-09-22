#ifdef HAVE_CONFIG_H
#include "config.h"
#endif // HAVE_CONFIG_H

#include <gnuradio/io_signature.h>
#include "demod_impl.h"

#include <cstdio> 



namespace gr
{
    namespace callback_xml
    {
        demod::sptr demod::make(
            const char* bitstream)
        {
            return gnuradio::get_initial_sptr(
                new demod_impl(
                    bitstream));
        }


        demod_impl::demod_impl(
            const char* bitstream) :
            gr::block(
                "demod",
                gr::io_signature::make(0, 0, 0),
                gr::io_signature::make(0, 0, 0))
        {
            msg_cnt = 0;

            m_bits = new uint8_t[BITSTREAM_MAX_LEN];
            memset(m_bits, 0x00, BITSTREAM_MAX_LEN * sizeof(uint8_t));
            m_num_bits = 0;

            ConvertBitStream(bitstream);

            m_port_in = pmt::mp("in");
            message_port_register_in(m_port_in);
            set_msg_handler(m_port_in, boost::bind(&demod_impl::HandlePdu, this, _1));
        }


        demod_impl::~demod_impl()
        {
            delete[] m_bits;
        }


        void demod_impl::SetBitStream(
            const char* bitstream)
        {
            ConvertBitStream(bitstream);
        }


        void demod_impl::HandlePdu(
            pmt::pmt_t pdu)
        {
            msg_cnt++;
            printf("[*] demod_impl: processing a PDU (total messages = %u)\n", msg_cnt);
        }


        void demod_impl::ConvertBitStream(
            const char* bitstream)
        {
            // get string length
            m_num_bits = (unsigned int)strnlen(bitstream, BITSTREAM_MAX_LEN);

            // null string
            if (m_num_bits == 0)
            {
                printf("[*] demod_impl: bitstream cleared\n");
                return;
            }

            // check characters
            for (unsigned int i = 0; i < m_num_bits; i++)
            {
                if (bitstream[i] != '0' &&
                    bitstream[i] != '1')
                {
                    fprintf(stderr, "[!] demod_impl: illegal character in bitstream string ");
                    fprintf(stderr, "(pos = %u, char = %c)\n", i, bitstream[i]);
                    return;
                }
            }

            // convert
            for (unsigned int i = 0; i < m_num_bits; i++)
            {
                if (bitstream[i] == '0') { m_bits[i] = 0; }
                else { m_bits[i] = 1; }
            }

            // print for debug purposes
            printf("[*] demod_impl: bitstream length = %u bits\n", m_num_bits);
            printf("[*] demod_impl: bitstream:\n");

            for (unsigned int i = 0; i < m_num_bits; i++)
            {
                printf("%u, ", m_bits[i]);
                if ((i+1) % 32 == 0) { printf("\n"); }
            }
            
            printf("\n");
        }

    } // namespace callback_xml
} // namespace gr
