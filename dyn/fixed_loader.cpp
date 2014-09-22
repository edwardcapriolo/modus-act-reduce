#include "fixed_loader.h"

#include "int_externalizable.h"
#include "datum.h"
#include "datum.h"
using namespace caf;
namespace modus {

fixed_loader::fixed_loader( ) {
    
}
 
string fixed_loader::get_register_name(){ 
  return string("fixed_loader");
}

void fixed_loader::fixed_loader::exec(){
  from f(42);
 
  announce<from> (&from::id);
  announce<datum>(&datum::payload, &datum::source);
  datum d;
  d.source = f;
  int_externalizable * i = new int_externalizable();
  i->x = 5;
  d.payload = i;
  //anon_send(*next, d);
  parent->send(*next, d);      
}

extern "C" {
  loader *lmaker() {
    return new fixed_loader();
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