#include <gtest/gtest.h>
#include <lkqueue.h>

class LinkedQueueTests : public testing::Test
{
protected:
    Queue<int> lkQueue;
    LinkedQueueTests()
    {
        for (int i = 5; i < 41; i += 5)
            lkQueue.Enqueue(i);
    }
};

TEST_F(LinkedQueueTests, Dequeueing)
{
    try
    {
        for (int i = 1; i <= 8; i++)
        {
            EXPECT_EQ(i * 5, lkQueue.Dequeue());
            EXPECT_EQ(8 - i, lkQueue.Size());
        }
        ASSERT_EQ(0, lkQueue.Size());
    }
    catch (const std::exception& e)
    {
        FAIL() << e.what();
    }
}

TEST_F(LinkedQueueTests, Peeking)
{
    try
    {
        for (int i = 0; i < 8; i++)
        {
            EXPECT_EQ(5, lkQueue.Peek());
            EXPECT_EQ(8, lkQueue.Size());
        }
        ASSERT_EQ(8, lkQueue.Size());
    }
    catch (const std::exception& e)
    {
        FAIL() << e.what();
    }
}

TEST_F(LinkedQueueTests, PeekingBehind)
{
    try
    {
        EXPECT_EQ(10, lkQueue[1]);
        EXPECT_EQ(35, lkQueue[-2]);
    }
    catch (const std::exception& e)
    {
        FAIL() << e.what();
    }
}

TEST_F(LinkedQueueTests, PeekingOutOfRangeShouldFail)
{
    EXPECT_THROW(lkQueue[10], std::out_of_range);
    EXPECT_THROW(lkQueue[-10], std::out_of_range);
}

TEST(EmptyLinkedQueueTests, AccessingEmptyShouldFail)
{
    Queue<int> lkQueue;
    EXPECT_THROW(lkQueue.Dequeue(), std::out_of_range);
    EXPECT_THROW(lkQueue[0], std::out_of_range);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
