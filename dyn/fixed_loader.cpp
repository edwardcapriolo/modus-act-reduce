/* 
 * File:   fixed_loader.cpp
 * Author: edward
 * 
 * Created on September 16, 2014, 6:46 PM
 */

#include "fixed_loader.h"

namespace modus {

extern "C" {
  node *lmaker(event_based_actor * parentc, actor * nextc) {
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