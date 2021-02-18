#pragma once
#include <iostream>
#include <vector>

template <class T>
class LinkedList
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
    int size = 0;    // Size of the list

    /// @brief Generate a new node, if it's the first node, also point 't' and 'h' to it.
    /// @return node* A node pointer to the new node
    node* gen_node();
    /// @brief Find a node as indicated by the index.
    /// @param index Find from head, negatives find from tail. Head = 0, Tail = -1
    /// @return node* A pointer to the node in that index
    node* find_node(const int& index);
    /// @brief Delete the only node of the list ans set control pointers to NULL.
    void delete_only_node();

public:
    /// @brief Give back all the memory when deleting the list.
    ~LinkedList() { Clear(); }

    /// @brief Delete all the elements of the list.
    void Clear();

    /// @brief Add data to the tail.
    /// @param data The data you want to add
    void Append(const T& data);
    /// @brief Delete the data at the tail.
    void PopBack();

    /// @brief Add data to the head, and start the list from there.
    /// @param data The data you want to add
    void AddHead(const T& data);
    /// @brief Delete the data at the head, start the list from the data after.
    void PopHead();

    /// @brief Add data at some index. Big O(size)
    /// @param index Where you want the new data to be
    /// @param data The data you want to add
    void Add(const int& index, const T& data);
    /// @brief Delete the data at some index, continue the list after that. Big O(size)
    /// @param index The index to delete
    void Delete(const int& index);

    /// @brief Get the data stored at some index. Big O(size)
    /// @param index Find from head, negatives find from tail. Head = 0, Tail = -1
    /// @return The data at some index
    T operator[](const int& index) { return find_node(index)->data; }

    /// @brief Get the size of the list.
    /// @return int
    int Size() { return size; }
    /// @brief Push back all the data to a vector.
    /// @param destination The destination vector
    void DumpToVector(std::vector<T>& destination);
    /// @brief Push back a range of the data into a vector
    /// @param destination The destination vector
    /// @param from The index from where to start. (inclusive)
    /// @param to The index at which to stop. (inclusive)
    void DumpToVector(std::vector<T>& destination, const int& from, const int& to);
};

