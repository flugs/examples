project(flugs_hello_router_example)
set(COMPONENT HelloRouter)

set(SOURCES
    main.cpp
)

set(PUBLIC_LINK_LIBRARIES Flugs::HttpServer Flugs::Router Qt5::Core Qt5::Network)
add_executable(${COMPONENT} ${SOURCES})
target_link_libraries(${COMPONENT} PUBLIC ${PUBLIC_LINK_LIBRARIES})
