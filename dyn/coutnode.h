#ifndef COUTNODE_H
#define	COUTNODE_H

#include "caf/all.hpp"
#include "caf/io/all.hpp"
#include "externalizable.h"
#include "node.h"

using namespace caf;
using namespace std;

map<string, maker_t *, less<string> > modus_node_factory;

namespace modus {

class coutnode : public node {
public:
  coutnode(event_based_actor * parentc, actor * nextc);
  void process(externalizable * e);
private:
};

}

#endif	/* COUTNODE_H */

