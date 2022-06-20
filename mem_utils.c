// Jeffrey Qiu， Booker Hu
// CSE 374 22sp Homework 6
// 2022-05-18

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include <assert.h>

#include "mem.h"
#include "mem_impl.h"

// Function usage:
// Check for possible problems with the free list data structure and verify that the free list has the following properties:
// Blocks are ordered with strictly increasing memory addresses
// Block sizes are positive numbers and no smaller than the minimum size
// Blocks do not overlap
// Blocks are not touching
// Function returns silently if no error is detected
// If error is detected, assert should fail and cause the program to terminate at that point
void check_heap() {
  FreeListNode * curr = freeList;
  while (curr != NULL) {
    //Block sizes are positive numbers and no smaller than the minimum size
    assert(curr -> size >= MIN_SIZE);

    if (curr -> next != NULL) {
      // Blocks are ordered with strictly increasing memory addresses & Blocks are not touching
      assert(((uintptr_t) curr + curr -> size) <= (uintptr_t) curr -> next);
    }
    curr = curr -> next;
  }
}