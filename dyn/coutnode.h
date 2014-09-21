#ifndef COUTNODE_H
#define	COUTNODE_H

#include "caf/all.hpp"
#include "caf/io/all.hpp"
#include "externalizable.h"
#include "node.h"
#include "datum.h"

using namespace caf;
using namespace std;

map<string, maker_t *, less<string> > modus_node_factory;

namespace modus {

class coutnode : public node  {
public:
  coutnode();
  virtual void process(const modus::datum req);
  
};

}

#endif	/* COUTNODE_H */

