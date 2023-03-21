CC = gcc
AS = as
CFLAGS = -std=c99 -Wall -Werror -g

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -rf *.o *~ $(EXE)
