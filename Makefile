# Booker Hu, Jeffery Qiu
# CSE 374 22sp Homework 6
# 2022-05-19


bench: getmem.o freemem.o get_mem_stats.o print_heap.o mem_utils.o bench.o
	gcc -Wall -g -std=c17 getmem.o freemem.o get_mem_stats.o print_heap.o mem_utils.o bench.o -o bench

bench.o: bench.c mem.h
	gcc -Wall -g -c bench.c -std=c17 -o bench.o

getmem.o: getmem.c mem.h mem_impl.h
	gcc -Wall -g -c getmem.c -std=c17 -o getmem.o

freemem.o: freemem.c mem.h mem_impl.h
	gcc -Wall -g -c freemem.c -std=c17 -o freemem.o

get_mem_stats.o: get_mem_stats.c mem.h mem_impl.h
	gcc -Wall -g -c get_mem_stats.c -std=c17 -o get_mem_stats.o 

print_heap.o: print_heap.c mem.h mem_impl.h
	gcc -Wall -g -c print_heap.c -std=c17 -o print_heap.o 

mem_utils.o: mem_utils.c mem.h mem_impl.h
	gcc -Wall -g -c mem_utils.c -std=c17 -o mem_utils.o

test: bench
	./bench

clean:
	rm -f *.o *~ bench test.txt
