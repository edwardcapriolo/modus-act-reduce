
#ifndef NODE_H
#define	NODE_H

#include "caf/all.hpp"
#include "caf/io/all.hpp"
#include "externalizable.h"
#include "datum.h"

using namespace caf;
using namespace std;

using node_type = typed_actor<replies_to<modus::datum>::with<void>>;

class node {
public:
  node(event_based_actor * parentc, actor * nextc) 
    : parent(parentc), next(nextc) { }
  virtual void process(externalizable * e){ }
protected:
  actor * next;
  event_based_actor * parent;
};

typedef node *maker_t(event_based_actor *, actor *);
extern map<string, maker_t *, less<string> > modus_node_factory;

#endif	/* NODE_H */

