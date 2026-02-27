# ======================================================================
#  otsdaq-demo main build file
#
#  cd .../path/to/build/directory
#  source .../path/to/otsdaq-demo/ups/setup_for_development
#  buildtool
# ======================================================================


# use cmake 3.17 or later
cmake_minimum_required (VERSION 3.19 FATAL_ERROR)

find_package(cetmodules 3.16.00 REQUIRED)

project(artdaq-caen VERSION 1.01.00)

include(CetCMakeEnv)
include(SetCompilerFlags)
include(InstallHeaders)
include(InstallSource)
include(InstallFhicl)

cet_cmake_env()
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

# Find our own CMake modules, and tell everyone else where to find them.
cet_cmake_module_directories(Modules BINARY)

cet_set_compiler_flags(DIAGS VIGILANT
 WERROR
 NO_UNDEFINED
 EXTRA_FLAGS -pedantic -D_LIBCPP_ENABLE_CXX17_REMOVED_FEATURES=1
 )

 # artdaq
 find_package( artdaq 4.00.00 REQUIRED QUIET)
 find_package( artdaq-core 3.05.00 REQUIRED QUIET)
 find_package( artdaq-utilities 3.05.00 REQUIRED QUIET)

#CAEN libraries
find_package( caenvmelib v2_50 )
find_package( caencomm v1_2a )
find_package( caendigitizer v2_7_2 )

include(BuildPlugins)

# Code
add_subdirectory(artdaq-caen)

# Useful scripts
add_subdirectory(tools)

# Test Programs
add_subdirectory(test)

# Documentation directory
add_subdirectory(doc)

cet_cmake_config()
