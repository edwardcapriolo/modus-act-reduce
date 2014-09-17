/* 
 * File:   int_externalizable.h
 * Author: edward
 *
 * Created on September 17, 2014, 5:51 PM
 */

#ifndef INT_EXTERNALIZABLE_H
#define	INT_EXTERNALIZABLE_H
#include "externalizable.h"

namespace modus {
class int_externalizable : public externalizable {
public:
  int hash_code(){
    return x+1;
  }
  bool equals(externalizable * other){ 
    int_externalizable * s;
    s = dynamic_cast<int_externalizable*>(other);
    return s->x == x;
  }
  int x;
};

bool operator == (const int_externalizable& lhs, const int_externalizable& rhs){
    return lhs.x == rhs.x;
}

}
#endif	/* INT_EXTERNALIZABLE_H */

