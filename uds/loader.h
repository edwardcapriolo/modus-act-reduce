/* 
 * File:   loader.h
 * Author: edward
 *
 * Created on September 16, 2014, 9:16 AM
 */

#ifndef LOADER_H
#define	LOADER_H
#include "caf/all.hpp"
#include "caf/io/all.hpp"
#include "externalizable.h"

using namespace caf;

class loader {
public:
  loader(event_based_actor * parentc, actor * nextc) 
  : parent(parentc), next(nextc) { }
  virtual void exec ();  
private:
  /* The next actor in the chain*/
  actor * next;
  /* The actor that created this node*/
  event_based_actor * parent;
};

typedef loader *lmaker_t(event_based_actor *, actor *);
extern map<string, lmaker_t *, less<string> > modus_loader_factory;
#endif	/* LOADER_H */