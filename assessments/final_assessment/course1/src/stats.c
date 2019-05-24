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
 * @file stats.c 
 * @brief Implement functions to process a given integer array like sorting, find
 * median, find mean value, find maximum, find minimum and print the result. Use a
 * simple driver to test all functions.
 *
 * @author Youxi Shao
 * @date 05/16/2019
 *
 */



#include <stdio.h>
#include "stats.h"


/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  unsigned char median;
  unsigned char mean;
  unsigned char maximum;
  unsigned char minimum;
  /* Statistics and Printing Functions Go Here */
  printf("The original array is:\n");
  print_array(test, SIZE);
  sort_array(test, SIZE);
  median = find_median(test, SIZE);
  mean = find_mean(test, SIZE);
  maximum = find_maximum(test, SIZE);
  minimum = find_minimum(test, SIZE);
  printf("The sorted array is:\n");
  print_array(test, SIZE);
  print_statistics(median, mean, maximum, minimum);

}

/* Add other Implementation File Code Here */
void print_statistics(unsigned char median, unsigned char mean, 
					  unsigned char maximum, unsigned char minimum) {
  printf("The median value of this array is %d.\nThe mean value of ", median);
  printf("this array is %d.\nThe maximum value of this array is ", mean);
  printf("%d.\nThe minimum value of this array is %d.\n", maximum, minimum);
}

void print_array(unsigned char a[], int size) {
  int i;
  for (i = 0; i < size; i++) {
  	if ((i + 1) % 8 != 0)
  		printf("%3d, ", a[i]);
  	else
  		printf("%3d\n", a[i]);
  }
}

unsigned char find_median(unsigned char a[], int size) {
  int med;
  if (size % 2 != 0)
  	med = a[(size + 1) / 2];
  else
  	med = (a[size / 2] + a[size / 2 + 1]) / 2;
  return med;
}

unsigned char find_mean(unsigned char a[], int size) {
  unsigned long total = 0;
  unsigned char mean;
  int i;
  for (i = 0; i < size; i++) {
  	total += a[i];
  }
  mean = total / size;
  return mean;
}

unsigned char find_maximum(unsigned char a[], int size) {
  unsigned char max = a[0];
  int i;
  for (i = 0; i < size - 1; i++) {
  	if (a[i + 1] > max)
  		max = a[i];
  }
  return max;
}

unsigned char find_minimum(unsigned char a[], int size) {
  int min = a[0];
  int i;
  for (i = 0; i < size - 1; i++) {
  	if (a[i + 1] < min)
  		min = a[i];
  }
  return min;
}

void sort_array(unsigned char a[], int size) {
  int i;
  int j;
  unsigned char temp;
  for (i = 0; i < size - 1; i++) {
  	for (j = i; j < size; j++) {
  		if (a[i] < a[j]) {
  			temp = a[i];
  			a[i] = a[j];
  			a[j] = temp;
  		}
  	}
  }
}
