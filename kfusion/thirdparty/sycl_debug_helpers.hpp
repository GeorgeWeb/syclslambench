/*

 Simple print functions for SYCL and SLAMBench types to help make debugging
 easier and quicker.

 andrew point gozillon at yahoo point com

 This code is licensed under the MIT License.

*/
#ifdef TRISYCL
#include <CL/sycl.hpp>
#else
#include <SYCL/sycl.hpp>
#endif

#include <type_traits>

template <typename T>
void printVal(T v) {
  if constexpr (std::is_integral<T>::value) {
    printf("%d  \n", v);
  } else {
    printf("%f  \n", v);
  }
}

template <>
void printVal<Matrix4>(Matrix4 v) {
  printf("begin matrix \n");
  for (int i = 0; i < 4; ++i)
    for(int j = 0; j < 4; ++j)
      printf(" %f ", v.data[i][j]);

  printf("\n");
}

template <>
void printVal<TrackData>(TrackData v) {
  printf("Track Data:: ");
  printf("Result: %d ", v.result);
  printf("Error: %f ", v.error);

  for (int i = 0; i < 6; ++i) {
    printf("J: %f ", v.J[i]);
  }

  printf("\n");
}

template <typename T, int Dimensions>
void printVal(cl::sycl::vec<T, Dimensions> v) {
  printf("vec: ");
  for (int i = 0; i < Dimensions; ++i)
  if constexpr (std::is_integral<T>::value) {
    printf("%d ", v[i]);
  } else {
    printf("%f ", v[i]);
  }
  printf(" \n");
}

template <typename T>
void printArraySlice(T array, int upto = 5) {
  std::cout << "begin array: \n";
  for (int i = 0; i < upto; ++i) {
    std::cout << " " << i << " ";
    printVal(array[i]);
  }
  std::cout << "\n end array \n";
  std::cout << "\n";
}

// print buffer utility
template <typename T>
void printBufferSlice(T buffer, int upto = 5) {
  if (upto > buffer->get_count())
    upto = buffer->get_count();

  // std::cout << "getting print buffer \n";
  auto acc = buffer-> template get_access<cl::sycl::access::mode::read>();
  std::cout << "Begin buffer: \n";
  for (int i = 0; i < upto; ++i) {
    std::cout << " " << i << " ";
    printVal(acc[i]);
  }
  std::cout << "\n End buffer \n";
  std::cout << "\n";
}

template <typename T>
void print2dBufferSlice(T buffer, int upto = 5, int row = 0) {
  if (upto > buffer[row]->get_count())
    upto = buffer[row]->get_count();

  auto acc = buffer[row]-> template get_access<cl::sycl::access::mode::read>();
  std::cout << "Begin 2d buffer: \n";
  for (int i = 0; i < upto; ++i) {
    std::cout << " " << i << " " << row << " ";
    printVal(acc[i]);
 }

  std::cout << "\n End 2d buffer \n\n";
}

template <typename T>
void print2dBufferRow(T buffer, int row = 0) {
  auto acc = buffer[row]-> template get_access<cl::sycl::access::mode::read>();
  std::cout << "Begin 2d buffer: \n";
  for (int i = 0; i < buffer[row]->get_count(); ++i) {
    std::cout << " " << i << " " << row << " ";
    printVal(acc[i]);
  }

  std::cout << "\n End 2d buffer \n";
  std::cout << "\n";
}

template <typename T>
void ZeroFill2dBufferRow(T buffer, int row = 0) {
  auto acc = buffer[row]-> template get_access<cl::sycl::access::mode::write>();
  for (int i = 0; i < buffer[row]->get_count(); ++i) {
    acc[i] = {0};
  }
}
