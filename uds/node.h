
#ifndef NODE_H
#define	NODE_H

#include "caf/all.hpp"
#include "caf/io/all.hpp"
#include "externalizable.h"
#include "datum.h"

using namespace caf;
using namespace std;

class node  {
public:
  node() { }
  virtual void process(modus::datum  d){}
  void set_parent(event_based_actor * par){ parent = par; }
  void set_next(actor * nex) { next = nex; }
protected:
  actor * next;
  event_based_actor * parent;
};

namespace modus {

void modus_node_actor_end(event_based_actor * self, node * processor){
  processor->set_parent(self);
  self->become (
    on(val<datum>) >> [=](datum a){
      processor->process(a);
    },
    others() >> [=] {
        aout(self) << "Node has malformed tuple";
    }
  );      
}

void modus_node_actor(event_based_actor * self, node * processor, actor * next){
  processor->set_parent(self);
  processor->set_next(next);
  self->become (
    on(val<datum>) >> [=](datum a){
      cout << "got "  << endl;
      processor->process(a);
    },
    others() >> [=] {
        aout(self) << "Node has malformed tuple";
    }
  );
}

}

typedef node *maker_t();
extern map<string, maker_t *, less<string> > modus_node_factory;

#endif	/* NODE_H */

