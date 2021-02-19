#pragma once
#include <iostream>

template <class T>
class Queue
{
private:
    struct node
    {
        T data;
        node* next = NULL;
        node* prev = NULL;
    };
    node* n = NULL;  // New node
    node* t = NULL;  // Tail
    node* h = NULL;  // Head
    int size = 0;    // Size of the queue

    /// @brief Generate a new node, if it's the fist node, also point 't' and 'h' to it.
    /// @return node* A pointer to the new node.
    node* gen_node();
    /// @brief Delete the only node of the list and set control pointers to NULL.
    void delete_only_node();

public:
    /// @brief Give back all the memory when deleting the list.
    ~Queue() { Clear(); }
    /// @brief Delete all the elements of the list
    void Clear();

    /// @brief Add data to the back of the queue.
    /// @param data The data you want to add
    void Enqueue(const T& data);
    /// @brief Read data from the front of the queue and delete it.
    /// @return The data at the front of the queue
    T Dequeue();
    /// @brief Read data from the front of the queue without deleting it.
    /// @return The data at the front of the queue
    T Peek() { return h->data; }

    /// @brief Get the size of the list
    /// @return int
    int Size() { return size; }
    /// @brief Peek elements behind the front of the queue. Big-O(size)
    /// @param index Peek from the front to the tail, negatives peek from the tail to the head. Head = 0, Tail = -1.
    /// @return The data stored at the index specified
    T operator[](const int& index);
};

template <class T>
typename Queue<T>::node* Queue<T>::gen_node()
{
    node* r = NULL;  // Result
    if (h == NULL && t == NULL && n == NULL)
        r = h = t = new node();
    else
        r = new node();
    return r;
}

template <class T>
void Queue<T>::delete_only_node()
{
    if (size == 0)  // Do nothing if the list is empty
        return;
    delete h;          // Delte Head which is also the only node
    h = t = n = NULL;  // Reset control pointers
    size--;
}

template <class T>
void Queue<T>::Clear()
{
    node* c = h;       // Keep a control pointer
    h = t = n = NULL;  // Point all control pointers to NULL
    while (size > 0)
    {
        node* _c = c->next;  // Keep a pointer to the next node
        delete c;            // Delete current node
        c = _c;              // Point to the next node
        size--;              // Update size
    }
}

template <class T>
void Queue<T>::Enqueue(const T& data)
{
    n = gen_node();   // Create a new node
    n->data = data;   // Fill the new node's data
    if (n != h)       // If it's not the Head node
        n->prev = t;  //   Point the new node's prev to the Tail
    if (n != t)       // If it's not the Tail node
        t->next = n;  //   Point tail's next to the new node
    t = n;            // Point tail to the new node
    size++;           // Update size
}

template <class T>
T Queue<T>::Dequeue()
{
    if (size == 0)
        throw std::out_of_range("Tried to get data when the queue was empty");

    T content = h->data;
    if (size < 2)
    {
        delete_only_node();  // Call correct method.
        return content;      // Return the data
    }

    node* ah = h->next;  // Keep a pointer to the node after
    ah->prev = NULL;     // Point after's prev to NULL
    delete h;            // Delete Head
    h = ah;              // Point Head to the node after
    size--;              // Update size
    return content;      // Return the data
}

template <class T>
T Queue<T>::operator[](const int& index)
{
    node* c = h;           // Point control to Head by default
    bool reverse = false;  // Go forward by default
    if (index < 0)
    {
        c = t;           // Point control to tail
        reverse = true;  // Reverse
    }

    // if (index > (size - 1) && !(index < -size) && index != 0)  // Tried to access an index out of range
    if ((index + 1) > size || index < -size)  // Tried to access an index out of range
        throw std::out_of_range("Tried to peek an index out of range");

    if (reverse)
        for (int i = -1; i > index; i--)  // When reversing start from the Tail and go the the prev node until we've
            c = c->prev;                  //   done all the operations
    else
        for (int i = 0; i < index; i++)  // When going forward start from the Head and go to the next node until
            c = c->next;                 //   we've done all the operations

    return c->data;
}
