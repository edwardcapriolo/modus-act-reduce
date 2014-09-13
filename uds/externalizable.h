/* 
 * File:   externalizable.h
 * Author: edward
 *
 * Created on September 5, 2014, 8:01 PM
 */

#ifndef EXTERNALIZABLE_H
#define	EXTERNALIZABLE_H

#include <pqxx/pqxx> 
#include "from.h"
using namespace std;

using namespace pqxx;

/**
 * This interface will need to be heavily re-worked once we 
 * have a good type system. 
 * 
 */
class externalizable {
public:
  /*
   * write this object out to work
   */
  virtual void externalize(work & work, from & f) {}
  /*
   *create something this object can serialize itself to
   */
  virtual void create_store(connection & conn) {}
  /*
   * use the result to set fields of this instance
   */
  virtual void internalize(result & r) {}
  /*
   * Provide a hash code based on the object
   */
  virtual int hash_code(){}
};

bool operator == (const externalizable& lhs, const externalizable& rhs){
  return false;
}



#endif	/* EXTERNALIZABLE_H */

