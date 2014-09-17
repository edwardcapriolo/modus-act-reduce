#include "fixed_loader.h"

#include "int_externalizable.h"
#include "datum.h"
#include "datum.h"
using namespace caf;
namespace modus {

fixed_loader::fixed_loader( event_based_actor * parentc, actor * nextc) 
 : loader (parentc, nextc) {
    
}
 
void fixed_loader::fixed_loader::exec(){
  from f;
  f.id = 42;
  announce<from> (&from::id);
  announce<datum>( &datum::payload, &datum::source );
  datum d;
  d.source = f;
  //this->parent->send(next,from);
  //parent->send(next, from);
  //parent->send(next, d);
  //parent->send(next, e);
  //anon_send(*next,d);
  parent->send(*next, d);
        
}

extern "C" {
  loader *lmaker(event_based_actor * parentc, actor * nextc) {
    return new fixed_loader(parentc, nextc);
  }
  
  class proxy { 
    public:
     proxy(){
        modus_loader_factory["fixed_loader"] = lmaker;
     }
  };
  proxy p;
}

}