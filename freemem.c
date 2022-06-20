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
// Return the block of storage at location p to the pool of available free storage. 

// The pointer value p must be one that was obtained as the result of a call to getmem. 
// If p is NULL, then the call to freemem has no effect and returns immediately. 
// If p has some value other than one returned by getmem, 
// or if the block it points to has previously been released by another call to freemem, then the operation of freemem is undefined

// When freemem returns a block of storage to the pool, 
// if the block is physically located in memory adjacent to one or more other free blocks, 
// then the free blocks involved should be combined into a single larger block, 
// rather than adding the small blocks to the free list individually.

// Parameter: p - location of the block to be freed
void freemem(void * p) {

  if (p == NULL) {
    return;
  }

  check_heap();

  FreeListNode * curr = freeList;
  FreeListNode * pt = (FreeListNode * )((uintptr_t) p - MIN_SIZE);
  if (curr == NULL) { // case 1: freeList is empty
    freeList = pt;
    return;
  }

  if (curr < pt) {
    while (curr -> next != NULL && (uintptr_t) pt > (uintptr_t) curr -> next) {
      curr = curr -> next;
    }

    if ((uintptr_t) pt != (uintptr_t) curr + curr -> size) {
      pt -> next = curr -> next;
      curr -> next = pt;
      curr = pt;
    } else {
      curr -> size += pt -> size;
    }
  } else {
    pt -> next = curr;
    curr = pt;
    freeList = pt;
  }

  if (curr -> next != NULL) {
    if ((uintptr_t) curr -> next == (uintptr_t) curr + curr -> size) {
      curr -> size += curr -> next -> size;
      curr -> next = curr -> next -> next;
    }
  }

  check_heap();
}