/* 
 * File:   dynamic_loader.h
 * Author: edward
 *
 * Created on September 11, 2014, 7:24 PM
 */

#ifndef DYNAMIC_LOADER_H
#define	DYNAMIC_LOADER_H

#include <string>
#include <dlfcn.h>
#include <stdio.h>
#include <unistd.h>
#include <map>
#include "node.h"


using namespace std;
static unsigned int BUF_SIZE = 1024;

map<string, maker_t *, less<string> > factory;

void load(){
  list<void *> dl_list; 
  void *dlib;
  dlib = dlopen("dyn/libdyn.so", RTLD_NOW);
  if(dlib == NULL){
    cerr << dlerror() << endl;
    exit(-1);
  }
  dl_list.insert(dl_list.end(), dlib);
  node * mynode = factory["coutnode"](NULL, NULL);
  cout << "load" << endl;
}

/*
 FILE *dl;   // handle to read directory
  char *command_str = "ls *.so";  // command
  char in_buf[BUF_SIZE]; // input buffer for lib
  list<void *> dl_list; // list to hold handles
  list<void *>::iterator itr;
  vector<string> node_names;  // vector of shape
   list<node *> shape_list;
   list<node *>::iterator sitr;
   map<string, maker_t *, less<string> >::iterator fitr;
   dl = popen(command_str, "r");
   if(!dl){
      perror("popen");
      exit(-1);
   }
   void *dlib;
   char name[1024]; 
 
 */

#endif	/* DYNAMIC_LOADER_H */

