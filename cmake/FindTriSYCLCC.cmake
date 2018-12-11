
find_path(TRISYCL_CC_PATH trisyclcc)  # Ensure trisyclcc exe script is in PATH

if    (TRISYCL_CC_PATH AND "$ENV{CXX}" MATCHES "trisyclcc")
  set (TRISYCL_FOUND TRUE)
endif ()

if    (TRISYCL_FOUND)
  message ("-- Found triSYCL driver script: ${TRISYCL_CC_PATH}/trisyclcc")
else  (TRISYCL_FOUND)
  message ("-- Could NOT find SYCL driver script (missing: TRISYCL_CC_PATH)")
endif (TRISYCL_FOUND)
