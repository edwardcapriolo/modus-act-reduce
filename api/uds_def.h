/* 
 * File:   uds_def.h
 * Author: edward
 *
 * Created on September 7, 2014, 12:06 PM
 */

#ifndef UDS_DEF_H
#define	UDS_DEF_H

#include "feed_def.h"
#include "fx.h"
#include "rfx.h"
#include "uds_map_def.h"
//forward define
template <class Returns, class Takes>
class uds_map_def;

template <class ReturnKey, class ReturnValue, class Takes>
class uds_reduce_def;

template <class MyType, class ... MyType2>
class uds_def {
public:
  uds_def(){
        
  }
  void set_feed(feed_def<MyType> aDef){
    feed = aDef;    
  }
  
  template<class Returns>
  uds_def<Returns> map(fx<Returns,MyType> fx){
    uds_map_def<Returns, MyType> result;
    result.parent = this;
    result.mapFx = fx;
    return result;
  }
  
  template<class  ReturnKey, class ReturnValue>
  uds_def<ReturnKey, ReturnValue> reduce  (rfx<ReturnKey,ReturnValue,MyType> fx){
    uds_reduce_def<ReturnKey, ReturnValue, MyType> result;
    result.parent = this;
    result.reduceFx = fx;
    return result;
  }
  uds_def* parent;
private:
  feed_def<MyType> feed;
};

template <class Returns, class Takes>
class uds_map_def : public uds_def<Returns> {
public:
  uds_map_def(){
  }
  fx <Returns, Takes> mapFx;
  uds_def<Takes>* parent;
private:       
};

template <class ReturnKey, class ReturnValue, class Takes>
class uds_reduce_def : public uds_def<ReturnKey,ReturnValue> {
public:    
  uds_reduce_def(){
        
  }
  rfx <ReturnKey, ReturnValue, Takes> reduceFx;
  uds_def<Takes>* parent;
};

#endif	/* UDS_DEF_H */

