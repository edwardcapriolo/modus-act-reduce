#ifndef FEED_DEF_H
#define	FEED_DEF_H

#include <iostream>
#include <sstream> 
using namespace std;

class feed_partition {
public: 
  feed_partition(){
      
  }    
};

template <class T>
class feed_def {
public:
  feed_def(){
            
  }
    
  vector<feed_partition> get_splits() { }  
};

template<class T>
class file_feed_def : public feed_def<T> {
public:
  file_feed_def(string filename){
    this->filename = filename;

  }
private:
  string filename;  
};

#endif	/* FEED_DEF_H */

