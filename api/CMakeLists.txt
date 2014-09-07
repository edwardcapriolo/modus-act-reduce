include_directories (${PROJECT_SOURCE_DIR}/../etcdcpp)
include_directories (${PROJECT_SOURCE_DIR}/../modus/guild)
add_library (actred-api api.h dummy.cpp)
#add_library( [STATIC | SHARED | MODULE] [EXCLUDE_FROM_ALL] source1 source2 ... sourceN) http://stackoverflow.com/questions/16655705/cmake-cannot-determine-linker-language-for-target
