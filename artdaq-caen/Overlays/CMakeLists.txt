cet_make_library(LIBRARY NAME Overlays

SOURCE
CAENV1720Fragment.cc
CAENV1730Fragment.cc
FragmentType.cc
LIBRARIES PUBLIC
artdaq-core::Utilities
artdaq-core::Data
TRACE::TRACE
)

include(ArtdaqCorePlugins)
cet_build_plugin(ArtdaqCaen artdaq::FragmentNameHelper LIBRARIES REG artdaq-caen::Overlays)

install_headers()
install_source()
