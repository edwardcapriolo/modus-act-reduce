#include <cppunit/extensions/HelperMacros.h>
#include "dynamic_loader.h"
#include "loader.h"
#include "node.h"

using namespace modus;

class loader_test : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE( loader_test );
  CPPUNIT_TEST( testEmpty );
  CPPUNIT_TEST_SUITE_END();
public:
  void testEmpty () { 
    node * cout_node = load_node("dyn", "coutnode", NULL, NULL);
    CPPUNIT_ASSERT( cout_node != NULL );
  }
};
CPPUNIT_TEST_SUITE_REGISTRATION( loader_test );
