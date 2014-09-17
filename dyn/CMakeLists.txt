include_directories (${PROJECT_SOURCE_DIR}/uds)

link_directories (/usr/local/pgsql/lib)
add_library (dyn SHARED coutnode.h coutnode.cpp fixed_loader.h)
# guild curl caf and then postgres deps
target_link_libraries (dyn curl caf_core caf_io pq pqxx pgport pgcommon z edit crypt dl m )


