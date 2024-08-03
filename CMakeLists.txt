cmake_minimum_required(VERSION 3.14)
project(LibHmahBezier LANGUAGES C)

unset(CMAKE_CXX_COMPILER)

set(SOURCES src/bezier_core.c)

option(HMAH_BEZIER_INCLUDE_BEZIER2 "Include Bezier2 class in lib" ON)
option(HMAH_BEZIER_INCLUDE_BEZIER3 "Include Bezier3 class in lib" ON)
option(HMAH_BEZIER_STATIC "Build static library" ON)
option(HMAH_BEZIER_SHARED "Build shared library" OFF)
option(HMAH_BEZIER_BUILD_TESTS "Build tests for lib testing" ON)

set(FORCE_INCLUDE_ALL ON)

if (${HMAH_BEZIER_INCLUDE_BEZIER2})
  set(SOURCES ${SOURCES} src/bezier2.c)
endif ()

if (${HMAH_BEZIER_INCLUDE_BEZIER3})
  set(SOURCES ${SOURCES} src/bezier3.c)
endif ()

if (${HMAH_BEZIER_STATIC})
  add_library(hmahbezier STATIC ${SOURCES})
elseif (${HMAH_BEZIER_SHARED})
  add_library(hmahbezier SHARED ${SOURCES})
else ()
  message(FATAL_ERROR "Choose HMAH_BEZIER_STATIC or HMAH_BEZIER_SHARED to build!")
endif ()

if (${HMAH_BEZIER_BUILD_TESTS})
  add_subdirectory(tests)
endif ()