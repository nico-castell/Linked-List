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

TEST_F(LinkedListTest, EdgeCasesOnHeadShouldFail)
{
    try
    {
        lkList.PopBack();
    }
    catch (const std::exception& e)
    {
        ASSERT_STREQ("Tried to access an index out of range", e.what());
    }
}
#pragma endregion

#pragma region Dumping to vector
// Whole Vector
TEST(LinkedListDumpTest, DumpToVector1)
{
    LinkedList<int> lkList;
    for (int i = 5; i < 41; i += 5)
        lkList.Append(i);

    std::vector<int> rNumbers(8);
    rNumbers.clear();
    lkList.DumpToVector(rNumbers);

    for (int i = 0; i < 8; i++)
        EXPECT_EQ(rNumbers[i], lkList[i]);
}

// Positive - Forward
TEST(LinkedListDumpTest, DumpToVector2)
{
    LinkedList<int> lkList;
    for (int i = 5; i < 41; i += 5)
        lkList.Append(i);

    int from = 2;
    int to = 5;
    int total = 4;
    std::vector<int> rNumbers(total);
    rNumbers.clear();

    lkList.DumpToVector(rNumbers, from, to);

    ASSERT_EQ(total, rNumbers.size());

    for (int i = 0; i < total; i++)
        EXPECT_EQ(rNumbers[i], lkList[i + from]);
}

// Positive - Reverse
TEST(LinkedListDumpTest, DumpToVector3)
{
    LinkedList<int> lkList;
    for (int i = 5; i < 41; i += 5)
        lkList.Append(i);

    int from = 6;
    int to = 2;
    int total = 5;
    std::vector<int> rNumbers(total);
    rNumbers.clear();

    lkList.DumpToVector(rNumbers, from, to);

    ASSERT_EQ(total, rNumbers.size());

    for (int i = 0; i < total; i++)
        EXPECT_EQ(rNumbers[i], lkList[from - i]);
}

// Negative - Forward
TEST(LinkedListDumpTest, DumpToVector4)
{
    LinkedList<int> lkList;
    for (int i = 5; i < 41; i += 5)
        lkList.Append(i);

    int from = -5;
    int to = -2;
    int total = 4;
    std::vector<int> rNumbers(total);
    rNumbers.clear();

    lkList.DumpToVector(rNumbers, from, to);

    ASSERT_EQ(total, rNumbers.size());

    for (int i = 0; i < total; i++)
        EXPECT_EQ(rNumbers[i], lkList[from + i]);
}

// Negative - Reverse
TEST(LinkedListDumpTest, DumpToVector5)
{
    LinkedList<int> lkList;
    for (int i = 5; i < 41; i += 5)
        lkList.Append(i);

    int from = -2;
    int to = -5;
    int total = 4;
    std::vector<int> rNumbers(total);
    rNumbers.clear();

    lkList.DumpToVector(rNumbers, from, to);

    ASSERT_EQ(total, rNumbers.size());

    for (int i = 0; i < total; i++)
        EXPECT_EQ(rNumbers[i], lkList[from - i]);
}

// Full list, negative - reverse
TEST(LinkedListDumpTest, FullDumpToVector1)
{
    LinkedList<int> lkList;
    for (int i = 5; i < 41; i += 5)
        lkList.Append(i);

    int from = -1;
    int to = -9;
    int total = 9;
    std::vector<int> rNumbers(total);
    rNumbers.clear();

    lkList.DumpToVector(rNumbers, from, to);

    ASSERT_EQ(total, rNumbers.size());

    for (int i = 0; i < total; i++)
        EXPECT_EQ(rNumbers[i], lkList[(from - i) % (total - 1)]);
}

// FIXME: Out of range exceptions
// Full list, negative - forward
TEST(LinkedListDumpTest, FullDumpToVector2)
{
    LinkedList<int> lkList;
    for (int i = 5; i < 41; i += 5)
        lkList.Append(i);

    int from = -9;
    int to = -1;
    int total = 9;
    std::vector<int> rNumbers(total);
    rNumbers.clear();

    lkList.DumpToVector(rNumbers, from, to);

    ASSERT_EQ(total, rNumbers.size());

    for (int i = 0; i < total; i++)
        EXPECT_EQ(rNumbers[i], lkList[(from - i) % (total - 1)]);
}

// Wrap list, negative/positive - forward
TEST(LinkedListDumpTest, WrappedDumpToVector)
{
    LinkedList<int> lkList;
    for (int i = 5; i < 41; i += 5)
        lkList.Append(i);

    int from = -9;
    int to = 1;
    int total = 10;
    std::vector<int> rNumbers(total);
    rNumbers.clear();

    lkList.DumpToVector(rNumbers, from, to);

    ASSERT_EQ(total, rNumbers.size());

    for (int i = 0; i < total; i++)
        EXPECT_EQ(rNumbers[i], lkList[(from + i) % (total - 1)]);
}

// Wrap list, positive/negative - reverse

#pragma endregion

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
