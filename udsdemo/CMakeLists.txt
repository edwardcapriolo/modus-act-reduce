include_directories (${PROJECT_SOURCE_DIR}/../etcdcpp)
include_directories (${PROJECT_SOURCE_DIR}/../modus/guild)
include_directories (${PROJECT_SOURCE_DIR}/api)
include_directories (${PROJECT_SOURCE_DIR}/uds)

link_directories (${PROJECT_SOURCE_DIR}/../modus/guild )

add_executable (udsdemo udsdemo.cpp)

target_link_libraries (udsdemo guild curl caf_core caf_io dl)
