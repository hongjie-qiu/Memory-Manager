// Jeffrey Qiu， Booker Hu
// CSE 374 22sp Homework 6
// 2022-05-18

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include <time.h>

#include "mem.h"

// Parameters:
// ntrials: total number of getmem plus freemem calls to randomly perform during this test. Default 10000.
// pctget: percent of the total getmem/freemem calls that should be getmem. Default 50.
// pctlarge: percent of the getmem calls that should request "large" blocks with a size greater than small_limit. Default 10.
// small_limit: largest size in bytes of a "small" block. Default 200.
// large_limit: largest size in bytes of a "large" block. Default 20000.
// random_seed: initial seed value for the random number generator. Default: system time-of-day clock
// Function usage:
// The program executes a large number of calls to functions getmem and freemem to allocate and free blocks of random sizes and in random order
// User can specify parameters that control the test, otherwise default values are used.
int main(int argc, char * argv[]) {
  int args[6] = {
    10000,
    50,
    10,
    200,
    20000,
    clock()
  };

  for (int i = 1; i < argc; i++) {
    args[i - 1] = atoi(argv[i]);
  }

  int ntrials = args[0];
  int pctget = args[1];
  int pctlarge = args[2];
  int small_limit = args[3];
  int large_limit = args[4];
  int random_seed = args[5];

  srand(random_seed);
  void * temp[ntrials];
  int end = 0;
  uintptr_t total_size, total_free, n_free_blocks;
  clock_t start_time, end_time;

  FILE * f = fopen("test.txt", "w");
  start_time = clock();
  for (int i = 0; i < ntrials; i++) {
    if (rand() % 100 >= pctget) {
      if (end > 0) {
        int rand_index = rand() % end;
        freemem(temp[rand_index]);
        temp[rand_index] = temp[end - 1];
        end--;
      }
    } else {
      int randSize;
      if (rand() % 100 >= pctlarge) {
        randSize = rand() % small_limit + 1;
      } else {
        randSize = rand() % (large_limit - small_limit) + small_limit + 1;
      }
      temp[end] = getmem(randSize);
      end++;
    }

    if (i % (ntrials / 10) == 0) {
      end_time = clock();
      printf("(%.0f%%)\n ", i / (double) ntrials * 100);
      printf("Total CPU time used so far: %.7f\n ", ((double)(end_time - start_time)) / CLOCKS_PER_SEC);
      get_mem_stats( & total_size, & total_free, & n_free_blocks);
      printf("Total amount of storage acquired: %lu\n ", total_size);
      printf("Total number of blocks: %lu\n ", n_free_blocks);
      printf("Average number of bytes: %.2f\n", total_free / (double) n_free_blocks);
    }
  }
  print_heap(f);
}