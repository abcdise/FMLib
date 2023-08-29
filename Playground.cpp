#include "Playground.h"
#include "testing.h"
#include "matlib.h"

static void testUsability(){
    ASSERT_APPROX_EQUAL(1.0, 1.0001, 0.001);
}

static void testSeed(){
    rng("default");
    double x = randn(1)[0];
    rng("default");
    double y = randn(1)[0];
    ASSERT_APPROX_EQUAL(x, y, 0.0);
}

void testPlayground(){
    TEST(testUsability);
    TEST(testSeed);
}