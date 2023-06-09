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
    swap_a(&lst);
    TEST_ASSERT_EQUAL_STRING("b", lst->content);
    TEST_ASSERT_EQUAL_STRING("a", lst->next->content);
    TEST_ASSERT_EQUAL_STRING("c", lst->next->next->content);
}

static void test_push_a(void)
{
    t_list  *lsta;
    t_list  *lstb;

    lsta = NULL;
    lstb = NULL;
    ft_lstadd_back(&lsta, ft_lstnew("a")); // lst = a
    ft_lstadd_back(&lsta, ft_lstnew("b"));// lst = a -> b
    ft_lstadd_back(&lsta, ft_lstnew("c")); // lst = a -> b -> c
    ft_lstadd_back(&lstb, ft_lstnew("d")); // lst = a
    ft_lstadd_back(&lstb, ft_lstnew("e"));// lst = a -> b
    ft_lstadd_back(&lstb, ft_lstnew("f")); // lst = a -> b -> c
    push_a(&lsta, &lstb);
    TEST_ASSERT_EQUAL_STRING("d", lsta->content);
    TEST_ASSERT_EQUAL_STRING("a", lsta->next->content);
    TEST_ASSERT_EQUAL_STRING("b", lsta->next->next->content);
}

static void test_push_b(void)
{
    t_list  *lsta;
    t_list  *lstb;

    lsta = NULL;
    lstb = NULL;
    ft_lstadd_back(&lsta, ft_lstnew("a")); // lst = a
    ft_lstadd_back(&lsta, ft_lstnew("b"));// lst = a -> b
    ft_lstadd_back(&lsta, ft_lstnew("c")); // lst = a -> b -> c
    ft_lstadd_back(&lstb, ft_lstnew("d")); // lst = a
    ft_lstadd_back(&lstb, ft_lstnew("e"));// lst = a -> b
    ft_lstadd_back(&lstb, ft_lstnew("f")); // lst = a -> b -> c
    push_b(&lstb, &lsta);
    TEST_ASSERT_EQUAL_STRING("a", lstb->content);
    TEST_ASSERT_EQUAL_STRING("d", lstb->next->content);
    TEST_ASSERT_EQUAL_STRING("e", lstb->next->next->content);
}

static void test_rotate(void)
{
    t_list  *lsta;
    t_list  *lstb;

    lsta = NULL;
    lstb = NULL;
    ft_lstadd_back(&lsta, ft_lstnew("a")); // lst = a
    ft_lstadd_back(&lsta, ft_lstnew("b"));// lst = a -> b
    ft_lstadd_back(&lsta, ft_lstnew("c")); // lst = a -> b -> c
    ft_lstadd_back(&lstb, ft_lstnew("d")); // lst = a
    ft_lstadd_back(&lstb, ft_lstnew("e"));// lst = a -> b
    ft_lstadd_back(&lstb, ft_lstnew("f")); // lst = a -> b -> c
    rotate_a(&lsta);
    TEST_ASSERT_EQUAL_STRING("b", lsta->content);
    TEST_ASSERT_EQUAL_STRING("c", lsta->next->content);
    TEST_ASSERT_EQUAL_STRING("a", lsta->next->next->content);
    TEST_ASSERT_EQUAL(NULL, lsta->next->next->next);
    rotate_b(&lstb);
    TEST_ASSERT_EQUAL_STRING("e", lstb->content);
    TEST_ASSERT_EQUAL_STRING("f", lstb->next->content);
    TEST_ASSERT_EQUAL_STRING("d", lstb->next->next->content);
}

static void test_rotate_inval(void)
{
    t_list  *lsta;
    t_list  *lstb;

    lsta = NULL;
    lstb = NULL;
    ft_lstadd_back(&lsta, ft_lstnew("a"));
    rotate_a(&lsta);
    TEST_ASSERT_EQUAL_STRING("a", lsta->content);
    rotate_b(&lstb);
    TEST_ASSERT_EQUAL(NULL, lstb);
}

