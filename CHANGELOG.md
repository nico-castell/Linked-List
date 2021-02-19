# Change log

All significant changes to **Linked Lists** will be documented here

1. [Released](#Released)
1. [Pre Releases](#Pre-Releases)

## Released

### Version [1.0.1](https://github.com/nico-castell/Linked-List/releases/tag/1.0.1) - *2021-02-19*
#### Added
- Unit testing for the **LinkedList\<T\>**, **Queue\<T\>**, and **Stack\<T\>** classes.
- Google Test was configured to be automatically cloned when configuring the project.

#### Removed
- **src** folder containing an entry point for a program wich is no longer required, as we now have unit testing.

### Version [1.0.0](https://github.com/nico-castell/Linked-List/releases/tag/1.0.0) - *2021-02-17*
#### Changed
- Exported Linked List tests to their own *header-implementation* files.
- Now the project uses CMake, meaning it's no longer compatible with the old repository.

#### Fixed
- Edge cases: Adding the first node of the list no longer causes issues. Not even with the **Add()** method.
- Edge cases: Empting the list.

## Pre-Releases

### Version 0.0.2 - *2021-02-15*
#### Added
- Overload to dump a specific range of a linked list to a vector.

#### Changed
- The Queue and Stack now use the better search algorithm from the Linked List.
- Updated the [.clang-format](.clang-format).

#### Fixed
- Now the **Add()** and **Delete()** methods have 2 edge-cases when the index is either the Tail or the Head.

### Version 0.0.1 - *2021-02-13*
#### Added
- Sample of a **Linked List**.
- Sample of a **Queue**.
- Sample of a **Stack**.
