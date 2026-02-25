
cet_build_plugin(CAENV1720Dump art::module
    LIBRARIES REG
    artdaq-caen::Overlays
    art_root_io::tfile_support
    ROOT::Hist
    ROOT::Tree
)

cet_build_plugin(CAENV1730Dump art::module
    LIBRARIES REG
    artdaq-caen::Overlays
    art_root_io::tfile_support
    ROOT::Hist
    ROOT::Tree
)

cet_build_plugin(CAENV1730WaveformAna art::module
    LIBRARIES REG
    artdaq-caen::Overlays
    art_root_io::tfile_support
    ROOT::Hist
    ROOT::Tree
)
