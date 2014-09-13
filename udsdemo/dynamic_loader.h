/* 
 * File:   dynamic_loader.h
 * Author: edward
 *
 * Created on September 11, 2014, 7:24 PM
 */

#ifndef DYNAMIC_LOADER_H
#define	DYNAMIC_LOADER_H

#include "caf/all.hpp"
#include "caf/io/all.hpp"

#include <string>
#include <dlfcn.h>
#include <stdio.h>
#include <unistd.h>
#include <map>
#include "node.h"

using namespace std;

// This is here because the c dynamic loader is c++ namespace unaware ?
map<string, maker_t *, less<string> > modus_node_factory;

namespace modus {

node * load_node(string module_name, event_based_actor * self, actor * next){
  string path = "dyn/lib" + module_name + ".so";
  void *dlib;
  dlib = dlopen(path.c_str(), RTLD_NOW);
  if(dlib == NULL){
    cerr << dlerror() << endl;
    throw "Unable to open" ;
  }
  node * my_node = modus_node_factory["coutnode"](self, next);
  return my_node;
}

}

#endif	/* DYNAMIC_LOADER_H */

