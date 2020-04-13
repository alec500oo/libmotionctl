# Cmake build file for libmotionctl
# Libmotionctl can be built as a static, dynamic, or test executable. The test
# suite can be used to verify the performance of the library.
#
# @author Alec Matthews <alec500oo@gmail.com>

cmake_minimum_required(VERSION 3.10)

project(libmotionctl)

# add libmotionctl sources
add_subdirectory(src)

# handle testing option
option(BUILD_TESTS "Build tests for libmotionctl")

if(BUILD_TESTS)
  # set options for cmocka and hide them from the GUI
  set(BUILD_SHARED_LIBS OFF CACHE INTERNAL "Disable shared libs")
  set(WITH_CMOCKERY_SUPPORT OFF CACHE INTERNAL "")
  set(WITH_EXAMPLES OFF CACHE INTERNAL "Don't build cmocka examples")
  set(UNIT_TESTING OFF CACHE INTERNAL "")
  set(PICKY_DEVELOPER OFF CACHE INTERNAL "")

  # add cmocka sub-dir
  add_subdirectory(lib/cmocka)

  # add tests sub-dir
  add_subdirectory(tests)
endif(BUILD_TESTS)
