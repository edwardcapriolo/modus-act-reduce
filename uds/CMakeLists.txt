include_directories (${PROJECT_SOURCE_DIR}/../etcdcpp)
link_directories (/usr/local/pgsql/lib)
add_library (uds uds.h dummy.cpp)
# guild curl caf and then postgres deps
target_link_libraries (uds guild curl caf_core caf_io pq pqxx pgport pgcommon z edit crypt dl m )


