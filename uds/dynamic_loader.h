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
#include "loader.h"

using namespace std;

// This is here because the c dynamic loader is c++ namespace unaware ?
std::map<std::string, maker_t *, std::less<string> > modus_node_factory;

std::map<std::string, lmaker_t *, std::less<string> > modus_loader_factory;

namespace modus {

/* construct a subclass of node. Construct it 
 * 
 */
    
node * load_node(string module_name, string node_name){
  string path = "../dyn/lib" + module_name + ".so";
  void *dlib;
  dlib = dlopen(path.c_str(), RTLD_NOW);
  if(dlib == NULL){
    cerr << dlerror() << endl;
    throw "Unable to open" ;
  }
  node * my_node = modus_node_factory[node_name]();
  //dlclose(dlib);
  return my_node;
}

loader * load_loader(string module_name, string loader_name, event_based_actor * self, actor * next){
  string path = "../dyn/lib" + module_name + ".so";
  void *dlib;
  dlib = dlopen(path.c_str(), RTLD_NOW);
  if(dlib == NULL){
    cerr << dlerror() << endl;
    
    throw "Unable to open" ;
  }
  loader * my_loader =  modus_loader_factory[loader_name](self, next);
  //dlclose(dlib);
  return my_loader;
}

}

#endif	/* DYNAMIC_LOADER_H */

