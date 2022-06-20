// Jeffrey Qiu， Booker Hu
// CSE 374 22sp Homework 6
// 2022-05-18

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>

#include "mem.h"
#include "mem_impl.h"

// Store statistics about the current state of the memory manager in the three 
// integer variables whose addresses are given as arguments.
// total_size: total amount of storage in bytes acquired by the memory manager 
// so far to use in satisfying allocation requests
// total_free: the total amount of storage in bytes that is currently stored on the free list, 
// including any space occupied by header information or links in the free blocks.
// n_free_blocks: the total number of individual blocks currently stored on the free list.
void get_mem_stats(uintptr_t * total_size, uintptr_t * total_free, uintptr_t * n_free_blocks) {
  check_heap();
  * total_size = total_used;

  uintptr_t free_bytes = 0;
  uintptr_t free_blocks = 0;

  FreeListNode * curr = freeList;
  while (curr != NULL) {
    free_bytes += curr -> size;
    free_blocks++;
    curr = curr -> next;
  }

  * total_free = free_bytes;
  * n_free_blocks = free_blocks;
  check_heap();
}