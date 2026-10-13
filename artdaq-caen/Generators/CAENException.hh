//
//  CAENException.h (W.Badgett)
//
#ifndef ARTDAQ_CAEN_ARTDAQ_CAEN_GENERATORS_CAENEXCEPTION_HH_
#define ARTDAQ_CAEN_ARTDAQ_CAEN_GENERATORS_CAENEXCEPTION_HH_

#include "CAENDecoder.hh"
#include "CAENDigitizerType.h"
#include "messagefacility/MessageLogger/MessageLogger.h"

#include <iostream>
#include <string>

namespace artdaqcaen
{
class CAENException : public std::exception
{
  public:
	CAEN_DGTZ_ErrorCode error;
	std::string         label;
	int                 boardId;

	CAENException(CAEN_DGTZ_ErrorCode error_, std::string label_, int boardId_);

	void print(std::ostream& os = std::cout);
	using std::exception::what;
	std::string what();  // override;
};
}  // namespace artdaqcaen

std::ostream& operator<<(std::ostream& s, const artdaqcaen::CAENException& e);

#endif  // ARTDAQ_CAEN_ARTDAQ_CAEN_GENERATORS_CAENEXCEPTION_HH_
