
find_path(TRISYCL_CC_PATH trisyclcc)  # Ensure trisyclcc exe script is in PATH
find_path(COMPUTECPP_CC_PATH computecppcc)  # Ensure syclcc exe script is in PATH

if   (COMPUTECPP_CC_PATH)
  message ("-- Found ComputeCpp driver: ${COMPUTECPP_CC_PATH}/computecppcc")
else  (COMPUTECPP_CC_PATH)
  message ("-- Could NOT find ComputeCpp driver script (missing: COMPUTECPP_CC_PATH)")
endif (COMPUTECPP_CC_PATH)

if   (TRISYCL_CC_PATH)
  message ("-- Found triSYCL driver: ${TRISYCL_CC_PATH}/trisyclcc")
else  (TRISYCL_CC_PATH)
  message ("-- Could NOT find triSYCL driver script (missing: TRISYCL_CC_PATH)")
endif (TRISYCL_CC_PATH)

get_filename_component(barename "$ENV{CXX}" NAME)

if    (TRISYCL_CC_PATH AND "${barename}" STREQUAL "trisyclcc")
  set (SYCL_FOUND TRUE)
  set (TRISYCL_FOUND TRUE)
  message ("-- Found triSYCL driver and CXX is set to trisyclcc, compiling with triSYCL")
elseif (COMPUTECPP_CC_PATH AND "${barename}" STREQUAL "computecppcc")
  set (SYCL_FOUND TRUE)
  set (COMPUTECPP_FOUND TRUE)
  message ("-- Found ComputeCpp driver and CXX is set to computecppcc, compiling with ComputeCpp")
endif ()
