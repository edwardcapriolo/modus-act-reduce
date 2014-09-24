#ifndef FEED_DEF_H
#define	FEED_DEF_H

#include <iostream>
#include <sstream> 
#include <vector>
using namespace std;

class feed_partition {
public: 
  feed_partition(){
      
  }    
};

class feed_def {
public:
  feed_def(){
            
  }
    
  vector<feed_partition> get_splits() { }  
};

class file_feed_def : public feed_def    {
public:
  file_feed_def(string filename){
    this->filename = filename;

  }
private:
  string filename;  
};

#endif	/* FEED_DEF_H */

