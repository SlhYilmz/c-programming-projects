# Memory Management Project

## Overview

This project is a basic memory management simulation implemented in C. The program simulates a memory allocator that manages dynamic memory allocation and deallocation using a linked list of memory blocks. It provides basic functions to allocate and deallocate memory based on specific addresses or block sizes, mimicking the behavior of low-level memory management in operating systems.

## Features

- **Memory Allocation by Address**: Allows allocation of memory at a specific starting address. The program determines whether the requested block can be allocated based on the current memory layout.
  
- **Memory Allocation by Size (Best Fit)**: Allocates memory of a specified size using the best-fit strategy, which selects the smallest available block that is large enough to satisfy the allocation request.

- **Memory Deallocation**: Supports deallocation of memory blocks at specific addresses. The program attempts to merge adjacent free blocks to minimize fragmentation.

- **Memory Layout Visualization**: The current state of the memory is printed after each operation, showing which blocks are allocated and which are free.

## Functions

### `void initializeMemory(Node **root, int startAddr, int size)`

Initializes the memory with a single free block starting at `startAddr` and spanning `size` units.

### `void printMemoryLayoutThousands(Node *root)`

Prints the current memory layout, displaying the start and end addresses of each block in kilobytes.

### `void bellekAlAdresli(Node **root, int startAddr, int size)`

Allocates memory starting from `startAddr` with the size `size`. If the allocation is successful, the memory layout is updated accordingly.

### `void bellekIadeEt(Node **root, int startAddr, int size)`

Deallocates memory starting from `startAddr` with the size `size`. The function also attempts to merge adjacent free blocks to reduce fragmentation.

### `void bellekAlAdressiz(Node **root, int size)`

Allocates memory of `size` units using the best-fit strategy, where the smallest available block that can satisfy the request is chosen.

### `int isEmpty(Node *root)`

Checks if the memory list is empty (i.e., no blocks are available).

## How to Use

1. **Compile the Code**: Use the given makefile to compile the `main.c` file.
   ```bash
   make
   ```

2. **Run the Program**: Execute the compiled binary.
   ```bash
   ./main
   ```

3. **Understand the Output**: The program will print the memory layout after each allocation or deallocation operation, showing which blocks are occupied and which are free.

## Example Usage

The `main` function provides an example of how the memory management functions can be used:

```c
int main(void)
{
    Node *root = NULL;
    bellekIadeEt(&root, 900 * kb, 5 * kb);
    bellekIadeEt(&root, 26 * kb, 3 * kb);
    bellekAlAdresli(&root, 26 * kb, 3 * kb);
    bellekIadeEt(&root, 3 * kb, 1 * kb);
    bellekAlAdressiz(&root, 1 * kb);
    // Additional operations...
}
```

This example shows a sequence of memory allocation and deallocation operations, with the memory layout being printed after each operation.

## Version

This is version 0.0.1 of the Memory Management Project.

## Author

- **Muhammed Salih Yılmaz** - Initial development
