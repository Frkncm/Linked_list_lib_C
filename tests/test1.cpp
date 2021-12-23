#include <gtest/gtest.h>
extern "C"
{
#include "llist.h"
}

struct llist_test : public ::testing::Test
{
    node *my_list = NULL;
    void SetUp() override
    {
    }
    void TearDown() override
    {
    }
};

TEST_F(llist_test, is_list_created)
{
    EXPECT_TRUE(my_list == NULL);
}

TEST_F(llist_test, pop_back_and_check)
{

    for (int i = 0; i < 10; i++)
        list_pushBack(&my_list, i);

    for (int i = 9; i >= 0; i--)
        EXPECT_EQ(list_popBack(&my_list), i);

    EXPECT_TRUE(my_list == NULL);
}

TEST_F(llist_test, pop_back_and_check_sized)
{
    CREATE_LIST(l_list);

    for (int i = 0; i < 10; i++)
    {
        list_pushBack_size(&l_list, i);
        EXPECT_TRUE(l_list->size == (i + 1));
    }

    for (int i = 9; i >= 0; i--)
    {
        EXPECT_EQ(list_popBack_size(&l_list), i);
        EXPECT_TRUE(l_list->size == i);
    }

    EXPECT_TRUE(l_list->list_node == NULL);
}

TEST_F(llist_test, check_list_free)
{

    for (int i = 0; i < 10; i++)
        list_pushBack(&my_list, i);

    list_free(&my_list);

    EXPECT_TRUE(my_list == NULL);

    list_pushBack(&my_list, 22);
    EXPECT_EQ(list_popBack(&my_list), 22);
}

TEST_F(llist_test, check_pop_back_null)
{

    list_pushBack(&my_list, 100);

    list_popBack(&my_list);

    EXPECT_TRUE(my_list == NULL);
}

TEST_F(llist_test, check_list_to_array)
{
    int arr[10];

    for (int i = 0; i < 10; i++)
        list_pushBack(&my_list, i);

    list_to_array(my_list, arr);

    for (int i = 9; i >= 0; i--)
        EXPECT_EQ(list_popBack(&my_list), arr[i]);
}

TEST_F(llist_test, check_size_based_list)
{
    list *mylst;
    for (int i = 0; i < 10; i++)
        list_pushBack_size(&mylst, i);

    EXPECT_TRUE(mylst->size == 10);
}