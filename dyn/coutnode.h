/* 
 * File:   coutnode.h
 * Author: edward
 *
 * Created on September 11, 2014, 7:08 PM
 */

#ifndef COUTNODE_H
#define	COUTNODE_H

#include "caf/all.hpp"
#include "caf/io/all.hpp"
#include "externalizable.h"
#include "node.h"

using namespace caf;

class coutnode : public node {
public:
  coutnode(event_based_actor * parentc, actor * nextc);
  void process(externalizable * e);
private:
};

#endif	/* COUTNODE_H */

