#include "from.h"
#include "externalizable.h"

class insert_request {
public:
  externalizable * t;
  from f;
};

bool operator == (const insert_request& lhs, const insert_request& rhs) {
  return lhs.t == rhs.t && lhs.f == rhs.f;
}
