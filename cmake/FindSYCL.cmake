
find_path(SYCL_CC_PATH syclcc)  # Ensure syclcc exe script is in PATH

get_filename_component(barename "$ENV{CXX}" NAME)

if    (SYCL_CC_PATH AND ${barename} STREQUAL "syclcc")
  set (SYCL_FOUND TRUE)
endif ()

if    (SYCL_FOUND)
  message ("-- Found SYCL driver: ${SYCL_CC_PATH}/syclcc")
else  (SYCL_FOUND)
  message ("-- Could NOT find SYCL driver script (missing: SYCL_CC_PATH)")
endif (SYCL_FOUND)
