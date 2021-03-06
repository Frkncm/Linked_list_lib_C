#include <gtest/gtest.h>
extern "C"
{
#include "linked_list.h"
}

struct llist_test : public ::testing::Test
{
    CREATE_LIST(l_list);
    void SetUp() override
    {
    }
    void TearDown() override
    {
    }
};

TEST_F(llist_test, is_list_created)
{
    EXPECT_TRUE(l_list == NULL);

    list_free(&l_list);
}

TEST_F(llist_test, pop_back_and_check)
{
    for (int i = 0; i < 10; i++)
        list_pushBack(&l_list, i);

    for (int i = 9; i >= 0; i--)
        EXPECT_EQ(list_popBack(&l_list), i);

    EXPECT_TRUE(l_list->list_node == NULL);

    list_free(&l_list);
}

TEST_F(llist_test, pop_back_and_check_sized)
{
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

    list_pushBack(&l_list, 100);

    list_popBack(&l_list);

    EXPECT_TRUE(l_list->list_node == NULL);

    list_free(&l_list);
}

TEST_F(llist_test, check_list_to_array)
{

    int arr[6];

    for (int i = 0; i < 10; i++)
        list_pushBack(&l_list, i);

    if (list_to_array(l_list, arr, sizeof(arr) / sizeof(arr[0])))
        for (int i = 9; i >= 0; i--)
            EXPECT_EQ(list_popBack(&l_list), arr[i]);

    list_free(&l_list);
}
