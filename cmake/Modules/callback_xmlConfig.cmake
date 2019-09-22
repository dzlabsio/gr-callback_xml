INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_CALLBACK_XML callback_xml)

FIND_PATH(
    CALLBACK_XML_INCLUDE_DIRS
    NAMES callback_xml/api.h
    HINTS $ENV{CALLBACK_XML_DIR}/include
        ${PC_CALLBACK_XML_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    CALLBACK_XML_LIBRARIES
    NAMES gnuradio-callback_xml
    HINTS $ENV{CALLBACK_XML_DIR}/lib
        ${PC_CALLBACK_XML_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(CALLBACK_XML DEFAULT_MSG CALLBACK_XML_LIBRARIES CALLBACK_XML_INCLUDE_DIRS)
MARK_AS_ADVANCED(CALLBACK_XML_LIBRARIES CALLBACK_XML_INCLUDE_DIRS)

