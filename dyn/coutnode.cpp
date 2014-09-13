/* 
 * File:   coutnode.cpp
 * Author: edward
 * 
 * Created on September 11, 2014, 7:08 PM
 */

#include "coutnode.h"

namespace modus {
coutnode::coutnode( event_based_actor * parentc, actor * nextc) 
 : node (parentc, nextc) {
   
}
void coutnode::process(externalizable * e){
  cout << e->hash_code() << endl;
}


extern "C" {
  node *maker(event_based_actor * parentc, actor * nextc) {
    return new coutnode(parentc, nextc);
  }
  
  class proxy { 
    public:
     proxy(){
        modus_node_factory["coutnode"] = maker;
     }
  };
  proxy p;
}

}