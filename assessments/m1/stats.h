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
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 
void print_tatistics();
/**
 * @brief A function that prints the statistics of an\
 * array including minimum, maximum, mean and median.
 *
 * @param N/A
 *
 * @return N/A
 */

void print_array(int a[], int size);
/**
 * @brief Given an array of data and a length, prints\
 * the array to the screen.
 * 
 * @param a[], Array that is going to be printed
 * @param size, The size of the array
 *
 * @return N/A
 */

int find_median(int a[], int size);
/**
 * @brief Given an array of data and a length, returns\
 * the median value.
 *
 * @param int a[], Array that is going to be printed
 * @param int size, The size of the array
 *
 * @return int median
 */

int find_mean(int a[], int size);
/**
 * @brief Given an array of data and a length, returns\
 * the mean value.
 *
 * @param int a[], Array that is going to be printed
 * @param int size, The size of the array
 *
 * @return int mean
 */

int find_maximum(int a[], int size);
/**
 * @brief Given an array of data and a length, returns\
 * the maximum value.
 *
 * @param int a[], Array that is going to be printed
 * @param int size, The size of the array
 *
 * @return int maximum
 */

int find_minimum(int a[], int size);
/**
 * @brief Given an array of data and a length, returns\
 * the minimum value.
 *
 * @param int a[], Array that is going to be printed
 * @param int size, The size of the array
 *
 * @return int minimum
 */

void sort_array(int a[], int size);
/**
 * @brief Given an array of data and a length, sorts\
 * the array from largest to smallest.
 *
 * @param a[], Array that is going to be printed
 * @param size, The size of the array
 *
 * @return N/A
 */

#endif /* __STATS_H__ */
