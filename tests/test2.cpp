#include <gtest/gtest.h>
extern "C"
{
#include "linked_list.h"
}

struct llist_test2 : public ::testing::Test
{
    CREATE_LIST(l_list);

    void SetUp() override
    {
    }
    void TearDown() override
    {
    }
};

TEST_F(llist_test2, test_pop_front)
{

    for (int i = 0; i < 10; i++)
        list_pushBack(&l_list, i);

    for (int i = 0; i < 10; i++)
        EXPECT_EQ(list_popFront(&l_list), i);

    list_free(&l_list);
}

TEST_F(llist_test2, test_pop_front_null)
{

    list_pushBack(&l_list, 123);

    EXPECT_EQ(list_popFront(&l_list), 123);

    EXPECT_TRUE(list_popFront(&l_list) == -1);

    list_free(&l_list);
}

TEST_F(llist_test2, check_pop_front_list_size)
{
    list_pushBack(&l_list, 5);
    list_pushBack(&l_list, 2);
    list_pushBack(&l_list, 11);

    EXPECT_TRUE(l_list->size == 3);

    list_popBack(&l_list);

    EXPECT_TRUE(l_list->size == 2);
}

TEST_F(llist_test2, check_list_get_index)
{
    list_pushBack(&l_list, 5);
    list_pushBack(&l_list, 2);
    list_pushBack(&l_list, 11);

    EXPECT_EQ(list_get(l_list, 2), 11);
}

TEST_F(llist_test2, check_insert_after_index)
{
    list_pushBack(&l_list, 5);
    list_pushBack(&l_list, 2);
    list_pushBack(&l_list, 11);

    EXPECT_TRUE(list_insertAfterIndex(l_list, 55, 2));

    EXPECT_EQ(list_get(l_list, 3), 55);
}

TEST_F(llist_test2, check_insert_after_index_weirdvalues)
{
    list_pushBack(&l_list, 5);
    list_pushBack(&l_list, 2);
    list_pushBack(&l_list, 11);
    EXPECT_FALSE(list_insertAfterIndex(l_list, 55, 5));

}

TEST_F(llist_test2, check_push_front)
{
    list_pushBack(&l_list, 5);
    list_pushBack(&l_list, 2);
    list_pushBack(&l_list, 11);

    EXPECT_TRUE(list_pushFront(&l_list, 66));

    EXPECT_EQ(list_get(l_list, 0), 66);
    EXPECT_EQ(list_get(l_list, 1), 5);
    EXPECT_EQ(list_get(l_list, 2), 2);
    EXPECT_EQ(list_get(l_list, 3), 11);

    EXPECT_TRUE(list_get(l_list, 5) == -1);

}

TEST_F(llist_test2, check_index_based_read)
{
    list_pushBack(&l_list, 5);
    list_pushBack(&l_list, 2);
    list_pushBack(&l_list, 11);
    list_pushBack(&l_list, 65);
    list_pushBack(&l_list, 12);

    EXPECT_TRUE(list_pushFront(&l_list, 66));

    EXPECT_EQ(list_get(l_list, 5), 12);
    EXPECT_EQ(list_get(l_list, 4), 65);
    EXPECT_EQ(list_get(l_list, 3), 11);
    EXPECT_EQ(list_get(l_list, 2), 2);
    EXPECT_EQ(list_get(l_list, 1), 5);
    EXPECT_EQ(list_get(l_list, 0), 66);

}