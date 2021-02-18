#pragma once
#include <iostream>

template <class T>
class Stack
{
private:
    struct node
    {
        T data;
        node* prev = NULL;
        node* next = NULL;
    };
    node* n = NULL;  // New node
    node* t = NULL;  // Tail
    node* h = NULL;  // Head
    int size = 0;    // Size of the stack

    /// @brief Generate a new node, if it's the first node, also point 't' and 'h' to it.
    /// @return node* A pointer to the new node
    node* gen_node();
    /// @brief Delete the only node of the stack and set control pointers to NULL.
    void delete_only_node();

public:
    /// @brief Give back all the memory when deleting the stack.
    ~Stack() { Clear(); }
    /// @brief Delete all the elements of the stack.
    void Clear();

    /// @brief Add data to the top of the stack.
    /// @param data The data you want to add
    void Push(const T& data);
    /// @brief Read data from the top of the stack and delete it.
    /// @return The data at the top of the stack
    T Pop();
    /// @brief Read data from the top of the stack without deleting it.
    /// @return The data at the top of the stack
    T Peek() { return t->data; }

    /// @brief Get the size of the stack.
    /// @return int
    int Size() { return size; }
    /// @brief Peek elements in the stack. Big-O(size)
    /// @param index Peek from the top of the stack, negatives peek from the bottom. Top = 0, Bottom = -1;
    /// @return The data stored at the index specified
    T operator[](const int& index);
};

template <class T>
typename Stack<T>::node* Stack<T>::gen_node()
{
    node* r = NULL;  // Result
    if (h == NULL && t == NULL && n == NULL)
        r = h = t = new node();
    else
        r = new node();
    return r;
}

template <class T>
void Stack<T>::delete_only_node()
{
    if (size == 0)  // Do nothinf if the list is empty
        return;
    delete h;  // Delete Head which is also the only node
    h = t = n = NULL;
    size--;
}

template <class T>
void Stack<T>::Clear()
{
    node* c = h;       // Control pointer
    h = t = n = NULL;  // Point control pointers to NULL
    while (size > 0)
    {
        node* _c = c->next;  // Keep a pointer to the next node
        delete c;            // Delete current node
        c = _c;              // Point to the next node
        size--;              // Update size
    }
}

template <class T>
void Stack<T>::Push(const T& data)
{
    n = gen_node();   // Create a new node
    n->data = data;   // Fill the new node's data
    if (n != h)       // If it's not the Head node
        n->prev = t;  //   Point the new node's prev to the Tail
    if (n != t)       // If it's not the Tail node
        t->next = n;  //   Pint Tail's next to the new node
    t = n;            // Point tail to the new node
    size++;           // Update size
}

template <class T>
T Stack<T>::Pop()
{
    try
    {
        if (size == 0)
            throw std::out_of_range("Tried to get data when the stack was empty");
        T content = t->data;
        if (size < 2)
        {
            delete_only_node();  // Call correct method
            return content;      // Return the data
        }
        node* bn = t->prev;  // Keep a pointer to the node before
        bn->next = NULL;     // Point the node before's next to NULL
        delete t;            // Delete the Tail
        t = bn;              // Point Tail to the node before
        size--;              // Update size
        return content;      // Update size
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(1);
    }
}

template <class T>
T Stack<T>::operator[](const int& index)
{
    node* c = t;          // Point control to Tail by default
    bool reverse = true;  // Reverse by default
    if (index < 0)
    {
        c = h;            // Point control to Head
        reverse = false;  // Go forward
    }

    try
    {
        if (index > (size - 1) && !(index < -size) && index != 0)  // Tried to access an index out of range
            throw std::out_of_range("Tried to peek an index out of range");
        if (reverse)
            for (int i = 0; i < index; i++)  // When reversing start from the Tail and go to the prev node until we've
                c = c->prev;                 //   done all the operations
        else
            for (int i = -1; i > index; i--)  // When going forward start from the Head and go to the next node until
                c = c->next;                  //   we've done all the operations
        return c->data;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(1);
    }
}
