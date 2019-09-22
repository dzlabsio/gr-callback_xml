#ifndef CALLBACK_XML_DEMOD_IMPL_H
#define CALLBACK_XML_DEMOD_IMPL_H

#include <callback_xml/demod.h>

#include <cstdint>

#define BITSTREAM_MAX_LEN 256



namespace gr
{
    namespace callback_xml
    {
        class demod_impl : public demod
        {
        public:
            demod_impl(
                const char* bitstream);

            ~demod_impl();

            // override callback function in base class
            void SetBitStream(
                const char* bitstream) override;

        private:
            unsigned int msg_cnt;
            uint8_t* m_bits;
            unsigned int m_num_bits;
            pmt::pmt_t m_port_in;

            void HandlePdu(
                pmt::pmt_t pdu);

            void ConvertBitStream(
                const char* bitstream);
        };

    } // namespace callback_xml
} // namespace gr



#endif // CALLBACK_XML_DEMOD_IMPL_H
