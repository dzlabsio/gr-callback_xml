from gnuradio import gr, gr_unittest
from gnuradio import blocks
import callback_xml_swig as callback_xml



class qa_demod (gr_unittest.TestCase):

    def setUp (self):
        self.tb = gr.top_block ()

    def tearDown (self):
        self.tb = None

    def test_001_t (self):
        # set up fg
        self.tb.run ()
        # check data



if __name__ == '__main__':
    gr_unittest.run(qa_demod, "qa_demod.xml")
