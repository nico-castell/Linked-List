#include "lklist-tests.h"
#include <iostream>
#include <lklist.h>
#include <vector>

template <typename T>
void PrintVector(const std::vector<T>& vec)
{
    for (auto& v : vec)
        std::cout << v << "  ";
    std::cout << "\n";
}

void TestLinkedList()
{
    std::cout << "Testing linked list:\n";
    std::cout << "Adding data:\n";
    LinkedList<int> my_list;

    // Testing edge cases when the list is emptied.
    my_list.Add(0, 5);
    my_list.Delete(0);
    my_list.Append(5);
    my_list.PopBack();
    my_list.Append(5);
    my_list.PopHead();

    // Testing when the list is emptied but it had more than one node.
    for (int i = 5; i < 11; i += 5)
        my_list.Append(i);
    for (int i = 5; i < 11; i += 5)
        my_list.PopBack();

    // Fill up the list.
    for (int i = 5; i < 41; i += 5)
        my_list.Append(i);

    // Testing edge cases involving the Head
    my_list.PopHead();
    my_list.AddHead(5);
    my_list.Delete(0);
    my_list.AddHead(5);
    my_list.PopHead();
    my_list.Add(0, 5);

    // Tesing edge cases involving the Tail
    my_list.PopBack();
    my_list.Append(40);
    my_list.Delete(-1);
    my_list.Append(40);
    my_list.PopBack();
    my_list.Add(-1, 40);

    // Add data in the middle
    my_list.Add((my_list.Size() / 2), 400);

    // Dump the list to the console
    std::cout << "\nDumping list:\n";
    for (int i = 0; i < my_list.Size(); i++)
        std::cout << my_list[i] << "  ";
    std::cout << "\n";

    for (int i = -1; i > -(my_list.Size() + 1); i--)
        std::cout << my_list[i] << "  ";
    std::cout << "\n";

    // Dumping list to vector
    std::cout << "\nDumping list to vector:\n";
    std::cout << "0  1   2   3   4    5   6   7   8\n";
    std::vector<int> numbers;
    my_list.DumpToVector(numbers);
    PrintVector(numbers);

    std::vector<int> rNumbers1;
    my_list.DumpToVector(rNumbers1, 2, 5);  // Positive - Forward
    std::cout << "2 to 5:  \t";
    PrintVector(rNumbers1);

    std::vector<int> rNumbers2;
    my_list.DumpToVector(rNumbers2, 6, 2);  // Positive - Reverse
    std::cout << "6 to 2:  \t";
    PrintVector(rNumbers2);

    std::vector<int> rNumbers3;
    my_list.DumpToVector(rNumbers3, -5, -2);  // Negative - Forward
    std::cout << "-5 to -2:\t";
    PrintVector(rNumbers3);

    std::vector<int> rNumbers4;
    my_list.DumpToVector(rNumbers4, -2, -5);  // Negative - Reverse
    std::cout << "-2 to -5:\t";
    PrintVector(rNumbers4);

    std::vector<int> rNumbers5;
    my_list.DumpToVector(rNumbers5, -1, -9);
    std::cout << "-1 to -9:\t";
    PrintVector(rNumbers5);

    std::vector<int> rNumbers6;
    my_list.DumpToVector(rNumbers6, -9, -1);
    std::cout << "-9 to -1:\t";
    PrintVector(rNumbers6);

    std::vector<int> rNumbers7;
    my_list.DumpToVector(rNumbers7, -9, 1);
    std::cout << "-9 to 1: \t";
    PrintVector(rNumbers7);

    std::vector<int> rNumbers8;
    my_list.DumpToVector(rNumbers8, 1, -9);
    std::cout << "1 to -9: \t";
    PrintVector(rNumbers8);
}
