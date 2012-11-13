/**
 * @file	Stack.h
 * @brief	Defining the types and library functions
 *
 * @autor	Sorokovskiy Muchailo
 */

#ifndef STACK_H_
#define STACK_H_

#ifdef LIBRARY
#define DLLEXPORT __declspec(dllexport)	// attribute export
#else
#define DLLEXPORT __declspec(dllimport) // attribute export
#endif /* LIBRARY */

#include <vector>

typedef unsigned char UCHAR;
typedef std::vector<UCHAR> STACKV;

extern "C"	// create "C" code
{
	/**
	* @brief	This function creates a pointer to type STACKV
	* @param	[in]	max_size Maximum size of memory that will occupy the stack
	* @return	STACKV*
	*/
	DLLEXPORT STACKV* CreateStack ( UCHAR max_size );

	/**
	* @brief	This function cleans up the stack
	* @param	[in]	*SV Pointer to stack
	* @return	void
	*/
	DLLEXPORT void ClearStack ( STACKV *SV );

	/**
	* @brief	This function checks whether the stack is not empty
	* @param	[in]	Pointer to stack
	* @post		returns true if pointer is not initialized or stack is empty
	* @return	bool
	*/
	DLLEXPORT bool IsEmpty ( STACKV *SV );

	/**
	* @brief	This function adds character to the stack
	* @param	[in]	*SV Pointer to stack
	* @param	[in]	ch Character
	* @post		returns false if the stack pointer is not initialized, or stack is full
	* @return	bool
	*/
	DLLEXPORT bool PushToStack ( STACKV *SV, UCHAR ch );

	/**
	* @brief	This function returns the value of top of stack
	* @param	[in]	*SV Pointer to stack
	* @param	[out]	*ch Pointer to character
	* @post		returns false if the stack pointer is not initialized, or stack is empty
	* @return	bool
	*/
	DLLEXPORT bool GetTop ( STACKV *SV, UCHAR *ch );

	/**
	* @brief	This function removes the top of stack
	* @param	[in]	*SV Pointer to stack
	* @post		returns false if the stack pointer is not initialized, or stack is empty
	* @return	bool
	*/
	DLLEXPORT bool Pop ( STACKV *SV );

	/**
	* @brief	This function removes the stack
	* @param	[in]	*SV Pointer to stack
	* @return	void
	*/
	DLLEXPORT void DeleteStack ( STACKV *SV );
}

#endif /* STACKDLL_H_ */