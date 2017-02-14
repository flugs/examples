project(flugs_hello_controller_example)

set(COMPONENT HelloController)

set(SOURCES
    main.cpp
)

set(PUBLIC_LINK_LIBRARIES Flugs::HttpServer Flugs::Controller Qt5::Core Qt5::Network)
add_executable(${COMPONENT} ${SOURCES})
target_link_libraries(${COMPONENT} PUBLIC ${PUBLIC_LINK_LIBRARIES})

