#include "Playground.h"
#include "testing.h"

static void testUsability(){
    ASSERT_APPROX_EQUAL(1.0, 1.0001, 0.001);
}

void testPlayground(){
    setDebugEnabled(true);
    TEST(testUsability);
}