#include <cppunit/extensions/HelperMacros.h>
#include <caf/await_all_actors_done.hpp>
#include <caf/actor.hpp>
#include "dynamic_loader.h"
#include "loader.h"
#include "node.h"
#include "datum.h"
#include "int_externalizable.h"

using namespace modus;

class loader_test : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE( loader_test );
  CPPUNIT_TEST( testCout );
  CPPUNIT_TEST( testLoader );
  CPPUNIT_TEST( testChain    );
  CPPUNIT_TEST_SUITE_END();
public:

  void testCout () { 
    node * cout_node = load_node("dyn", "coutnode");
    CPPUNIT_ASSERT( cout_node != NULL );
  }
  void testLoader () { 
    loader * loader_node = load_loader("fixed", "fixed_loader");
    CPPUNIT_ASSERT( loader_node != NULL );
  }
  
  void testChain () {
    announce<datum>(&datum::source, &datum::payload);
    from f(5);
    datum d;
    d.source = f;
    int_externalizable * ex = new int_externalizable();
    ex->x = 10;
    d.payload = ex;
    
    node * cout_node = load_node("dyn", "coutnode");
    cout_node->process(d);
    actor i = spawn(modus_node_actor_end, cout_node);
    
    loader * loader_node = load_loader("fixed", "fixed_loader");
    actor loader_actor = spawn(modus_loader_actor, loader_node, &i);
    
    loader_node->exec();
    anon_send(loader_actor, d);
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
  }
};
CPPUNIT_TEST_SUITE_REGISTRATION( loader_test );
