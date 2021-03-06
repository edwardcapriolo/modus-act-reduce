#ifndef MODUS_CONTEXT_H
#define	MODUS_CONTEXT_H

#include "guild.h"
#include "feed_def.h"
#include "uds_def.h"
using namespace std;
namespace modus {

class modus_context {
public:
  modus_context(){
    etcd_session s(etcd_host("localhost", 4001));
    g = new guild(&s, 20);
  }
  modus_context(string host, int port, int expire_in_seconds){
    etcd_session s(etcd_host(host, port));
    g = new guild(&s, expire_in_seconds);
  }
  guild * get_guild(){
    return g;
  }
  
  uds_def * load(feed_def f){
    /*  
    uds_def d ;
    d.set_feed(f);
    return d;    
     */
      return NULL;
  }
private:
  guild * g;  
};

}
#endif	/* MODUS_CONTEXT_H */

