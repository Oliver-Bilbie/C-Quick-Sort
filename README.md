# Quick-Sort

This directory contains a C implementation of the quick-sort algorithm.

---

## Background

Quick-sort is a sorting algorithm with $Θ(n^2)$ complexity, which is renowned for having a small constant factor
which makes it faster than the complexity alone suggests.

It is a divide-and-conquer algorithm which follows the following steps:

1. Select an element in the list to be labelled as the _pivot_.
    - In this implementation I have chosen the first element in the list.
2. Split the remaining elements into two sub-arrays depending on whether their values are greater than or less than the pivot.
    - This may be done in-place, however I have instead opted to create separate linked-lists for each sub-array.
3. Recursively apply steps 1 and 2 to the sub-arrays.
4. Reassemble the sub-arrays.

---

## Optimization

The quick-sort algorithm frequently requires a value to be appended to an array. I have chosen to use a linked-list
data structure to represent the values, which reduces the computation required to perform this operation.
Furthermore I have preferred to prepend new values to the linked-lists rather than appending them; once again this
is to reduce the computation required. This results in the order of the data being reversed in some places,
although this is not an issue in this instance since the reversed data is unsorted and therefore no information is
lost.

---

## Running the code

This project contains a Makefile to streamline the process of running the code.
You will require [GCC](https://gcc.gnu.org/) in order to compile and run the code in this way.
To do so simply run
```bash
make
```
from within the root directory.

---

## Checking for memory leaks

This project does not contain any memory leaks. This may be verified by installing [Valgrind](https://valgrind.org/) and running
```bash
make leak-check
```
from within the root directory.
