add_library (actred-api dummy.cpp uds_def.h uds_def.cpp uds.h uds.cpp uds_map_def.h uds_map_def.cpp)
include_directories (${PROJECT_SOURCE_DIR}/uds)
#add_library( [STATIC | SHARED | MODULE] [EXCLUDE_FROM_ALL] source1 source2 ... sourceN) http://stackoverflow.com/questions/16655705/cmake-cannot-determine-linker-language-for-target
