#ifndef FIXED_LOADER_H
#define	FIXED_LOADER_H

#include "loader.h"
#include "caf/all.hpp"
#include "caf/io/all.hpp"
#include "externalizable.h"

using namespace caf;
using namespace std;

map<string, lmaker_t *, less<string> > modus_loader_factory;

namespace modus {
        
class fixed_loader : public loader {
public:
  fixed_loader();
  void exec ();
  string get_register_name(); 
private:
};

}//end namespace
#endif	/* FIXED_LOADER_H */


    /*
class fixed_int_externalizable : public externalizable {
public:
  int y;
  virtual int hash_code(){ return y; }
  virtual bool equals(externalizable * other){ 
    fixed_int_externalizable  *  s = dynamic_cast<fixed_int_externalizable *>(other);
    return s->y == y;
  }
};
*/