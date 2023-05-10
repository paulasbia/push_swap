#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>
#include "unity.h"
#include "../push_swap.h"


void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

static void test_swap(void)
{
    t_list  *lst;//lst = NULL

    lst = NULL;
    ft_lstadd_back(&lst, ft_lstnew("a")); // lst = a
    ft_lstadd_back(&lst, ft_lstnew("b"));// lst = a -> b
    ft_lstadd_back(&lst, ft_lstnew("c")); // lst = a -> b -> c
    swap(&lst, 'b');
    TEST_ASSERT_EQUAL_STRING("b", lst->content);
    TEST_ASSERT_EQUAL_STRING("a", lst->next->content);
    TEST_ASSERT_EQUAL_STRING("c", lst->next->next->content);
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_swap);
    return UNITY_END();
}

