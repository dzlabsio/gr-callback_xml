#ifndef CALLBACK_XML_DEMOD_H
#define CALLBACK_XML_DEMOD_H

#include <callback_xml/api.h>
#include <gnuradio/block.h>



namespace gr
{
    namespace callback_xml
    {
        class CALLBACK_XML_API demod : virtual public gr::block
        {
        public:
            typedef boost::shared_ptr<demod> sptr;

            static sptr make(
                const char* bitstream);

            // callback function
            virtual void SetBitStream(
                const char* bitstream) = 0;
        };

    } // namespace callback_xml
} // namespace gr



#endif // CALLBACK_XML_DEMOD_H
