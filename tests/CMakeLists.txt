
enable_testing()
#set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic")

FILE(GLOB UnitTests_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*_test.cpp" )
ADD_EXECUTABLE(UnitTester test_runner.cpp ${UnitTests_SRCS})
FOREACH(test ${UnitTests_SRCS})
        GET_FILENAME_COMPONENT(TestName ${test} NAME_WE)
        add_test(${TestName} UnitTester ${TestName})
ENDFOREACH(test)

include_directories (${PROJECT_SOURCE_DIR}/api)
include_directories (${PROJECT_SOURCE_DIR}/uds)
include_directories (${PROJECT_SOURCE_DIR}/dyn)


link_directories (${PROJECT_SOURCE_DIR}/api)
link_directories (${PROJECT_SOURCE_DIR}/uds)
link_directories (${PROJECT_SOURCE_DIR}/dyn)

target_link_libraries (UnitTester cppunit curl caf_core caf_io dl actred-api dyn fixed guild )

