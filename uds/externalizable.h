/* 
 * File:   externalizable.h
 * Author: edward
 *
 * Created on September 5, 2014, 8:01 PM
 */

#ifndef EXTERNALIZABLE_H
#define	EXTERNALIZABLE_H

//#include <pqxx/pqxx> 
#include "from.h"
using namespace std;

//using namespace pqxx;

/**
 * This interface will need to be heavily re-worked once we 
 * have a good type system. 
 * 
 */
class externalizable {
public:
  /**
  virtual void externalize(work & work, from & f) {}
  virtual void create_store(connection & conn) {}
  virtual void internalize(result & r) {}
  */
  const virtual int hash_code(){ }
  const virtual bool equals(const externalizable * other){ return false; }
};

bool operator == (const externalizable& lhs, const externalizable& rhs){
   // return lhs.equals(&rhs);
    
  return false;
  
}



#endif	/* EXTERNALIZABLE_H */

