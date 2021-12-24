#include <gtest/gtest.h>
extern "C"
{
#include "linked_list.h"
}

struct llist_test : public ::testing::Test
{

    void SetUp() override
    {
    }
    void TearDown() override
    {
    }
};

TEST_F(llist_test, is_list_created)
{
    CREATE_LIST(l_list);
    EXPECT_TRUE(l_list == NULL);
    
    list_free(&l_list);
}

TEST_F(llist_test, pop_back_and_check)
{
    CREATE_LIST(l_list);
    for (int i = 0; i < 10; i++)
        list_pushBack(&l_list, i);

    for (int i = 9; i >= 0; i--)
        EXPECT_EQ(list_popBack(&l_list), i);

    EXPECT_TRUE(l_list->list_node == NULL);

    list_free(&l_list);
}

TEST_F(llist_test, pop_back_and_check_sized)
{
    CREATE_LIST(l_list);
    for (int i = 0; i < 10; i++)
    {
        list_pushBack(&l_list, i);
        EXPECT_TRUE(l_list->size == (i + 1));
    }

    for (int i = 9; i >= 0; i--)
    {
        EXPECT_EQ(list_popBack(&l_list), i);
        EXPECT_TRUE(l_list->size == i);
    }

    EXPECT_TRUE(l_list->list_node == NULL);

    list_free(&l_list);
}

TEST_F(llist_test, check_list_free)
{
    CREATE_LIST(l_list);
    for (int i = 0; i < 10; i++)
        list_pushBack(&l_list, i);

    list_free(&l_list);

    EXPECT_TRUE(l_list == NULL);

    list_pushBack(&l_list, 22);
    EXPECT_EQ(list_popBack(&l_list), 22);

    list_free(&l_list);
}

TEST_F(llist_test, check_pop_back_null)
{
    CREATE_LIST(l_list);

    list_pushBack(&l_list, 100);

    list_popBack(&l_list);

    EXPECT_TRUE(l_list->list_node == NULL);

    list_free(&l_list);
}

TEST_F(llist_test, check_list_to_array)
{
    CREATE_LIST(l_list);

    int arr[10];

    for (int i = 0; i < 10; i++)
        list_pushBack(&l_list, i);

    list_to_array(l_list, arr);

    for (int i = 9; i >= 0; i--)
        EXPECT_EQ(list_popBack(&l_list), arr[i]);

    list_free(&l_list);
}

