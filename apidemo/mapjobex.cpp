#include "api.h"
#include "caf/all.hpp"
#include "caf/io/all.hpp"
#include <chrono>

using namespace std;
using namespace caf;

template <class T>
class fixed_feed_def : public feed_def<T> {
public:
  actor send;
  int start;
  int end;
  fixed_feed_def(int start, int end, actor send_to){
     send = send_to;
     this->start = start;
     this->end = end;
  } 
 
 void go(){
   for (int i=start ; i<end ; i++){
     anon_send(send, atom("r"), i);
   }
 }
 
 vector<feed_partition> get_splits() { }  
 
 private  :
 
};

void addOneMapper(event_based_actor* self, actor next) {
  self->become (
    on(atom("r"), val<int>) >> [=](atom_value op, int a){ 
      cout << "got " << a << endl;
      self->send(next, atom("r"), a+1);
    },
    others() >> [=] {
        aout(self) << "Mapper has malformed tuple";
    }
  );
}

void output_sync_actor(event_based_actor* self){
  self->become (
    on(atom("r"), val<int>) >> [=](atom_value op, int a){ 
      cout << "got " << a << endl << "write to disk";
    },
    others() >> [=] {
        aout(self) << "Outsync has malformed tuple";
    }
  );
}

int main(){
   actor sink = spawn(output_sync_actor);
  actor mapper = spawn(addOneMapper, sink);
  fixed_feed_def<int> ff (1,1000, mapper);
  ff.go();   
  std::this_thread::sleep_for(std::chrono::milliseconds(5000));
}