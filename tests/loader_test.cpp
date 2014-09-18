#include <cppunit/extensions/HelperMacros.h>
#include "dynamic_loader.h"
#include "loader.h"
#include "node.h"

using namespace modus;

class loader_test : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE( loader_test );
  CPPUNIT_TEST( testCout );
  CPPUNIT_TEST( testLoader );
  CPPUNIT_TEST_SUITE_END();
public:

  void testCout () { 
    node * cout_node = load_node("dyn", "coutnode", NULL, NULL);
    CPPUNIT_ASSERT( cout_node != NULL );
  }
  void testLoader () { 
    loader * loader_node = load_loader("fixed", "fixed_loader", NULL, NULL);
    CPPUNIT_ASSERT( loader_node != NULL );
  }
  
  void testChain () {
    node * cout_node = load_node("dyn", "coutnode", NULL, NULL);
    loader * loader_node = load_loader("fixed", "fixed_loader", NULL, NULL);  
  }
};
CPPUNIT_TEST_SUITE_REGISTRATION( loader_test );
