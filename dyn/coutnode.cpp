#include "coutnode.h"
#include "datum.h"
using namespace std;
using namespace caf;

namespace modus {
    
coutnode::coutnode( ) 
 : node () {
   
}

void coutnode::process(const modus::datum req){
  cout << req.payload->hash_code() << "hash" << endl;
}

extern "C" {
  node *maker() {
    return new coutnode();
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