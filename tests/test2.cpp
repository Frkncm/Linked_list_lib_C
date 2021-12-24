#include <gtest/gtest.h>
extern "C"
{
#include "linked_list.h"
}

struct llist_test2 : public ::testing::Test
{
    void SetUp() override
    {
        
    }
    void TearDown() override
    {
    }
};

TEST_F(llist_test2, test_pop_front)
{
    CREATE_LIST(l_list);

    for (int i = 0; i < 10; i++)
        list_pushBack(&l_list, i);

    for (int i = 0; i < 10; i++)
        EXPECT_EQ(list_popFront(&l_list->list_node), i);

    list_free(&l_list);
}