#include "Playground.h"
#include "testing.h"

static void testUsability(){
    ASSERT_APPROX_EQUAL(1.0, 0.1, 0.001);
}

void testPlayground(){
    TEST(testUsability);
}