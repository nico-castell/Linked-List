# A linked list
<!-- #region Shields -->
[![Lines of code](https://img.shields.io/tokei/lines/github/nico-castell/Linked-List?color=yellow&label=Lines%20of%20code)](https://github.com/nico-castell/Linked-List)
[![GitHub commits since latest release (by date)](https://img.shields.io/github/commits-since/nico-castell/Linked-List/latest?color=yellow&label=Commits%20since%20last%20release)](https://github.com/nico-castell/Linked-List/commits)
[![GitHub](https://img.shields.io/github/license/nico-castell/Linked-List?color=yellow&label=License)](LICENSE)
<!-- #endregion -->

Linked lists have a reputation for being slow, but I believe that their structure is really cool. So I created my own.

**Warning**: This is only a sample, I don't recommend using it in production.

## The structure

This **templetized** list is structured in nodes:

Node:
- **Data**: Information to store.
- **Next**: A pointer to the next node.
- **Prev**: a pointer to the previous node.

The list itself will keep 3 pointers and one int:
- node* **n**: A pointer to create new nodes
- node* **t**: A pointer to the tail
- node* **h**: A pointer to the head
- int **size**: Every time nodes are created or deleted, this value is updated to track the size of the list.

## The methods

There are many common methods this class implements. Here's a brief description by category of them.

### Head and tail:

These methods work with the always known pointers to the head and tail.
- **Append**(data): Adds data to the tail. *Big O(1)*.
- **PopBack**(): Deletes data from the tail. *Big O(1)*.
- **AddHead**(data): Replaces the head and points it to the old head. *Big O(1)*.
- **PopHead**(): Points the head to the 2nd node and delets the old head. *Big O(1)*

### The "middle" of the list:

These methods must each find the node at an index, which is a slow operation.
- **Add**(index,data): Adds data at an index in the list. *Big O(n)*.
- **Delete**(index): Deletes a certain index *Big O(n)*.
- **operator []**: Gets the data of a node at a certain index. *Big O(n)*

**Note:** The "middle of the list" methods use a private method to find a node by its index. This method will exit if an **out of range exception** happens.
**Note 2:** The "Add", "Delete" and "Pop" methods use a private method to handle deleting the only node in the list.

### Auxiliary methods:

- **Size**(): Get the size of the array. There's no way to set it manually. *Big O(1)*.
- **DumpToVector**(vector&): This method will push back all of the data into the vector. But before pushing, it will reserve enough space in the vector to be able to dump everything *without* trigerring resizing. *Big O(n)*.
- **DumpToVector**(vector&, from, to): This method will push back a specific range of data from the head to the tail of the list into a vector. *Big O(n)*.

## The Queue and the Stack

Additionally I used the basic structure of a linked list to make a queue and a stack.

### Queue

You add data from the front to the back. You get data from the front.

This queue implements the methods:
- **Enqueue**(data): Add data to the back. *Big O(1)*.
- **Dequeue**(): Get and delete the data at the front. *Big O(1)*.
- **Peek**(): Get the data at the front without deleting it. *Big O(1)*.
- **operator []**: Peek data behind the front. *Big O(n)*.
- **Size**(): Get the number of elements in the queue. *Big O(1)*.

### Stack

You add data from the bottom to the top. You get data from the top.

This stack implements the methods:
- **Push**(data): Add data to the top. *Big O(1)*.
- **Pop**(): Get and delete the data at the top. *Big O(1)*.
- **Peek**(): Get the data at the top without deleting it. *Big O(1)*.
- **operator []**: Peek data behind the top. *Big O(n)*.
- **Size**(): Get the number of elements in the stack. *Big O(1)*.

## License

This repository is available under the [MIT License](LICENSE).

> Live long, and prosper.  
> Spock
