
find_path(TRISYCL_CC_PATH trisyclcc)  # Ensure trisyclcc exe script is in PATH

get_filename_component(barename "$ENV{CXX}" NAME)

if    (TRISYCL_CC_PATH AND "${barename}" STREQUAL "trisyclcc")
  set (TRISYCL_FOUND TRUE)
endif ()

if    (TRISYCL_FOUND)
  message ("-- Found triSYCL driver: ${TRISYCL_CC_PATH}/trisyclcc")
else  (TRISYCL_FOUND)
  message ("-- Could NOT find triSYCL driver script (missing: TRISYCL_CC_PATH)")
endif (TRISYCL_FOUND)
