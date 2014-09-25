
#link_directories (/usr/local/pgsql/lib)
add_library (uds  dummy.cpp loader.h dynamic_loader.h node.h node.cpp)
# guild curl caf and then postgres deps
#target_link_libraries (uds guild curl caf_core caf_io pq pqxx pgport pgcommon z edit crypt dl m )
target_link_libraries (uds guild curl caf_core caf_io dl m )

