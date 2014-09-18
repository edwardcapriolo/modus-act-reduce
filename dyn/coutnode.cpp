#include "coutnode.h"
#include "datum.h"
using namespace std;
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
  
  class node_proxy { 
    public:
      node_proxy(){
        modus_node_factory["coutnode"] = maker;
      }
  };
  node_proxy node_proxy;
}

}