template <class T>
void LinkedList<T>::Clear()
{
    node* c = h;
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
typename LinkedList<T>::node* LinkedList<T>::gen_node()
{
    node* r = NULL;  // Result
    if (h == NULL && t == NULL && n == NULL)
        r = h = t = new node();
    else
        r = new node();
    return r;
}

template <class T>
typename LinkedList<T>::node* LinkedList<T>::find_node(const int& index)
{
    node* c = h;           // Point control to head by default
    bool reverse = false;  // No reverse by default
    if (index < 0)
    {
        c = t;           // Point control to tail
        reverse = true;  // Reverse
    }

    if (index > (size - 1) && !(index < -size) && index != 0)  // Tried to access an index out of range
        throw std::out_of_range("Tried to access an index out of range");

    if (reverse)
        for (int i = -1; i > index; i--)  // When reversing start from the tail and go to the prev node until we've
            c = c->prev;                  //   done all the operations
    else
        for (int i = 0; i < index; i++)  // When going forward start from the head and go to the next node until
            c = c->next;                 //   we've done all the operations
    return c;
}

template <class T>
void LinkedList<T>::delete_only_node()
{
    if (size == 0)  // Do nothing if the list is empty
        return;
    delete h;          // Delete the head which is also the only node
    h = t = n = NULL;  // Reset the control pointers
    size--;
}

template <class T>
void LinkedList<T>::Append(const T& data)
{
    n = gen_node();   // Create a new node
    n->data = data;   // Fill the new node's data
    if (n != h)       // Hande edge case
        n->prev = t;  // Point the new node's prev to the Tail
    t->next = n;      // Point tail's next to the new node
    t = n;            // Point tail to the new node
    size++;           // Update size
}

template <class T>
void LinkedList<T>::PopBack()
{
    if (size < 2)  // Handle edge case
    {
        delete_only_node();  // By calling the correct method.
        return;
    }
    node* bt = t->prev;  // Keep a pointer to the node before
    bt->next = NULL;     // Point before's next to NULL
    delete t;            // Delete the tail
    t = bt;              // Point tail to the node before
    size--;              // Update size
}

template <class T>
void LinkedList<T>::AddHead(const T& data)
{
    n = gen_node();  // Create a new node
    n->data = data;  // Fill the new node's data
    n->next = h;     // Point the new node's next to Head
    h->prev = n;     // Point Head's prev to the new node
    h = n;           // Point Head to the new node
    n = t;           // Return n to Tail
    size++;          // Update size
}

template <class T>
void LinkedList<T>::PopHead()
{
    if (size < 2)  // Handle edge case
    {
        delete_only_node();  // by calling the correct method.
        return;
    }
    node* ah = h->next;  // Keep a pointer to the node after
    ah->prev = NULL;     // Point after's prev to NULL
    delete h;            // Delete head
    h = ah;              // Point head to the node after
    size--;              // Update size
}

template <class T>
void LinkedList<T>::Add(const int& index, const T& data)
{
    node* tn = find_node(index);  // Find this node
    if (tn == h)                  // This node is the head
    {
        AddHead(data);  // Call correct method
        return;         // Exit this method
    }
    else if (tn == t)
    {
        Append(data);  // Call correct method
        return;        // Exit this method
    }
    n = gen_node();       // Create a new node
    n->data = data;       // Fill the new node's data
    node* bn = tn->prev;  // Get the node before the new index
    bn->next = n;         // Point the node before's next to the new node
    n->prev = bn;         // Point the new node's prev to the node before
    n->next = tn;         // Point the new node's next to the new node
    tn->prev = n;         // Point this node's prev to the new node
    n = t;                // Return n to the Tail
    size++;               // Update size
}

template <class T>
void LinkedList<T>::Delete(const int& index)
{
    if (size < 2)  // Handle edge case
    {
        delete_only_node();  // by calling the correct method
        return;
    }
    node* tn = find_node(index);  // Keep a pointer to this node
    if (tn == t)
    {
        PopBack();  // Call correct method
        return;
    }
    else if (tn == h)
    {
        PopHead();  // Call correct method
        return;
    }
    node* bn = tn->prev;  // Keep a pointer to the node after
    node* an = tn->next;  // Keep a pointer to the node after the one we delete
    bn->next = an;        // Point the node before's next to the node after
    an->prev = bn;        // Point the node after's prev to the node before
    delete tn;            // Delete the node requested
    size--;               // Update size
}

template <class T>
void LinkedList<T>::DumpToVector(std::vector<T>& destination)
{
    if ((destination.capacity() - destination.size()) < size)  // Make sure the vector has enough capaciry to hold the
        destination.reserve(destination.size() + size);        //   list without triggering rezising
    node* c = h;
    for (int i = 0; i < size; i++)
    {
        destination.push_back(c->data);
        c = c->next;
    }
}

template <class T>
void LinkedList<T>::DumpToVector(std::vector<T>& destination, const int& from, const int& to)
{
    int range = abs(to - from) + 1;
    if ((destination.capacity() - destination.size()) < range)  // Make sure the vector has enough capacity to hold the
        destination.reserve(destination.size() + range);        //   list without triggering rezising.
    node* c = find_node(from);
    bool reverse = false;  // Default to forward direction
    if (to < from)         // Or go backwards
        reverse = true;

    if (reverse)  // Go backwards
        for (int i = to; i <= from; i++)
        {
            destination.push_back(c->data);
            c = c->prev;
            if (c == NULL)  // This node is the head
                c = t;
        }
    else  // Go forward
        for (int i = from; i <= to; i++)
        {
            destination.push_back(c->data);
            c = c->next;
            if (c == NULL)  // This node is the tail
                c = h;
        }
}
