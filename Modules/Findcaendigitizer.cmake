#[================================================================[.rst:
FindCAENDIGITIZER
----------
  find CAENDIGITIZER

#]================================================================]
if (CAENDIGITIZER_FIND_REQUIRED)
  set(_cet_CAENDIGITIZER_FIND_REQUIRED ${CAENDIGITIZER_FIND_REQUIRED})
  unset(CAENDIGITIZER_FIND_REQUIRED)
else()
  unset(_cet_CAENDIGITIZER_FIND_REQUIRED)
endif()
find_package(CAENDIGITIZER CONFIG QUIET)
if (_cet_CAENDIGITIZER_FIND_REQUIRED)
  set(CAENDIGITIZER_FIND_REQUIRED ${_cet_CAENDIGITIZER_FIND_REQUIRED})
  unset(_cet_CAENDIGITIZER_FIND_REQUIRED)
endif()

find_package(caencomm REQUIRED QUIET)

if (CAENDIGITIZER_FOUND)
  set(_cet_CAENDIGITIZER_config_mode CONFIG_MODE)
else()
  unset(_cet_CAENDIGITIZER_config_mode)
  find_file(_CAENDigitizer_h NAMES CAENDigitizer.h HINTS PATH_SUFFIXES include)
  if (_CAENDigitizer_h)
    #message("Found CAENDIGITIZER.h: ${_CAENDigitizer_h}")
    get_filename_component(_cet_CAENDIGITIZER_include_dir "${_CAENDigitizer_h}" PATH)
    if (_cet_CAENDIGITIZER_include_dir STREQUAL "/")
      unset(_cet_CAENDIGITIZER_include_dir)
    endif()
  endif()

  if (EXISTS "${_cet_CAENDIGITIZER_include_dir}")
    set(CAENDIGITIZER_FOUND TRUE)
    get_filename_component(_cet_CAENDIGITIZER_dir "${_cet_CAENDIGITIZER_include_dir}" PATH)
    if (_cet_CAENDIGITIZER_dir STREQUAL "/")
      unset(_cet_CAENDIGITIZER_dir)
    endif()
    set(CAENDIGITIZER_INCLUDE_DIRS "${_cet_CAENDIGITIZER_include_dir}")
    set(CAENDIGITIZER_LIBRARY_DIR "${_cet_CAENDIGITIZER_dir}/lib")
    find_library( CAENDIGITIZER_LIBRARY NAMES CAENDigitizer PATHS ${CAENDIGITIZER_LIBRARY_DIR} REQUIRED)
    get_filename_component(_cet_CAENDIGITIZER_lib_dir "${CAENDIGITIZER_LIBRARY}" PATH)
  endif()
endif()
if (CAENDIGITIZER_FOUND)
  if (NOT TARGET CAEN::Digitizer)
    add_library(CAEN::Digitizer SHARED IMPORTED)
    set_target_properties(CAEN::Digitizer PROPERTIES
      INTERFACE_INCLUDE_DIRECTORIES "${CAENDIGITIZER_INCLUDE_DIRS}"
      IMPORTED_LOCATION "${CAENDIGITIZER_LIBRARY}"
      INTERFACE_LINK_LIBRARIES "CAEN::Comm"
      )
      target_link_directories(CAEN::Digitizer INTERFACE ${_cet_CAENDIGITIZER_lib_dir})
    set(CAENDIGITIZER_LIBRARY "CAEN::Digitizer")
  endif()
  if (CETMODULES_CURRENT_PROJECT_NAME AND
      ${CETMODULES_CURRENT_PROJECT_NAME}_OLD_STYLE_CONFIG_VARS)
    include_directories("${CAENDIGITIZER_INCLUDE_DIRS}")
    set(CAENDIGITIZER "${CAENDIGITIZER_LIBRARY}")
  endif()
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(CAENDIGITIZER ${_cet_CAENDIGITIZER_config_mode}
  REQUIRED_VARS CAENDIGITIZER_FOUND
  CAENDIGITIZER_INCLUDE_DIRS
  CAENDIGITIZER_LIBRARY)

unset(_cet_CAENDIGITIZER_FIND_REQUIRED)
unset(_cet_CAENDIGITIZER_config_mode)
unset(_cet_CAENDIGITIZER_dir)
unset(_cet_CAENDIGITIZER_lib_dir)
unset(_cet_CAENDIGITIZER_include_dir)
unset(_CAENDigitizer_h CACHE)

