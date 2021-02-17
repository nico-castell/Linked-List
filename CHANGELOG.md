# Change log

All significant changes to **Linked Lists** will be documented here

1. [Unreleased](#Unreleased)
1. [Pre Releases](#Pre-Releases)

## Unreleased
### Changed
- Exported Linked List tests to their own *header-implementation* files.
- Now the project uses CMake, meaning it's no longer compatible with the old repository.

### Fixed
- Edge cases: Adding the first node of the list no longer causes issues. Not even with the **Add()** method.
- Edge cases: Empting the list.

### Version 0.0.2 - *2021-02-15*
#### Added
- Overload to dump a specific range of a linked list to a vector.

#### Changed
- The Queue and Stack now use the better search algorithm from the Linked List.
- Updated the [.clang-format](.clang-format).

#### Fixed
- Now the **Add()** and **Delete()** methods have 2 edge-cases when the index is either the Tail or the Head.

## Pre-Releases

### Version [0.0.1](https://github.com/nico-castell/Linked-List/releases/tag/0.0.1) - *2021-02-13*
#### Added
- Sample of a **Linked List**.
- Sample of a **Queue**.
- Sample of a **Stack**.
