#include <gtest/gtest.h>
#include <lklist.h>
#include <vector>

#pragma region Basic testing
class LinkedListTest : public testing::Test
{
protected:
    LinkedList<int> lkList;
};

TEST_F(LinkedListTest, EmptyingList)
{
    for (int i = 5; i < 16; i += 5)
        lkList.Append(i);
    for (int i = 5; i < 16; i += 5)
        lkList.Delete(0);
    EXPECT_EQ(0, lkList.Size());

    for (int i = 5; i < 16; i += 5)
        lkList.Append(i);
    for (int i = 5; i < 16; i += 5)
        lkList.PopBack();
    EXPECT_EQ(0, lkList.Size());

    for (int i = 5; i < 16; i += 5)
        lkList.Append(i);
    for (int i = 5; i < 16; i += 5)
        lkList.PopHead();
    EXPECT_EQ(0, lkList.Size());
}

TEST_F(LinkedListTest, EdgeCasesOnHead)
{
    lkList.AddHead(5);
    EXPECT_EQ(5, lkList[0]);
    lkList.PopHead();
    EXPECT_EQ(0, lkList.Size());

    lkList.Add(0, 5);
    EXPECT_EQ(5, lkList[0]);
    lkList.Delete(0);
    EXPECT_EQ(0, lkList.Size());

    lkList.Append(5);
    EXPECT_EQ(5, lkList[0]);
    lkList.PopBack();
    EXPECT_EQ(0, lkList.Size());
}

TEST_F(LinkedListTest, EdgeCasesOnTail)
{
    lkList.Append(5);
    EXPECT_EQ(5, lkList[0]);
    lkList.PopBack();
    EXPECT_EQ(0, lkList.Size());

    lkList.Add(-1, 5);
    EXPECT_EQ(5, lkList[0]);
    lkList.Delete(-1);
    EXPECT_EQ(0, lkList.Size());
}

TEST_F(LinkedListTest, DeletingEmptyShouldDoNothing)
{
    lkList.PopBack();
    EXPECT_EQ(0, lkList.Size());
    lkList.Delete(0);
    EXPECT_EQ(0, lkList.Size());
    lkList.Delete(-1);
    EXPECT_EQ(0, lkList.Size());
    lkList.PopHead();
    EXPECT_EQ(0, lkList.Size());
}

TEST_F(LinkedListTest, AccessingOutOfRangeShouldFail)
{
    std::vector<int> shouldEndUpEmpty;
    EXPECT_THROW(lkList[0], std::out_of_range);
    EXPECT_THROW(lkList.DumpToVector(shouldEndUpEmpty, 0, 0), std::out_of_range);
}
#pragma endregion

#pragma region Dumping to vector
class LinkedListDumpTest : public testing::Test
{
protected:
    LinkedList<int> lkList;
    std::vector<int> rNumbers;

    LinkedListDumpTest()
    {
        for (int i = 5; i < 41; i += 5)
            lkList.Append(i);
    }
};

// Whole Vector
TEST_F(LinkedListDumpTest, DumpToVector1)
{
    lkList.DumpToVector(rNumbers);

    for (int i = 0; i < 8; i++)
        EXPECT_EQ(rNumbers[i], lkList[i]);
}

// Positive - Forward
TEST_F(LinkedListDumpTest, DumpToVector2)
{
    int from = 2;
    int to = 5;
    int total = abs(to - from) + 1;

    lkList.DumpToVector(rNumbers, from, to);

    ASSERT_EQ(total, rNumbers.size());

    for (int i = 0; i < total; i++)
        EXPECT_EQ(rNumbers[i], lkList[i + from]);
}

// Positive - Reverse
TEST_F(LinkedListDumpTest, DumpToVector3)
{
    int from = 6;
    int to = 2;
    int total = abs(to - from) + 1;

    lkList.DumpToVector(rNumbers, from, to);

    ASSERT_EQ(total, rNumbers.size());

    for (int i = 0; i < total; i++)
        EXPECT_EQ(rNumbers[i], lkList[from - i]);
}

// Negative - Forward
TEST_F(LinkedListDumpTest, DumpToVector4)
{
    int from = -5;
    int to = -2;
    int total = abs(to - from) + 1;

    lkList.DumpToVector(rNumbers, from, to);

    ASSERT_EQ(total, rNumbers.size());

    for (int i = 0; i < total; i++)
        EXPECT_EQ(rNumbers[i], lkList[from + i]);
}

// Negative - Reverse
TEST_F(LinkedListDumpTest, DumpToVector5)
{
    int from = -2;
    int to = -5;
    int total = abs(to - from) + 1;

    lkList.DumpToVector(rNumbers, from, to);

    ASSERT_EQ(total, rNumbers.size());

    for (int i = 0; i < total; i++)
        EXPECT_EQ(rNumbers[i], lkList[from - i]);
}

// Full list, negative - reverse
TEST_F(LinkedListDumpTest, FullDumpToVector1)
{
    int from = -1;
    int to = -9;
    int total = abs(to - from) + 1;

    lkList.DumpToVector(rNumbers, from, to);

    ASSERT_EQ(total, rNumbers.size());

    for (int i = 0; i < total; i++)
        EXPECT_EQ(rNumbers[i], lkList[(from - i) % (total - 1)]);
}

// Full list, negative - forward
TEST_F(LinkedListDumpTest, FullDumpToVector2)
{
    int from = -8;
    int to = -1;
    int total = abs(to - from) + 1;

    lkList.DumpToVector(rNumbers, from, to);

    ASSERT_EQ(total, rNumbers.size());

    for (int i = 0; i < total; i++)
        EXPECT_EQ(rNumbers[i], lkList[from + i]);
}

// Wrap list, negative/positive - forward
TEST_F(LinkedListDumpTest, WrappedDumpToVector1)
{
    int from = -8;
    int to = 1;
    int total = abs(to - from) + 1;

    lkList.DumpToVector(rNumbers, from, to);

    ASSERT_EQ(total, rNumbers.size());

    for (int i = 0; i < total; i++)
        EXPECT_EQ(rNumbers[i], lkList[(from + i) % (total - 1)]);
}

// Wrap list, positive/negative - reverse
TEST_F(LinkedListDumpTest, WrappedDumpToVector2)
{
    int from = 1;
    int to = -8;
    int total = abs(to - from) + 1;

    lkList.DumpToVector(rNumbers, from, to);

    ASSERT_EQ(total, rNumbers.size());

    for (int i = 0; i < total; i++)
        EXPECT_EQ(rNumbers[i], lkList[(from - i) % (total - 1)]);
}

#pragma endregion

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
