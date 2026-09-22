# CS1D Assignment 4 - Binary Trees

This project implements a binary search tree from the assignment requirements shown in the PDF image.

## Assignment summary

Implement a binary tree using an array, a vector, or a linked list. Duplicates are allowed in a binary tree.

Store the following values using the properties of a binary search tree:

49, 9, 59, 288, 19, 13, 888, 77, 25, 109, 55, 118, 89, 33, 1001, 18, 44, 88, 12, 24

Then:
- perform in-order traversal
- perform post-order traversal
- perform pre-order traversal
- perform breadth-first traversal
- print the tree by level
- display parent-child relationships for all nodes

## Project structure

- main.cpp - program entry point and assignment output
- BinarySearchTree.h - BST node and class declarations
- BinarySearchTree.cpp - BST logic and traversal implementations

## Build and run

If you have a C++ compiler installed, compile from the project folder with:

```bash
g++ main.cpp BinarySearchTree.cpp -std=c++17 -Wall -Wextra -pedantic -o bst_assignment
./bst_assignment
```

On Windows using MinGW, the command would be similar to:

```bash
g++ main.cpp BinarySearchTree.cpp -std=c++17 -Wall -Wextra -pedantic -o bst_assignment.exe
bst_assignment.exe
```

## Notes

The BST inserts each value using the usual binary search rule:
- smaller values go to the left
- larger values go to the right

This makes all required traversals and tree-level printing work naturally.
