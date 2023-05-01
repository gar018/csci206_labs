
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
/*
 * Students need to fill in the TODO places
 */

    struct param_t {
        double * array;
        int            from;       // start index
        int            len;
    };

// swap two locations (i,j) in the array
void swap(double arr[], int i, int j) 
{
	double tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void * selection_sort(void * param) 
{
	/*
	TODO write selection sort.

	Step 1: Set MIN to location 0 in the array
	Step 2: Search the minimum element in the unsorted part of array [MIN..len-1]
	Step 3: Swap with value at location MIN
	Step 4: Increment MIN to point to next element
	Step 5: Repeat until MIN points to the end of the array
	*/

   struct param_t *p = (struct param_t *)param;
    for(int i = p->from; i < p->from+p->len; i++) {
        int MIN = i;//holds the INDEX of the minimum value
        for(int j = i; j < p->from+p->len; j++) {
            if(p->array[MIN] > p->array[j]) MIN = j;
        }
        swap(p->array, MIN, i);
    }
    return NULL;
}

/* UTILITY FUNCTIONS */
// print an array of size n (do not change, or labtool will not work!)
void print_array(double * a, int n)
{
	int i;
	if(n <= 16){
		// print the whole thing
		printf("[");
		for (i=0; i<n-1; i++){
			printf("%f, ", a[i]);
		}
		printf("%f]\n", a[i]);
	} else {
		// truncate the printout
		printf("[");
		// print first 8
		for (i=0; i<8; i++){	
			printf("%f, ", a[i]);
		}
		printf("..., ");
		// print last 8
		for (i=n-9; i < n-1; i++){
			printf("%f, ", a[i]);
		}
	  printf("%f]\n", a[i]);
	}
}

// pseudo random array filler
void fill_array(int seed, double * a, int n){
	if (n == 16){
		// constant data if n == 16 (do not change this!)
		const double d[16] = {4,4,4,4,7,7,7,7,1,1,1,1,5,5,5,5};
		memcpy(a, d, sizeof(double)*16);
		return;
	}
	srand(seed);
	while(n--){
		// rand returns an int between 0 and RAND_MAX, this maps it to [0...1]
		*a++ = (double)rand() / (double)RAND_MAX;
	}
}

// check if an array is sorted, return 1 if true, 0 if not.
int is_sorted(double arr[], int n)
{
	int i;
	// check for any out of order elements
	for (i=0; i<n-1; i++){
		if (arr[i] > arr[i+1])
			return 0;
	}
	return 1;
}


void merge_result(struct param_t *p, int len, int threads, double * dest);

/* Driver program to test above functions */
int main(int argc, char *argv[])  
{

	int NUM_THREADS;              // how many threads to use
	int NUM_VALS;                 // how many values to sum
	double * a = NULL;            // the array of values



   pthread_t * worker;      // worker threads, this is an array
   struct param_t * param;  // parameter, array, from, len

    //printf("debug\n");

	switch (argc){
		case 1:   // no arguments, use default values
			NUM_VALS = 16;
			NUM_THREADS = 1;
			break;
		case 2:   // just one argument, NUM_VALS
			NUM_VALS = atoi(argv[1]);
			NUM_THREADS = 1;
			break;
		default:  // command line sets both values
			NUM_VALS = atoi(argv[1]);
			NUM_THREADS = atoi(argv[2]);
	}

   int length = NUM_VALS/NUM_THREADS;

	printf("%s using %d threads on array of %d elements.\n",
		argv[0],
		NUM_THREADS,
		NUM_VALS);
	if (NUM_VALS % NUM_THREADS != 0){
		printf("ERROR: array size must be evenly divisible by the number of threads!\n");
		exit(1);
	}

	a = malloc(sizeof(double)*NUM_VALS);  // allocate memory for array
	fill_array(7891, a, NUM_VALS);        // initialize with random values


   worker = malloc(sizeof(pthread_t)*NUM_THREADS);
   param = malloc(sizeof(struct param_t)*NUM_THREADS);


	printf("Generated array ");
	print_array(a, NUM_VALS);

	printf("Sorting. . .\n");
   
    for (int i = 0; i < NUM_THREADS; i ++) {
	  param[i].array = a;
	  param[i].from = i*length;
	  param[i].len = length;
	  
	  int ret_v = pthread_create(&(worker[i]), NULL, selection_sort, (void*)&(param[i]));
	  if (ret_v) {
		 printf("ERROR; return code from pthread_create() is %d\n", ret_v);
		 exit(-1);
	  }
   }

   for (int i = 0; i < NUM_THREADS; i ++) {  // join the threads
	  pthread_join(worker[i], NULL);
   }

    //double result[NUM_VALS];
    //merge_result(param,NUM_VALS,NUM_THREADS,result);
	printf("Sorted array is ");
	print_array(a, NUM_VALS);

	printf("Is sorted: %s\n",
	is_sorted(a, NUM_VALS) ? "YES": "NO -- FAILED");

  free(a);
  free(worker);
  free(param);


  return 0;
}


void merge_result(struct param_t *p, int len, int threads, double * dest) {
    /*double * from_array[threads];
    double * a = p[0].array;
    for (int i = 0; i < threads; i++) {
        from_array[i] = a[p[i].from];
    }

    for (int i = 0; i < len; i++) {
        int MIN = 0;
        for (int j = 0; j < threads; j++) {
            if (*from_array[MIN] > *from_array[j]) {
                MIN = j;
            }
        }
        dest[i] = *from_array[MIN];
        from_array[MIN] = a[MIN+1];
    }
    
    double array_stack[threads][len/threads];
    for (int i = 0; i < len; i++) {
           
    }*/
}
