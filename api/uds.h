#ifndef UDS_H
#define	UDS_H
#include "uds_map_def.h"
#include "node.h"

class uds {
public:
  uds();
  uds(const uds& orig);
  virtual ~uds();
  uds * map(node * n);
  
private:
  uds * parent;
  uds_def * def;
};

#endif	/* UDS_H */

