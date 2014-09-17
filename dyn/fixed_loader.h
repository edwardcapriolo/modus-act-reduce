/* 
 * File:   fixed_loader.h
 * Author: edward
 *
 * Created on September 16, 2014, 6:46 PM
 */

#ifndef FIXED_LOADER_H
#define	FIXED_LOADER_H
#include "loader.h"

using namespace caf;


namespace modus {

class fixed_int_externalizable : public externalizable {
public:
  int y;
  const int hash_code(){ return y; }
  const bool equals(const externalizable * other){ 
    fixed_int_externalizable  *  s = dynamic_cast<fixed_int_externalizable *>(other);
    return s->y == y;
  }
};

    
class fixed_loader : public loader {
public:
    fixed_loader(event_based_actor * parentc, actor * nextc)
    : parent(parentc), next(nextc) { }
 
    void exec (){
        parent->send(nextc, fixed_int_externalizable{1} );
        parent->send(nextc, fixed_int_externalizable{2} );
        parent->send(nextc, fixed_int_externalizable{4} );
    }
    
private:
  actor * next;
  event_based_actor * parent;
};

}//end namespace
#endif	/* FIXED_LOADER_H */

