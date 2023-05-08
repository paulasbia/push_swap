#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>
#include "unity.h"


void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

struct params {
    int x;
    int y;
    int result;
    int sub;
};

void soma(struct params *p){
    p->result = p->x + p->y;
    p->sub = p->x - p->y;
}

void usa_soma(){
    struct params p;
    p.x = 1;
    p.y = 2;
    soma(&p);
    TEST_ASSERT_EQUAL_INT32(3, p.result);
    TEST_ASSERT_EQUAL_INT32(-1, p.sub);
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(usa_soma);
    return UNITY_END();
}

