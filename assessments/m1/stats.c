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
  int median;
  int mean;
  int maximum;
  int minimum;
  int sorted_array[SIZE];
  /* Statistics and Printing Functions Go Here */
  printf("The original array is: ");
  print_array(test, SIZE);
  print_statistics(test, SIZE);

}

/* Add other Implementation File Code Here */
void print_statistics() {

}

void print_array(int a[], int size) {

}

int find_median(int a[], int size) {

}

int find_mean(int a[], int size) {

}

int find_maximum(int a[], int size) {

}

int find_minimum(int a[], int size) {
	
}

