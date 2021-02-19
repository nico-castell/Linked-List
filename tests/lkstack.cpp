#include <gtest/gtest.h>
#include <lkstack.h>

class LinkedStackTests : public testing::Test
{
protected:
    Stack<int> lkStack;
    LinkedStackTests()
    {
        for (int i = 5; i < 41; i += 5)
            lkStack.Push(i);
    }
};

TEST_F(LinkedStackTests, Popping)
{
    try
    {
        for (int i = 1; i <= 8; i++)
        {
            EXPECT_EQ(45 - (i * 5), lkStack.Pop());
            EXPECT_EQ(8 - i, lkStack.Size());
        }
        ASSERT_EQ(0, lkStack.Size());
    }
    catch (const std::exception& e)
    {
        FAIL() << e.what();
    }
}

TEST_F(LinkedStackTests, Peeking)
{
    try
    {
        for (int i = 0; i < 8; i++)
        {
            EXPECT_EQ(40, lkStack.Peek());
            EXPECT_EQ(8, lkStack.Size());
        }
        ASSERT_EQ(8, lkStack.Size());
    }
    catch (const std::exception& e)
    {
        FAIL() << e.what();
    }
}

TEST_F(LinkedStackTests, PeekingBehind)
{
    try
    {
        EXPECT_EQ(35, lkStack[1]);
        EXPECT_EQ(10, lkStack[-2]);
    }
    catch (const std::exception& e)
    {
        FAIL() << e.what();
    }
}

TEST_F(LinkedStackTests, PeekingOutOfRangeShouldFail)
{
    EXPECT_THROW(lkStack[10], std::out_of_range);
    EXPECT_THROW(lkStack[-10], std::out_of_range);
}

TEST(EmptyLinkedStackTests, AccessingEmptyShouldFail)
{
    Stack<int> lkStack;
    EXPECT_THROW(lkStack.Pop(), std::out_of_range);
    EXPECT_THROW(lkStack[0], std::out_of_range);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
