#[================================================================[.rst:
FindCAENCOMM
----------
  find CAENCOMM

#]================================================================]
if (CAENCOMM_FIND_REQUIRED)
  set(_cet_CAENCOMM_FIND_REQUIRED ${CAENCOMM_FIND_REQUIRED})
  unset(CAENCOMM_FIND_REQUIRED)
else()
  unset(_cet_CAENCOMM_FIND_REQUIRED)
endif()
find_package(CAENCOMM CONFIG QUIET)
if (_cet_CAENCOMM_FIND_REQUIRED)
  set(CAENCOMM_FIND_REQUIRED ${_cet_CAENCOMM_FIND_REQUIRED})
  unset(_cet_CAENCOMM_FIND_REQUIRED)
endif()

find_package(caenvmelib REQUIRED QUIET)

if (CAENCOMM_FOUND)
  set(_cet_CAENCOMM_config_mode CONFIG_MODE)
else()
  unset(_cet_CAENCOMM_config_mode)
  find_file(_CAENComm_h NAMES CAENComm.h HINTS PATH_SUFFIXES include)
  if (_CAENComm_h)
    #message("Found CAENComm.h: ${_CAENComm_h}")
    get_filename_component(_cet_CAENCOMM_include_dir "${_CAENComm_h}" PATH)
    if (_cet_CAENCOMM_include_dir STREQUAL "/")
      unset(_cet_CAENCOMM_include_dir)
    endif()
  endif()

  if (EXISTS "${_cet_CAENCOMM_include_dir}")
    set(CAENCOMM_FOUND TRUE)
    get_filename_component(_cet_CAENCOMM_dir "${_cet_CAENCOMM_include_dir}" PATH)
    if (_cet_CAENCOMM_dir STREQUAL "/")
      unset(_cet_CAENCOMM_dir)
    endif()
    set(CAENCOMM_INCLUDE_DIRS "${_cet_CAENCOMM_include_dir}")
    set(CAENCOMM_LIBRARY_DIR "${_cet_CAENCOMM_dir}/lib")
    find_library( CAENCOMM_LIBRARY NAMES CAENComm PATHS ${CAENCOMM_LIBRARY_DIR} REQUIRED)
    get_filename_component(_cet_CAENCOMM_lib_dir "${CAENCOMM_LIBRARY}" PATH)
  endif()
endif()
if (CAENCOMM_FOUND)
  if (NOT TARGET CAEN::Comm)
    add_library(CAEN::Comm SHARED IMPORTED)
    set_target_properties(CAEN::Comm PROPERTIES
      INTERFACE_INCLUDE_DIRECTORIES "${CAENCOMM_INCLUDE_DIRS}"
      IMPORTED_LOCATION "${CAENCOMM_LIBRARY}"
      INTERFACE_LINK_LIBRARIES "CAEN::VME"
      )
      target_link_directories(CAEN::Comm INTERFACE ${_cet_CAENCOMM_lib_dir})
    set(CAENCOMM_LIBRARY "CAEN::Comm")
  endif()
  if (CETMODULES_CURRENT_PROJECT_NAME AND
      ${CETMODULES_CURRENT_PROJECT_NAME}_OLD_STYLE_CONFIG_VARS)
    include_directories("${CAENCOMM_INCLUDE_DIRS}")
    set(CAENComm "${CAENCOMM_LIBRARY}")
  endif()
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(CAENCOMM ${_cet_CAENCOMM_config_mode}
  REQUIRED_VARS CAENCOMM_FOUND
  CAENCOMM_INCLUDE_DIRS
  CAENCOMM_LIBRARY)

unset(_cet_CAENCOMM_FIND_REQUIRED)
unset(_cet_CAENCOMM_config_mode)
unset(_cet_CAENCOMM_dir)
unset(_cet_CAENCOMM_lib_dir)
unset(_cet_CAENCOMM_include_dir)
unset(_CAENComm_h CACHE)

