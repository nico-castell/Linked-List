#include "lkstack-tests.h"
#include <iostream>
#include <lkstack.h>

void TestStack()
{
    std::cout << "\n\nTesting Stack:\n";
    std::cout << "Adding data:\n";

    Stack<int> my_stack;

    // Testing edge cases when the stack is emptied
    my_stack.Push(5);
    my_stack.Pop();

    // Fill up the stack
    for (int i = 5; i < 41; i += 5)
        my_stack.Push(i);

    std::cout << "Popping:\n";
    for (int i = 5; i < 11; i += 5)
        std::cout << my_stack.Pop() << '\n';

    std::cout << "Peeking:\n";
    for (int i = 5; i < 11; i += 5)
        std::cout << my_stack.Peek() << '\n';

    std::cout << "Size: " << my_stack.Size() << '\n';

    std::cout << "Index 1:  " << my_stack[1] << '\n';
    std::cout << "Index -2: " << my_stack[-2] << '\n';
}
