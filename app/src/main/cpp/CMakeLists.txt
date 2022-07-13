
cmake_minimum_required(VERSION 3.10.2)


project("source")

include_directories(include)
#include_directories(include/media/)

#file(GLOB_RECURSE MIRACASTSRC
#        "media/libstagefright/*.h"
#        "media/libstagefright/*.cpp"
#        )

#file(GLOB source_file libstagefright/*.h libstagefright/*.cpp)
file(GLOB_RECURSE source_file libstagefright/*.h libstagefright/*.cpp)

add_library(
             native-lib
             SHARED

            ${source_file})


find_library(
              log-lib
              log )

target_link_libraries(
                       native-lib
                       ${log-lib} )