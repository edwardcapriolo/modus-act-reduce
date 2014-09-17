/* 
 * File:   operator.h
 * Author: edward
 *
 * Created on September 10, 2014, 9:10 AM
 */

#ifndef OPERATOR_H
#define	OPERATOR_H

#include "caf/all.hpp"
#include "caf/io/all.hpp"
#include "externalizable.h"

using namespace caf;

class node {
public:
  node(event_based_actor * parentc, actor * nextc) 
    : parent(parentc), next(nextc) { }
  virtual void process(externalizable * e){ }
private:
  /* The next actor in the chain*/
  actor * next;
  /* The actor that created this node*/
  event_based_actor * parent;
};

typedef node *maker_t(event_based_actor *, actor *);
extern map<string, maker_t *, less<string> > modus_node_factory;

#endif	/* OPERATOR_H */

