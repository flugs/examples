cmake_minimum_required(VERSION 3.7.0)

macro(OPTIONAL_ADD_SUBDIRECTORY dir)
  get_filename_component(fullPath ${dir} ABSOLUTE)

  if(EXISTS ${fullPath}/CMakeLists.txt)
    add_subdirectory(${dir})
  endif()
endmacro()

optional_add_subdirectory(helloworld)
optional_add_subdirectory(hellorouter)
optional_add_subdirectory(hellocontroller)
optional_add_subdirectory(qml)
