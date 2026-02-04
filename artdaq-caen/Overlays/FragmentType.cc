#include "artdaq-caen/Overlays/FragmentType.hh"

#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

artdaqcaen::FragmentType artdaqcaen::toFragmentType(std::string t_string)
{
	std::transform(t_string.begin(), t_string.end(), t_string.begin(), toupper);
	auto it = std::find(names.begin(), names.end(), t_string);
	return (it == names.end())
	           ? FragmentType::INVALID
	           : static_cast<FragmentType>(artdaq::Fragment::FirstUserFragmentType +
	                                       (it - names.begin()));
}

std::string artdaqcaen::fragmentTypeToString(artdaqcaen::detail::FragmentType val)
{
	if(val < FragmentType::INVALID)
	{
		return names[val - FragmentType::MISSED];
	}
	else
	{
		return "INVALID/UNKNOWN";
	}
}

std::map<artdaq::Fragment::type_t, std::string> artdaqcaen::makeFragmentTypeMap()
{
	auto output = artdaq::Fragment::MakeSystemTypeMap();
	for(auto name : names)
	{
		output[toFragmentType(name)] = name;
	}
	return output;
}
