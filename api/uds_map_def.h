#ifndef UDS_MAP_DEF_H
#define	UDS_MAP_DEF_H
#include "uds_def.h"
#include "node.h"

class uds_map_def : public uds_def {
public:
  uds_map_def();
  uds_map_def(node n); 
  virtual ~uds_map_def();
private:
  node node;
};

#endif	/* UDS_MAP_DEF_H */

