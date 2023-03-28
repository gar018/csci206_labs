CFLAGS = -g -c
EXES   = double

all: $(EXES)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

double.o: double.s
	as -g $< -o $@

double: double_rev.o double.o
	$(CC) double_rev.o double.o -o $@

clean:
	rm -f *.o *~ $(EXES)
