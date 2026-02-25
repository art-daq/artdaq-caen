#include "artdaq-caen/Overlays/FragmentType.hh"
#include "artdaq-core/Plugins/FragmentNameHelper.hh"

#include "TRACE/tracemf.h"
#define TRACE_NAME "CaenFragmentNameHelper"

namespace artdaqcaen
{
/**
 * \brief CaenFragmentNameHelper extends ArtdaqFragmentNamingService.
 * This implementation uses artdaq-demo's SystemTypeMap and directly assigns names based
 * on it
 */
class CaenFragmentNameHelper : public artdaq::FragmentNameHelper
{
  public:
	/**
	 * \brief DefaultArtdaqFragmentNamingService Destructor
	 */
	~CaenFragmentNameHelper() override = default;

	/**
	 * \brief CaenFragmentNameHelper Constructor
	 */
	CaenFragmentNameHelper(std::string                                                   unidentified_instance_name,
	                       std::vector<std::pair<artdaq::Fragment::type_t, std::string>> extraTypes);

  private:
	CaenFragmentNameHelper(CaenFragmentNameHelper const&)            = delete;
	CaenFragmentNameHelper(CaenFragmentNameHelper&&)                 = delete;
	CaenFragmentNameHelper& operator=(CaenFragmentNameHelper const&) = delete;
	CaenFragmentNameHelper& operator=(CaenFragmentNameHelper&&)      = delete;
};

CaenFragmentNameHelper::CaenFragmentNameHelper(std::string unidentified_instance_name,
                                               std::vector<std::pair<artdaq::Fragment::type_t, std::string>> extraTypes)
    : FragmentNameHelper(unidentified_instance_name, extraTypes)
{
	TLOG(TLVL_DEBUG) << "CaenFragmentNameHelper CONSTRUCTOR START";
	SetBasicTypes(artdaqcaen::makeFragmentTypeMap());
	TLOG(TLVL_DEBUG) << "CaenFragmentNameHelper CONSTRUCTOR END";
}
}  // namespace artdaqcaen

DEFINE_ARTDAQ_FRAGMENT_NAME_HELPER(artdaqcaen::CaenFragmentNameHelper)
