
#ifndef LOADER_H
#define	LOADER_H

#include "caf/all.hpp"
#include "caf/io/all.hpp"
#include "externalizable.h"
#include "datum.h"

using namespace caf;
using namespace std;

class loader {
public:
  loader() { }
  virtual void exec (){}
  /**
   * @return the name that this loader instances will register with
   */  
  virtual string get_register_name() = 0;
  void set_next(actor * nex){
    next = nex;
  }
  void set_parent(event_based_actor * par){
    parent = par;
  }
protected:
  actor * next;
  event_based_actor * parent;
};

namespace modus {

void modus_loader_actor(event_based_actor * self, loader * loader, actor * next){
  loader->set_next(next);
  loader->set_parent(self);
  self->become (
    on(val<datum>) >> [=](datum a){
      cout << "loader got "  << endl;
      self->send(*next, a);
    },
    others() >> [=] {
        aout(self) << "Node has malformed tuple";
    }
  );
}

}

typedef loader *lmaker_t();
extern map<string, lmaker_t *, less<string> > modus_loader_factory;
#endif	/* LOADER_H */