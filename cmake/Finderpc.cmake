# find_package(PkgConfig REQUIRED)
# pkg_check_modules(PC_ERPC QUIET erpc)

find_library(ERPC_LIBRARY
  NAMES erpc
  PATHS ${CMAKE_BINARY_DIR}/erpc/lib
)

find_path(ERPC_INCLUDE_DIR
  NAMES erpc_config.h
  PATHS ${CMAKE_BINARY_DIR}/erpc/include
  PATH_SUFFIXES erpc
)

if(NOT ERPC_LIBRARY)
  message(FATAL_ERROR "erpc library not found")
endif()

if(NOT ERPC_INCLUDE_DIR)
  message(FATAL_ERROR "erpc include directory not found")
endif()

# add_library(erpc INTERFACE)
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(erpc
  REQUIRED_VARS ERPC_LIBRARY ERPC_INCLUDE_DIR
  VERSION_VAR ERPC_VERSION
)

mark_as_advanced(ERPC_LIBRARY ERPC_INCLUDE_DIR)