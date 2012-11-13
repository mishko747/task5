/**
 * @file	UseStackLib.h
 * @brief	Defining the types and project functions
 *
 * @autor	Sorokovskiy Muchailo
 */

#ifndef USESTACKLIB_H_
#define USESTACTLIB_H_

typedef unsigned char UCHAR;

#define MAX_SYMBOLS 200U	// maximum length of string
#define CONTINUE printf("\n\nPress any key to continue of ESC to exit...")	// message of end session
#define CODE_ESC 27	// key code ESC

/**
* @brief	This function inverts the array of characters
* @param	[in]	*pStr Pointer to stack
* @post		Returns a pointer to an array of inverted characters
* @return	unsigend char*
*/
UCHAR* InvertStr ( UCHAR *pStr );

#endif /* USESTACKLIB_H_ */