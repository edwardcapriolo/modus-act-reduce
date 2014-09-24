
#include <cppunit/extensions/HelperMacros.h>
#include <caf/await_all_actors_done.hpp>
#include "uds_def.h"

class api_test : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE( api_test );
  CPPUNIT_TEST( testCout );

  CPPUNIT_TEST_SUITE_END();
public:

  void testCout () {
    uds_def f;
  }
 
};
CPPUNIT_TEST_SUITE_REGISTRATION( api_test );