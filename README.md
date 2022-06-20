# Memory-Manager
A complete memory management package that has the same functionality as the standard library(such as malloc and free) and a testing program in C/C++

### Functionality:
The memeory manager implements a linked-list named freeList as the storage of free memory blocks to effectively manage the memeory usage. When an user requests a pointer to a new block of storage with at least "size" bytes of memory, the getmem(size) function will search through the freeList and returns the block with most suitable size. If getmem finds a block on the free list that is substantially larger than the storage requested, it should divide that block and return a pointer to a portion that is large enough to satisfy the request, leaving the remainder on the free list. If no block on the free list statisfy the request, getmem tries to acquire a good-sized block of storage from the underlying system, add it to the free list, then split it up, yielding a block that will satisfy the request. If getmem cannot satisfy the request in the end, it will return null.

When an user requests to free a memory block p, the call to freemem(p) will return the block of storage at location p to the pool of available free storage. If p is NULL, then the call to freemem has no effect and returns immediately. If p has some value other than one returned by getmem, or if the block it points to has previously been released by another call to freemem, then the operation of freemem is undefined. In addition, if the block is physically located in memory adjacent to one or more other free blocks, then the free blocks involved would be combined into a single larger block. 

##### Credit: Booker Hu
