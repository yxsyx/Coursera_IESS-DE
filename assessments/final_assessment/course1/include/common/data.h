/*data.h*/

/**
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __DATA_H__
#define __DATA_H__

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint8_t base);
/**
 * @brief
 *
 * detail
 *
 * @param
 * @param
 * @param
 *
 * @return
 */

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);
/**
 * @brief
 *
 * detail
 *
 * @param
 * @param
 * @param
 *
 * @return
 */

#endif /* __DATA_H__ */
