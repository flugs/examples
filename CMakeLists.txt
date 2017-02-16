cmake_minimum_required(VERSION 3.7.0)
project(flugs_examples)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC TRUE)

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../framework/install")
    set(CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../framework/install/cmake")
endif()

macro(OPTIONAL_ADD_SUBDIRECTORY dir)
  get_filename_component(fullPath ${dir} ABSOLUTE)

  if(EXISTS ${fullPath}/CMakeLists.txt)
    add_subdirectory(${dir})
  endif()
endmacro()

optional_add_subdirectory(helloworld)
optional_add_subdirectory(hellorouter)
optional_add_subdirectory(hellocontroller)
#optional_add_subdirectory(qml)
