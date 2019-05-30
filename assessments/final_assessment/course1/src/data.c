/* data.c */
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "data.h"
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint8_t base) {
  uint8_t counter = 0;
  uint8_t negativeFlag = 0;
  if (data == 0)
    * ptr = '0';
  else if (data < 0) {
    data = -data;
    negativeFlag = 1;
  }
  while (data != 0) {
    * (ptr + counter) = (data % base) > 9 ? (data % base - 10 + 'A') : \
                                            (data % base + '0');
    data /= base;
    counter++;
  }
  if (negativeFlag)
    * (ptr + counter++) = '-';
  my_reverse(ptr, counter);
  * (ptr + counter) = '\0';
  return counter;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
  int8_t negativeFlag = 1;
  int32_t num = 0;
  uint32_t powerBase = 1;
  if (* ptr == '-')
    negativeFlag = -1;
  my_reverse(ptr, digits);
  if (negativeFlag == -1)
    digits--;
  for (int i = 0; i < digits; i++) {
    if (i == 0) {
      if (* (ptr + i) >= 'A')
        num += powerBase * (* (ptr + i) - 'A' + 10);
      else
        num += powerBase * (* (ptr + i) - '0');
    }
    else {
      powerBase *= base;
      if (* (ptr + i) >= 'A')
        num += powerBase * (* (ptr + i) - 'A' + 10);
      else
        num += powerBase * (* (ptr + i) - '0');
    }
  }
  num *= negativeFlag;
  return num;
}