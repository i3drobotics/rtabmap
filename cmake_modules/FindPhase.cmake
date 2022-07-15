# - Find Phase (https://github.com/i3drobotics/phase)
#
#  Phase_ROOT_DIR environment variable can be set to find the library.
#
# It sets the following variables:
#  Phase_FOUND              - Set to false, or undefined, if Phase isn't found.
#  Phase_INCLUDE_DIRS       - The Phase include directory.
#  Phase_LIBRARIES          - The Phase library to link against.

#Phase library

cmake_minimum_required(VERSION 3.9)

if (WIN32)
    file (GLOB Phase_LIBRARY_FILES
        "${Phase_ROOT_DIR}/bin/*.dll"
    )
endif()

find_path(Phase_INCLUDE_DIR
    NAMES phase/phaseversion.h
    HINTS ${Phase_ROOT_DIR}/include
    NO_DEFAULT_PATH
    DOC "The Phase include directory"
)

if (NOT Phase_INCLUDE_DIR)
    message(WARNING "phase include directory not found")
endif()

find_library(Phase_LIB 
    NAMES phase
    PATHS ${Phase_ROOT_DIR}/lib
    NO_DEFAULT_PATH
    DOC "The Phase_ROOT_DIR library"
)

if (NOT Phase_LIB)
    message(WARNING "phase library directory not found")
endif()

file(GLOB Conan_LIBS
    "${Phase_ROOT_DIR}/lib/*.lib"
    "${Phase_ROOT_DIR}/lib/*.so*"
    "${Phase_ROOT_DIR}/lib/i3drsgm/*.so*"
)

set(WITH_I3DRSGM ON)

if (WITH_I3DRSGM)
    set (Phase_DEFINITIONS WITH_I3DRSGM)
endif()

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set LOGGING_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(Phase DEFAULT_MSG Phase_INCLUDE_DIR Phase_LIB)

if (Phase_FOUND)
    set(Phase_LIBRARIES
        ${Phase_LIB}
        ${Conan_LIBS}
    )
    set(Phase_INCLUDE_DIRS
        ${Phase_INCLUDE_DIR}
        ${Phase_INCLUDE_DIR}/opencv4
    )
    set(Phase_DEFINITIONS ${Phase_DEFINITIONS})
else(Phase_FOUND)
    message(FATAL_ERROR "Could not find Phase")
endif()

# Tell cmake GUIs to ignore the "local" variables.
mark_as_advanced(Phase_ROOT_DIR Phase_LIB Conan_LIBS Phase_INCLUDE_DIR) 
