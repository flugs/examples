project(flugs_hello_router_example)
set(COMPONENT HelloRouter)

set(SOURCES
    main.cpp
)

find_package(Qt5Core REQUIRED)
find_package(Qt5Qml REQUIRED)
find_package(Qt5Network REQUIRED)

find_package(FlugsFoundation REQUIRED)
find_package(FlugsHttpServer REQUIRED)
find_package(FlugsRouter     REQUIRED)

set(PUBLIC_LINK_LIBRARIES Flugs::HttpServer Flugs::Router Qt5::Core Qt5::Network Qt5::Qml)
add_executable(${COMPONENT} ${SOURCES})
target_link_libraries(${COMPONENT} PUBLIC ${PUBLIC_LINK_LIBRARIES})
