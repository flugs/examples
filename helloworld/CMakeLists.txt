cmake_minimum_required(VERSION 3.7.0)
project(flugs_example_hello_world)

set(SOURCES
    main.cpp
)

find_package(Qt5Core REQUIRED)
find_package(Qt5Qml REQUIRED)
find_package(Qt5Network REQUIRED)

find_package(FlugsFoundation REQUIRED)
find_package(FlugsHttpServer REQUIRED)

set(PUBLIC_LINK_LIBRARIES Flugs::HttpServer Qt5::Core Qt5::Network Qt5::Qml)
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PUBLIC ${PUBLIC_LINK_LIBRARIES})

