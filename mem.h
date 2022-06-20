// Jeffrey Qiu， Booker Hu
// CSE 374 22sp Homework 6
// 2022-05-18


#ifndef MEM_HEADER
#define MEM_HEADER

void* getmem(uintptr_t size);
void freemem(void* p);
void get_mem_stats(uintptr_t* total_size, uintptr_t* total_free, uintptr_t* n_free_blocks);
void print_heap(FILE *f);

#endif
