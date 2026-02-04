#[================================================================[.rst:
FindCAENVMELIB
----------
  find CAENVMELIB

#]================================================================]
if (CAENVMELIB_FIND_REQUIRED)
  set(_cet_CAENVMELIB_FIND_REQUIRED ${CAENVMELIB_FIND_REQUIRED})
  unset(CAENVMELIB_FIND_REQUIRED)
else()
  unset(_cet_CAENVMELIB_FIND_REQUIRED)
endif()
find_package(CAENVMELIB CONFIG QUIET)
if (_cet_CAENVMELIB_FIND_REQUIRED)
  set(CAENVMELIB_FIND_REQUIRED ${_cet_CAENVMELIB_FIND_REQUIRED})
  unset(_cet_CAENVMELIB_FIND_REQUIRED)
endif()
if (CAENVMELIB_FOUND)
  set(_cet_CAENVMELIB_config_mode CONFIG_MODE)
else()
  unset(_cet_CAENVMELIB_config_mode)
  find_file(_CAENVMElib_h NAMES CAENVMElib.h HINTS PATH_SUFFIXES include)
  if (_CAENVMElib_h)
    #message("Found CAENVMELIB.h: ${_CAENVMElib_h}")
    get_filename_component(_cet_CAENVMELIB_include_dir "${_CAENVMElib_h}" PATH)
    if (_cet_CAENVMELIB_include_dir STREQUAL "/")
      unset(_cet_CAENVMELIB_include_dir)
    endif()
  endif()

  if (EXISTS "${_cet_CAENVMELIB_include_dir}")
    set(CAENVMELIB_FOUND TRUE)
    get_filename_component(_cet_CAENVMELIB_dir "${_cet_CAENVMELIB_include_dir}" PATH)
    if (_cet_CAENVMELIB_dir STREQUAL "/")
      unset(_cet_CAENVMELIB_dir)
    endif()
    set(CAENVMELIB_INCLUDE_DIRS "${_cet_CAENVMELIB_include_dir}")
    set(CAENVMELIB_LIBRARY_DIR "${_cet_CAENVMELIB_dir}/lib")
    find_library( CAENVMELIB_LIBRARY NAMES CAENVME PATHS ${CAENVMELIB_LIBRARY_DIR} REQUIRED)
    get_filename_component(_cet_CAENVMELIB_lib_dir "${CAENVMELIB_LIBRARY}" PATH)
  endif()
endif()
if (CAENVMELIB_FOUND)
  if (NOT TARGET CAEN::VME)
    add_library(CAEN::VME SHARED IMPORTED)
    set_target_properties(CAEN::VME PROPERTIES
      INTERFACE_INCLUDE_DIRECTORIES "${CAENVMELIB_INCLUDE_DIRS}"
      IMPORTED_LOCATION "${CAENVMELIB_LIBRARY}"
      )
      target_link_directories(CAEN::VME INTERFACE ${_cet_CAENVMELIB_lib_dir})
    set(CAENVMELIB_LIBRARY "CAEN::VME")
  endif()
  if (CETMODULES_CURRENT_PROJECT_NAME AND
      ${CETMODULES_CURRENT_PROJECT_NAME}_OLD_STYLE_CONFIG_VARS)
    include_directories("${CAENVMELIB_INCLUDE_DIRS}")
    set(CAENVMELIB "${CAENVMELIB_LIBRARY}")
  endif()
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(CAENVMELIB ${_cet_CAENVMELIB_config_mode}
  REQUIRED_VARS CAENVMELIB_FOUND
  CAENVMELIB_INCLUDE_DIRS
  CAENVMELIB_LIBRARY)

unset(_cet_CAENVMELIB_FIND_REQUIRED)
unset(_cet_CAENVMELIB_config_mode)
unset(_cet_CAENVMELIB_dir)
unset(_cet_CAENVMELIB_lib_dir)
unset(_cet_CAENVMELIB_include_dir)
unset(_CAENVMElib_h CACHE)

