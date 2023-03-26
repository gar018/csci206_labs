CC = gcc
AS = as
CFLAGS = -std=c99 -Wall -Werror -g

counte: counte.c counte.s
time: time.c time.s
list_primes: list_primes.c is_prime.s
check_primes: check_primes.c check_primes.s
%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -rf *.o *~ $(EXE)
