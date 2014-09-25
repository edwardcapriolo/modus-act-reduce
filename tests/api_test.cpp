
#include <cppunit/extensions/HelperMacros.h>
#include <caf/await_all_actors_done.hpp>
#include "uds_def.h"
#include "uds.h"
#include "coutnode.h"

using namespace modus;

class api_test : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE( api_test );
  CPPUNIT_TEST( testCout );

  CPPUNIT_TEST_SUITE_END();
public:

  void testCout () {
    uds u;
    node * n = new coutnode();
    uds * map_step = u.map( n);
  }
 
};
CPPUNIT_TEST_SUITE_REGISTRATION( api_test );