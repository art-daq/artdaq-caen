//
//  CAENConfiguration.cc
//
//  Class to read and contain SBND CAEN configuration
//   parameters
//
//
#define TRACE_NAME "CAENConfiguration"
#include "artdaq/DAQdata/Globals.hh"

#include "CAENConfiguration.hh"

// Constructor
artdaqcaen::CAENConfiguration::CAENConfiguration(fhicl::ParameterSet const & ps):
  link(0),
  firstBoardId(0),
  nBoards(0),
  enableReadout(0),
  boardId(0),
  recordLength(0),
  postPercent(0),
  irqWaitTime(0),
  allowTriggerOverlap(true),
  usePedestals(0),
  dacValue(0),
  dynamicRange(0),
  ioLevel(0),
  nChannels(0),
  triggerPolarity(0),
  extTrgMode(0),
  swTrgMode(0),
  acqMode(0),
  debugLevel(0),
  runSyncMode(0),
  outputSignalMode(0),
  eventCounterWarning(0),
  memoryAlmostFull(0),
  analogMode(0),
  testPattern(0)
{
  link                 = ps.get<int>("link");
  enableReadout        = ps.get<int>("enableReadout");
  boardId              = ps.get<int>("boardId");
  recordLength         = ps.get<int>("recordLength");
  runSyncMode          = ps.get<int>("runSyncMode");
  outputSignalMode     = ps.get<int>("outputSignalMode");
  allowTriggerOverlap  = ps.get<bool>("allowTriggerOverlap");
  usePedestals         = ps.get<bool>("usePedestals");
  dacValue             = ps.get<int>("dacValue");
  dynamicRange         = ps.get<int>("dynamicRange");
  ioLevel              = ps.get<int>("ioLevel");
  nChannels            = ps.get<int>("nChannels");
  extTrgMode           = ps.get<int>("extTrgMode");
  swTrgMode            = ps.get<int>("swTrgMode");
  acqMode              = ps.get<int>("acqMode");
  triggerPolarity      = ps.get<int>("triggerPolarity");
  triggerPulseWidth    = ps.get<uint8_t>("triggerPulseWidth");
  debugLevel           = ps.get<int>("debugLevel");
  postPercent          = ps.get<int>("postPercent");
  irqWaitTime          = ps.get<int>("irqWaitTime");
  eventCounterWarning  = ps.get<int>("eventCounterWarning");
  memoryAlmostFull     = ps.get<int>("memoryAlmostFull");
  readoutMode          = ps.get<int>("readoutMode");
  analogMode           = ps.get<int>("analogMode");
  testPattern          = ps.get<int>("testPattern");

  char tag[1024];
  channelEnableMask = 0;

  for ( int j=0; j<MAX_CHANNELS; j++){
    sprintf(tag,"triggerThreshold%d", j);
    triggerThresholds[j] = ps.get<uint16_t>(tag);
  }

  if ( enableReadout ){
    for ( int j=0; j<MAX_CHANNELS; j++){
      sprintf(tag,"channelEnable%d", j);
      channelEnable[j] = ps.get<bool>(tag);
      if ( channelEnable[j] )
      {
	channelEnableMask |= ( 1 << j );
	sprintf(tag,"channelPedestal%d", j);
	pedestal[j] = ps.get<int>(tag);
      }

      /*
      sprintf(tag,"channelSelfTrgMode%d", j);
      channelSelfTrgMode[j] = ps.get<bool>(tag);
      if ( channelSelfTrgMode[j] )
      {
	channelEnableMask |= ( 1 << j );
	sprintf(tag,"channelPedestal%d", j);
	pedestal[j] = ps.get<int>(tag);
      }
      */
    }
  }
}