static void test_rotate_rr(void)
{
    t_list  *lsta;
    t_list  *lstb;

    lsta = NULL;
    lstb = NULL;
    ft_lstadd_back(&lsta, ft_lstnew("a")); // lst = a
    ft_lstadd_back(&lsta, ft_lstnew("b"));// lst = a -> b
    ft_lstadd_back(&lsta, ft_lstnew("c")); // lst = a -> b -> c
    ft_lstadd_back(&lstb, ft_lstnew("d")); // lst = a
    ft_lstadd_back(&lstb, ft_lstnew("e"));// lst = a -> b
    ft_lstadd_back(&lstb, ft_lstnew("f")); // lst = a -> b -> c
    rotate_rr(&lsta, &lstb);
    TEST_ASSERT_EQUAL_STRING("b", lsta->content);
    TEST_ASSERT_EQUAL_STRING("c", lsta->next->content);
    TEST_ASSERT_EQUAL_STRING("a", lsta->next->next->content);
    TEST_ASSERT_EQUAL_STRING("e", lstb->content);
    TEST_ASSERT_EQUAL_STRING("f", lstb->next->content);
    TEST_ASSERT_EQUAL_STRING("d", lstb->next->next->content);
}

static void test_rev_rotate(void)
{
    t_list  *lsta;
    t_list  *lstb;

    lsta = NULL;
    lstb = NULL;
    ft_lstadd_back(&lsta, ft_lstnew("a")); // lst = a
    ft_lstadd_back(&lsta, ft_lstnew("b"));// lst = a -> b
    ft_lstadd_back(&lsta, ft_lstnew("c")); // lst = a -> b -> c
    ft_lstadd_back(&lstb, ft_lstnew("d")); // lst = a
    ft_lstadd_back(&lstb, ft_lstnew("e"));// lst = a -> b
    ft_lstadd_back(&lstb, ft_lstnew("f")); // lst = a -> b -> c
    rev_rot_a(&lsta);
    TEST_ASSERT_EQUAL_STRING("c", lsta->content);
    TEST_ASSERT_EQUAL_STRING("a", lsta->next->content);
    TEST_ASSERT_EQUAL_STRING("b", lsta->next->next->content);
    rev_rot_b(&lstb);
    TEST_ASSERT_EQUAL_STRING("f", lstb->content);
    TEST_ASSERT_EQUAL_STRING("d", lstb->next->content);
    TEST_ASSERT_EQUAL_STRING("e", lstb->next->next->content);
}

static void test_rev_rot_rrr(void)
{
    t_list  *lsta;
    t_list  *lstb;

    lsta = NULL;
    lstb = NULL;
    ft_lstadd_back(&lsta, ft_lstnew("a")); // lst = a
    ft_lstadd_back(&lsta, ft_lstnew("b")); // lst = a -> b
    ft_lstadd_back(&lsta, ft_lstnew("c")); // lst = a -> b -> c
    ft_lstadd_back(&lstb, ft_lstnew("d")); // lst = a
    ft_lstadd_back(&lstb, ft_lstnew("e")); // lst = a -> b
    ft_lstadd_back(&lstb, ft_lstnew("f")); // lst = a -> b -> c
    rev_rot_ab(&lsta, &lstb);
    TEST_ASSERT_EQUAL_STRING("c", lsta->content);
    TEST_ASSERT_EQUAL_STRING("a", lsta->next->content);
    TEST_ASSERT_EQUAL_STRING("b", lsta->next->next->content);
    TEST_ASSERT_EQUAL(NULL, lsta->next->next->next);
    TEST_ASSERT_EQUAL_STRING("f", lstb->content);
    TEST_ASSERT_EQUAL_STRING("d", lstb->next->content);
    TEST_ASSERT_EQUAL_STRING("e", lstb->next->next->content);
}

static void test_rev_rot_inval(void)
{
    t_list  *lsta;
    t_list  *lstb;

    lsta = NULL;
    lstb = NULL;
    ft_lstadd_back(&lsta, ft_lstnew("a"));
    rev_rot_a(&lsta);
    TEST_ASSERT_EQUAL_STRING("a", lsta->content);
    rev_rot_b(&lstb);
    TEST_ASSERT_EQUAL(NULL, lstb);
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_swap);
    RUN_TEST(test_push_a);
    RUN_TEST(test_push_b);
    RUN_TEST(test_rotate);
    RUN_TEST(test_rotate_inval);
    RUN_TEST(test_rotate_rr);
    RUN_TEST(test_rev_rotate);
    RUN_TEST(test_rev_rot_rrr);
    RUN_TEST(test_rev_rot_inval);
    return UNITY_END();
}

