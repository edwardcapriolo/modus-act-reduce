#include "fixed_loader.h"

using namespace caf;
namespace modus {

fixed_loader::fixed_loader( event_based_actor * parentc, actor * nextc) 
 : loader (parentc, nextc) {
   
}
 
void fixed_loader::exec(){
    
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