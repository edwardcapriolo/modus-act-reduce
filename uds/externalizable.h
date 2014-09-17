#ifndef EXTERNALIZABLE_H
#define	EXTERNALIZABLE_H

#include "from.h"


class externalizable {
public:
  virtual int hash_code(){ }
  virtual bool equals(externalizable * other){ return false; }
};

bool operator == (const externalizable& lhs, const externalizable& rhs){
   // return lhs.equals(&rhs);
  return false;
}
#endif	/* EXTERNALIZABLE_H */

  /**
  virtual void externalize(work & work, from & f) {}
  virtual void create_store(connection & conn) {}
  virtual void internalize(result & r) {}
  */
