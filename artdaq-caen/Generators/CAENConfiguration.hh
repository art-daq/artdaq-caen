//
//  CAENConfiguration.h   (W.Badgett)
//

#ifndef _CAENConfiguration_h
#define _CAENConfiguration_h

#include <iostream>
#include "CAENDecoder.hh"
#include "fhiclcpp/ParameterSet.h"

namespace artdaqcaen
{
class CAENConfiguration
{
  public:
  enum
  {
    MAX_BOARDS = 6,
    MAX_CHANNELS = 8
  };

  virtual ~CAENConfiguration() {}
  CAENConfiguration(fhicl::ParameterSet const & ps);

    int  link;
    int  firstBoardId;
    int  nBoards;
    int  enableReadout;
    int  boardId;
    int  recordLength;
    int  postPercent;
    int  eventsPerInterrupt;
    int  irqWaitTime;
    bool allowTriggerOverlap;
    bool usePedestals;
    int  dacValue;
    int  dynamicRange;
    int  ioLevel;
    int  nChannels;
    int  triggerPolarity;
    uint16_t triggerThresholds[MAX_CHANNELS];
    uint8_t   triggerPulseWidth;
    int  extTrgMode;
    int  swTrgMode;
    int  selfTrgMode;
    int  acqMode;
    int  debugLevel;
    int  runSyncMode;
    int  outputSignalMode;
    int  eventCounterWarning;
    int  memoryAlmostFull;
    int  readoutMode;
    int  analogMode;
    int  testPattern;
    int  pedestal[MAX_CHANNELS];
    int  channelEnable[MAX_CHANNELS];
    int  channelSelfTrgLogic[MAX_CHANNELS/2];
    int  channelSelfTrgPulseType[MAX_CHANNELS/2];

    uint32_t  channelEnableMask;
    uint32_t  channelSelfTrgMask;

};
}

