//
//  CAENException.cc   (W.Badgett)
//

#include "CAENException.hh"
#include <iostream>
#include <sstream>

artdaqcaen::CAENException::CAENException(CAEN_DGTZ_ErrorCode error_, std::string label_, int boardId_)
    : error(error_), label(label_), boardId(boardId_)
{
}

std::string artdaqcaen::CAENException::what()
{
	std::stringstream hello;
	hello << *this;
	return (hello.str());
}

void artdaqcaen::CAENException::print(std::ostream& os) { os << *this; }

std::ostream& operator<<(std::ostream& s, const artdaqcaen::CAENException& e)
{
	s << "ERROR: " << e.label << " " << artdaqcaen::CAENDecoder::CAENError(e.error);
	if(e.boardId >= 0)
	{
		s << " BoardId " << e.boardId;
	}
	s << std::endl;
	return (s);
}
