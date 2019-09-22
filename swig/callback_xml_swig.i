/* -*- c++ -*- */

#define CALLBACK_XML_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "callback_xml_swig_doc.i"

%{
#include "callback_xml/demod.h"
%}



%include "callback_xml/demod.h"
GR_SWIG_BLOCK_MAGIC2(callback_xml, demod)
