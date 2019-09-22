# GNURadio Callbacks (XML)

To implement a callback, you have to modify **four** files in the OOT module:

1. `grc/callback_xml_demod.xml` ... GRC/SWIG/Python glue XML configuration file
2. `include/callback_xml/demod.h` ... exported C++ header file
3. `lib/demod_impl.h` ... opaque C++ header file
4. `lib/demod_impl.cc` ... opaque C++ code file

Open `examples/callback_example.grc` in GRC to test the flowgraph. Note that (although it's good convention) the variable used in the flowgraph does not actually need to have the same name as the variable in the XML file. It just needs to match between the `demod` block and the `QT GUI Entry` block.
