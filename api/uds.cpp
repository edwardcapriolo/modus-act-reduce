#include "uds.h"

uds::uds() {
}

uds::uds(const uds& orig) {
}

uds::~uds() {
}

uds * uds::map(node * n){
  uds * u = new uds();
  uds_map_def * d = new uds_map_def(n);
  u->def = dynamic_cast<uds_def*>(d);
  return u;
}