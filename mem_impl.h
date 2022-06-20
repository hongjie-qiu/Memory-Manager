// Jeffrey Qiu， Booker Hu
// CSE 374 22sp Homework 6
// 2022-05-18

#ifndef MEMI_H
#define MEMI_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MIN_SIZE 16

typedef struct FreeListNode {
  uintptr_t size;
  struct FreeListNode* next;
} FreeListNode;

void check_heap();

FreeListNode* freeList;
uintptr_t total_used;

#endif