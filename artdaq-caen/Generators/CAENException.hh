//
//  CAENException.h (W.Badgett)
//
#ifndef _CAEN_EXCEPTION_H
#define _CAEN_EXCEPTION_H

#include "CAENDecoder.hh"
#include "CAENDigitizerType.h"
#include "messagefacility/MessageLogger/MessageLogger.h"

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

#endif
