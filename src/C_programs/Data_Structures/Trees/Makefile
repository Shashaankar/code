# make file to compile BST 
HEADERS = tnode.h

default: bst

util.o :
	gcc -c tnode_utilities.c -o util.o

bst.o: bst.c $(HEADERS)
	gcc -c bst.c -o bst.o

bst: bst.o util.o
	gcc bst.o util.o -o bst

clean:
	-rm -f bst.o
	-rm -f util.o
	-rm -f bst
