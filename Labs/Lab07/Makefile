CC=gcc

CFLAGS=-std=c99 -Wall -Werror -g

SRC=fsm.c tokens.c sha_sum.c sha256.c speller.c dictionary.c better_dictionary.c

OBJF=fsm.o tokens.o sha_sum.o sha256.o speller.o dictionary.o better_dictionary.o          # objects needed for fsm

EXE=fsm sha_sum speller                       # executables

all: $(EXE)

%.o:%.c tokens.h

	$(CC) $(CFLAGS) -c $< -o $@

fsm: fsm.o tokens.o

	$(CC) -o $@ fsm.o tokens.o

sha_sum: sha_sum.o sha256.o

	$(CC) -o $@ sha_sum.o sha256.o

speller: speller.o better_dictionary.o

	$(CC) -o $@ speller.o better_dictionary.o

clean:

	/bin/rm -f *.o *~ $(EXE)
