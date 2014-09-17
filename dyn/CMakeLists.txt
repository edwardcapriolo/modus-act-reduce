include_directories (${PROJECT_SOURCE_DIR}/uds)

link_directories (/usr/local/pgsql/lib)
add_library (dyn SHARED coutnode.h coutnode.cpp)
add_library (fixed SHARED fixed_loader.h fixed_loader.cpp)
# guild curl caf and then postgres deps
target_link_libraries (dyn   curl caf_core caf_io dl m )
target_link_libraries (fixed curl caf_core caf_io dl m )

