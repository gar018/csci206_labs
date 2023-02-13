CC=gcc
CFLAGS=-Wall -Wfatal-errors -Werror -std=c99 
all: strnode_test node_test stack_test pcalc
node_test: node.o node_test.o node.h
strnode_test: strnode.o strnode_test.o strnode.h
stack_test: stack.o stack_test.o stack.h
pcalc: stack.o stack.h  pcalc.o 
LDLIBS=-lm
clean:
	rm -f strnode_test *.o
	rm -f node_test *.o
	rm -f stack_test *.o
	rm -f pcalc *.o
