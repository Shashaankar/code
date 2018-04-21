HEADERS = ../include/algos_util.h

default: qsort_exec

util.o :
	gcc -c algos_util.c -o util.o

qsort.o: quick_sort.c $(HEADERS)
	gcc -c quick_sort.c -o qsort.o

qsort_exec: qsort.o util.o
	gcc qsort.o util.o -o qsort_exec

clean:
	-rm -f qsort.o
	-rm -f util.o
	-rm -f qsort_exec
