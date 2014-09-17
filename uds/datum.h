/* 
 * File:   datum.h
 * Author: edward
 *
 * Created on September 17, 2014, 9:42 AM
 */

#ifndef DATUM_H
#define	DATUM_H

#include "from.h"
namespace modus {

class datum {
public:
  externalizable * payload;
  from source;
};

bool operator == (const datum& lhs, const datum& rhs) {
  return lhs.payload == rhs.payload && lhs.source == rhs.source;
}

}

#endif	/* DATUM_H */

