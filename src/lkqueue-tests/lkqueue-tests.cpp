#include "lkqueue-tests.h"
#include <iostream>
#include <lkqueue.h>

void TestQueue()
{
    std::cout << "\n\nTesting Queue:\n";
    std::cout << "Adding data:\n";

    Queue<int> my_queue;

    // Testing adge cases when the queue is emptied
    my_queue.Enqueue(5);
    my_queue.Dequeue();

    // Fill up the queue
    for (int i = 5; i < 41; i += 5)
        my_queue.Enqueue(i);

    std::cout << "Dequeing:\n";
    for (int i = 5; i < 11; i += 5)
        std::cout << my_queue.Dequeue() << '\n';

    std::cout << "Peeking:\n";
    for (int i = 5; i < 11; i += 5)
        std::cout << my_queue.Peek() << '\n';

    std::cout << "Size: " << my_queue.Size() << '\n';

    std::cout << "Index 1:  " << my_queue[1] << '\n';
    std::cout << "Index -1: " << my_queue[-2] << '\n';
}
