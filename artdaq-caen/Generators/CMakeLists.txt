
cet_make_library(
  SOURCE
    workerThread.cpp
    PoolBuffer.cc
    CAENDecoder.cc
    CAENConfiguration.cc
    CAENException.cc
  LIBRARIES
    pthread
    artdaq::DAQdata
    messagefacility::MF_MessageLogger
    CAEN::Comm
    CAEN::Digitizer
)

include(artdaq::commandableGenerator)
cet_build_plugin(CAENV1730Readout artdaq::commandableGenerator LIBRARIES REG artdaq-caen::Generators )
cet_build_plugin(CAENV1720Readout artdaq::commandableGenerator LIBRARIES REG artdaq-caen::Generators )
cet_build_plugin(CAENV1720SpillReadout artdaq::commandableGenerator LIBRARIES REG artdaq-caen::Generators )


install_source()
install_headers()
