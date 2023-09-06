#include "stdafx.h"
#include "Playground.h"
#include "testing.h"
#include "matlib.h"

using namespace std;

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

static void testPointer(){
    double* data = new double[5];
    for (int i=0; i<5; i++){
        data[i] = i;
    }
    ASSERT_APPROX_EQUAL(data[4], 4, 0.0);
    delete[] data;
}

void testPlayground(){
    TEST(testUsability);
    TEST(testSeed);
    TEST(testPointer);
}