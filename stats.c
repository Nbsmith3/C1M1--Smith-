/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <stats.c> 
 * @brief <Gives sorted array with statistics on it values >
 *
 * <Takes an array and its size and rearranges it from large to small. Prints out calculated values of the arrays median, mean, maximum, and minimum.>
 *
 * @author <Nathan Smith>
 * @date <June 11, 2021>
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */

#define SIZE 40

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */

  /* Statistics and Printing Functions Go here */

  void sort_array(unsigned char TEST[], int size){
	  for(int i=0; i < size; i++){
		  for(int j = 0;j < size-i;j++) {
			if(TEST[j] < TEST[j+1]){
			unsigned char p = TEST[j];
			unsigned char q = TEST[j+1];
				TEST[j] = q;
				TEST[j+1] = p;
			}
		  }
	  }
  }

  int find_median(unsigned char TEST[], int size){
	  sort_array(TEST, size);
  int a;
  int b;
  int c;
  if(size % 2 == 0){
	  a = (size / 2) - 1;
 	  b = size / 2;
  	  c = (TEST[a] + TEST[b])/ 2;
  }
  else{
	  c = ((size - 1) / 2) + 1;
  }
  return c;
  }

  int find_mean(unsigned char TEST[], int size){
	  int tot = 0;
	  int mean;
	for(int i = 0; i < size; i++){
		tot = tot + TEST[i];
	}
	mean = tot / size;
	return mean;
  }
  int find_maximum(unsigned char TEST[], int size){
	  sort_array(TEST, size);
	  int max;
	  max = TEST[0];
	  return max;
  }
  int find_minimum(unsigned char TEST[], int size){
	  sort_array(TEST, size);
	  int min;
	  min = TEST[size - 1];
	  return min;
  }
  void print_statistics(unsigned char TEST[], int size){
	  int c = find_median(TEST, size);
	  int mean = find_mean(TEST, size);
	  int max = find_maximum(TEST, size);
	  int min = find_minimum(TEST, size);

	  printf("Median = %d", c);
	  printf("\n");
	  printf("Mean = %d", mean);
	  printf("\n");
	  printf("Maximum = %d", max);
	  printf("\n");
	  printf("Minimum = %d", min);
	  printf("\n");
  }
  void print_array(unsigned char TEST[], int size){
	  sort_array(TEST, size);
	  for(int k=0; k < size; k++){
		  printf("%d ", TEST[k]);
	  	      }
	  printf("\n");
  }
  print_array(test, SIZE);
  print_statistics(test, SIZE);
}

/* Add other Implementation File Code Here */

