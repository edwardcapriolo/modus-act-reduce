#include "caf/all.hpp"
#include "caf/io/all.hpp"
#include "externalizable.h"
#include "uds.h"
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <caf/variant.hpp>

using namespace caf;

class someext : public externalizable {
public:
  void externalize(work & work, from & f) {}
  void create_store(connection & conn) {}
  virtual void internalize(result & r) {}
  int x;
};

class somearch {
private:
    friend class boost::serialization::access;
public:
  somearch();
  int degrees;
  int minutes;
  int seconds;
  template <class Archive>
  void serialize(Archive ar, const unsigned int version){
    ar & degrees;
    ar & minutes;
    ar & seconds;
  }
};

bool operator == (const someext& lhs, const someext& rhs){
    return lhs.x == rhs.x;
}
class mapper {
public:
  void map(externalizable * e, actor next){
     someext * s;
     s = (someext*) e;
     cout << "I can do a pointer " << s->x;
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
  someext e;
  e.x=5;
  
  from f;
  f.id = 5;
  
  insert_request r;
  r.f = f;
  r.t = &e;
  
  
  announce<someext>(&someext::x);
  announce<from>(&from::id);
  announce<insert_request>(&insert_request::f, &insert_request::t);
  auto insert = spawn(insert_request_actor);
  anon_send(insert, r);
  std::this_thread::sleep_for(std::chrono::milliseconds(5000));
}
