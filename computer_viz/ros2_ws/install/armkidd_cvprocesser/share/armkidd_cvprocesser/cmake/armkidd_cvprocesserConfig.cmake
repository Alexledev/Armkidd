# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_armkidd_cvprocesser_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED armkidd_cvprocesser_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(armkidd_cvprocesser_FOUND FALSE)
  elseif(NOT armkidd_cvprocesser_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(armkidd_cvprocesser_FOUND FALSE)
  endif()
  return()
endif()
set(_armkidd_cvprocesser_CONFIG_INCLUDED TRUE)

# output package information
if(NOT armkidd_cvprocesser_FIND_QUIETLY)
  message(STATUS "Found armkidd_cvprocesser: 0.0.0 (${armkidd_cvprocesser_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'armkidd_cvprocesser' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT armkidd_cvprocesser_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(armkidd_cvprocesser_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${armkidd_cvprocesser_DIR}/${_extra}")
endforeach()
