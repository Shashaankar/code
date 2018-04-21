HEADERS = ll_util.h

default: dll_exec

util.o :
	gcc -c ll_util.c -o util.o

dll.o: double_ll.c $(HEADERS)
	gcc -c double_ll.c -o dll.o

dll_exec: dll.o util.o
	gcc dll.o util.o -o dll_exec

clean:
	-rm -f dll.o
	-rm -f util.o
	-rm -f dll_exec
