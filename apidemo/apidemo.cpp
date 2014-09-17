#include "uds.h"
#include "modus_context.h"
#include "uds_def.h"

using namespace std;
using namespace modus;

int main (){
  file_feed_def<int> f1 (file_feed_def<int>(string("/tmp/a")));
  modus_context m ;
  uds_def<int> d = m.load(f1);
  fx<double,int> convert;
  uds_def<double> n = d.map( convert);
  rfx<double,double, double> change;
  uds_def<double,double> o = n.reduce(change);
  
  
}
