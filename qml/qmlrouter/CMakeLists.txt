project(flugs_qml_router_example)
set(COMPONENT QmlRouterExample)

set(SOURCES
    main.cpp
    main.qml
)

set(RESOURCES
    resources.qrc
)

qt5_add_resources(SOURCES ${RESOURCES})
set(PUBLIC_LINK_LIBRARIES Flugs::HttpServer Qt5::Core Qt5::Network Qt5::Qml)
add_executable(${COMPONENT} ${SOURCES})
target_link_libraries(${COMPONENT} PUBLIC ${PUBLIC_LINK_LIBRARIES})
