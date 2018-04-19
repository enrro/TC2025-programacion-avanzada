#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"
int brutesolution(int flight_length, int *movieLengths, int arrsize);
typedef int bool;
#define true 1
#define false 0

int main()
{
    int flightLength = 240;
    int movieLengths[] = {90, 160, 70, 210, 80, 60, 190};
    int arrsize = sizeof(movieLengths)/sizeof(int);
    bool result;
    

    result = brutesolution(flightLength, movieLengths, arrsize);
    printf("Resultado brute force: %s \n", result ? "true" : "false");

    return 0;
}

int brutesolution(int flight_length, int *movieLengths, int arrsize) {
  int i, j;
  for (i = 0; i < arrsize; i++) {
  	int first_movie = movieLengths[i];
    for (j = 1; j < arrsize; j++) {
      //not to choose the same movie twice
      if(j == i) {
        continue;
      }
      //if we find a matching second 3movie
    	if (first_movie + movieLengths[j] == flight_length) {
          return 1;
      }
    }
  }
  return 0;
}
