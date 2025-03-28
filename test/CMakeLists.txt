   # test/CMakeLists.txt
   cmake_minimum_required(VERSION 3.21)
   add_subdirectory(googletest-main)
   set(gtest_SOURCE_DIR, googletest-main)
   include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

   set(SOURCE_TEST_FILES runAllTests.cpp)
   add_executable(runAllTests ${SOURCE_TEST_FILES})
   target_link_libraries(runAllTests gtest gtest_main core)