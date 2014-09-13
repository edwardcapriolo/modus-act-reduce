#include "caf/all.hpp"
#include "caf/io/all.hpp"
#include "externalizable.h"
#include "uds.h"
#include "node.h"
#include "dynamic_loader.h"


using namespace caf;
using namespace modus;

class someext : public externalizable {
public:
  void externalize(work & work, from & f) {}
  void create_store(connection & conn) {}
  void internalize(result & r) {}
  int hash_code(){
    return x+1;
  }
  int x;
};

bool operator == (const someext& lhs, const someext& rhs){
    return lhs.x == rhs.x;
}
class mapper {
public:
  void map(externalizable * e, actor next){
    cout << "I can do a hash_code " << e->hash_code() << endl;
    someext * s;
    //s = (someext*) e; 
    s = dynamic_cast<someext*>(e);
    cout << "I can do a pointer " << s->x << endl;
    cout << "I can do a hash_code " << s->hash_code() << endl;
  }
};
void insert_request_actor(event_based_actor* self) {
  self->become (
    on(val<insert_request>) >> [=](insert_request a){
      cout << "got "  << endl;
      mapper m;
      m.map(a.t, invalid_actor);
      //self->send(next, atom("r"), a+1);
    },
    others() >> [=] {
        aout(self) << "Mapper has malformed tuple";
    }
  );
}

int main(){
    
  load_node("dyn", NULL,NULL);
  someext e;
  e.x=5;
  
  from f;
  f.id = 5;
  
  insert_request r;
  r.f = f;
  r.t = &e;
  
  
  //announce<someext>(&someext::x);
  announce<from>(&from::id);
  announce<insert_request>(&insert_request::f, &insert_request::t);
  auto insert = spawn(insert_request_actor);
  io::publish(insert, 9876);
  actor new_serv = io::remote_actor("localhost", 9876);
  anon_send(new_serv, r);
  std::this_thread::sleep_for(std::chrono::milliseconds(5000));
}
