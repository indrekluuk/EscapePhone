cmake_minimum_required(VERSION 3.2)
project(EscapePhone)



# PlatformIO build targets
# Must init platformio. See: PlatformIO_CLion_init.txt
add_subdirectory(src)






# init Google Test target
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# fake arduino headers
include_directories(test/fake)
# project headers
include_directories(src/EscapePhone)
# gtest headers
include_directories(${gtest_SOURCE_DIR}/include)


add_executable(runTests
        src/EscapePhone/Timer.cpp

        test/fake/Arduino.cpp

        test/src/TimerTest.cpp
        )

# link
add_subdirectory(test/lib/gtest-1.7.0)
target_link_libraries(runTests gtest_main)