inline std::ostream& operator<<(std::ostream& os, const artdaqcaen::CAENConfiguration& e) {
	os << "CAEN Configuration" << std::endl;
	os << "  Link                  " << e.link << std::endl;
	os << "  nBoards               " << e.nBoards << std::endl;
	os << "  EnableReadout         " << e.enableReadout << std::endl;
	os << "  RecordLength          " << e.recordLength << std::endl;
	os << "  AllowTriggerOverlap   " << e.allowTriggerOverlap << std::endl;
	os << "  UsePedestals          " << e.usePedestals << std::endl;
	os << "  DacValue              " << e.dacValue << std::endl;
	os << "  DynamicRange          " << e.dynamicRange << std::endl;
	os << "  nChannels             " << e.nChannels << std::endl;
	os << "  PostPercent           " << e.postPercent << "%" << std::endl;
	os << "  IrqWaitTime           " << e.irqWaitTime << std::endl;
	os << "  IOLevel (NIM or TTL)  " << e.ioLevel << " "
	   << artdaqcaen::CAENDecoder::IOLevel((CAEN_DGTZ_IOLevel_t)e.ioLevel) << std::endl;
	os << "  TriggerPolarity       " << e.triggerPolarity << " "
	   << artdaqcaen::CAENDecoder::TriggerPolarity((CAEN_DGTZ_TriggerPolarity_t)e.triggerPolarity) << std::endl;
	os << "  ExtTrgMode            " << e.extTrgMode << " "
	   << artdaqcaen::CAENDecoder::TriggerMode((CAEN_DGTZ_TriggerMode_t)e.extTrgMode) << std::endl;
	os << "  SWTrgMode             " << e.swTrgMode << " "
	   << artdaqcaen::CAENDecoder::TriggerMode((CAEN_DGTZ_TriggerMode_t)e.swTrgMode) << std::endl;
	for(int j = 0; j < artdaqcaen::CAENConfiguration::MAX_CHANNELS; j++)
		os << "    Channel " << j << " Threshold " << e.triggerThresholds[j] << std::endl;
	os << "  AcqMode               " << e.acqMode << " "
	   << artdaqcaen::CAENDecoder::AcquisitionMode((CAEN_DGTZ_AcqMode_t)e.acqMode) << std::endl;
	os << "  DebugLevel            " << e.debugLevel << std::endl;
	os << "  EventCounterWarning   " << e.eventCounterWarning << std::endl;
	os << "  MemoryAlmostFull      " << e.memoryAlmostFull << std::endl;
	os << "  ReadoutMode           " << e.readoutMode << " "
	   << artdaqcaen::CAENDecoder::EnaDisMode((CAEN_DGTZ_EnaDis_t)e.readoutMode) << std::endl;
	os << "  AnalogMode            " << e.analogMode << std::endl;
	os << "  TestPattern           " << e.testPattern << std::endl;
	os << "  BoardId               " << e.boardId << "  EnableReadout " << e.enableReadout << std::endl;
	if(e.enableReadout)
	{
		os << "    ChannelEnableMask   0x" << std::hex << e.channelEnableMask << std::dec << std::endl;
		for(int j = 0; j < artdaqcaen::CAENConfiguration::MAX_CHANNELS; j++)
		{
			if(e.channelEnable[j])
			{
				os << "    Channel " << j << " Pedestal " << e.pedestal[j] << std::endl;
			}
		}
	}
	return os;
}
inline TraceStreamer& operator<<(TraceStreamer& ts, const artdaqcaen::CAENConfiguration& e)
{
	ts << "CAEN Configuration" << std::endl;
	ts << "  Link                  " << e.link << std::endl;
	ts << "  nBoards               " << e.nBoards << std::endl;
	ts << "  EnableReadout         " << e.enableReadout << std::endl;
	ts << "  RecordLength          " << e.recordLength << std::endl;
	ts << "  AllowTriggerOverlap   " << e.allowTriggerOverlap << std::endl;
	ts << "  UsePedestals          " << e.usePedestals << std::endl;
	ts << "  DacValue              " << e.dacValue << std::endl;
	ts << "  DynamicRange          " << e.dynamicRange << std::endl;
	ts << "  nChannels             " << e.nChannels << std::endl;
	ts << "  PostPercent           " << e.postPercent << "%" << std::endl;
	ts << "  IrqWaitTime           " << e.irqWaitTime << std::endl;
	ts << "  IOLevel (NIM or TTL)  " << e.ioLevel << " "
	   << artdaqcaen::CAENDecoder::IOLevel((CAEN_DGTZ_IOLevel_t)e.ioLevel) << std::endl;
	ts << "  TriggerPolarity       " << e.triggerPolarity << " "
	   << artdaqcaen::CAENDecoder::TriggerPolarity((CAEN_DGTZ_TriggerPolarity_t)e.triggerPolarity) << std::endl;
	ts << "  ExtTrgMode            " << e.extTrgMode << " "
	   << artdaqcaen::CAENDecoder::TriggerMode((CAEN_DGTZ_TriggerMode_t)e.extTrgMode) << std::endl;
	ts << "  SWTrgMode             " << e.swTrgMode << " "
	   << artdaqcaen::CAENDecoder::TriggerMode((CAEN_DGTZ_TriggerMode_t)e.swTrgMode) << std::endl;
	for(int j = 0; j < artdaqcaen::CAENConfiguration::MAX_CHANNELS; j++)
		ts << "    Channel " << j << " Threshold " << e.triggerThresholds[j] << std::endl;
	ts << "  AcqMode               " << e.acqMode << " "
	   << artdaqcaen::CAENDecoder::AcquisitionMode((CAEN_DGTZ_AcqMode_t)e.acqMode) << std::endl;
	ts << "  DebugLevel            " << e.debugLevel << std::endl;
	ts << "  EventCounterWarning   " << e.eventCounterWarning << std::endl;
	ts << "  MemoryAlmostFull      " << e.memoryAlmostFull << std::endl;
	ts << "  ReadoutMode           " << e.readoutMode << " "
	   << artdaqcaen::CAENDecoder::EnaDisMode((CAEN_DGTZ_EnaDis_t)e.readoutMode) << std::endl;
	ts << "  AnalogMode            " << e.analogMode << std::endl;
	ts << "  TestPattern           " << e.testPattern << std::endl;
	ts << "  BoardId               " << e.boardId << "  EnableReadout " << e.enableReadout << std::endl;
	if(e.enableReadout)
	{
		ts << "    ChannelEnableMask   0x" << std::hex << e.channelEnableMask << std::dec << std::endl;
		for(int j = 0; j < artdaqcaen::CAENConfiguration::MAX_CHANNELS; j++)
		{
			if(e.channelEnable[j])
			{
				ts << "    Channel " << j << " Pedestal " << e.pedestal[j] << std::endl;
			}
		}
	}
	return ts;
}

#endif

