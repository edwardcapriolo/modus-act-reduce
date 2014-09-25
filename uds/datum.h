#ifndef DATUM_H
#define	DATUM_H

#include "from.h"
namespace modus {

class datum {
public:
  externalizable * payload;
  from source;
};

inline bool operator == (const datum& lhs, const datum& rhs) {
  return lhs.payload == rhs.payload && lhs.source == rhs.source;
}

}

#endif	/* DATUM_H */

