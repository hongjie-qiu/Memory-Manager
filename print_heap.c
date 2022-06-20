// Jeffrey Qiu， Booker Hu
// CSE 374 22sp Homework 6
// 2022-05-18

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>

#include "mem.h"
#include "mem_impl.h"

// Function Usage:
// Print a formatted listing on file f showing the blocks on the free list. 
// Each line of output should describe one free block and begin with two hexadecimal numbers 
// (0xdddddddd, where d is a hexadecimal digit) giving the address and length of that block. 
// Each free block should be described on a single output line that begins with the block's address and length.
void print_heap(FILE * f) {
  FreeListNode * curr = freeList;

  int count = 1;
  while (curr != NULL) {
    fprintf(f, "#%d: Address: %p Size: %lu\n", count, (void * )(uintptr_t) curr, curr -> size);
    count++;
    curr = curr -> next;
  }

  fprintf(f, "Total number of free blocks: %d", count - 1);
}