/*
 * Implements a dictionary's functionality
 * Gordon Rose
 */

#include <stdbool.h>
#include <fcntl.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Maximum number of words in the dictionary
#define N 150000

//Number of bins
#define BINS 27

// array of dictionary words
char words[BINS][N][LENGTH+1];

// number of words in the dictionary
int num_words = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    unsigned int bin = hash(word);
    for (int i = 0; i < num_words; i++) {
        const char * this_word = words[bin][i];
        if(strcasecmp(this_word,word) == 0) {
            return true;
        }
    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary_filename)
{
    FILE * f = fopen(dictionary_filename, "r");
    if (f == NULL) {
        return false;
    }
    int file = 0;
    while (file != EOF) {
        char buf[LENGTH+1];
        file = fscanf(f, "%s", buf);
        const char * w = buf;
        strcpy(words[hash(w)][num_words],buf);
        num_words++;
    }
    num_words--;
    return true;
}

unsigned int hash(const char * word) {
    unsigned int h = 0;
    const char fstLetter = word[0];
    const char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 1; i < strlen(alphabet)+1; i++ ) {
        const char alpha = alphabet[i];
        if (strcasecmp(&fstLetter, &alpha) == 0) h = i;
    }
    return h;
}

// Return the number of words stored in the dictionary.
unsigned int size(void)
{
    return num_words;

}
