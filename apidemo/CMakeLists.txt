include_directories (${PROJECT_SOURCE_DIR}/../etcdcpp)
include_directories (${PROJECT_SOURCE_DIR}/../modus/guild)
include_directories (${PROJECT_SOURCE_DIR}/api)
include_directories (${PROJECT_SOURCE_DIR}/uds)

link_directories (${PROJECT_SOURCE_DIR}/../modus/guild )

add_executable (apidemo apidemo.cpp)
add_executable (mapjobex mapjobex.cpp)

target_link_libraries (apidemo guild curl caf_core caf_io)
target_link_libraries (mapjobex guild curl caf_core caf_io)
