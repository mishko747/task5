/**
 * @file	Stack.cpp
 * @brief	Realization of library functions
 *
 * @autor	Sorokovskiy Muchailo
 */
#define LIBRARY

#include "Stack.h"

// This function creates a pointer to type STACKV
STACKV* CreateStack ( UCHAR max_size )
{
	STACKV *pVector = new STACKV;
	pVector->reserve( max_size );	// memory allocated by the max_size elements
	return pVector;
}

// This function cleans up the stack
void ClearStack ( STACKV *SV )
{
	if( !SV )
	{
		return;
	}
	SV->clear();
}

// This function checks whether the stack is not empty
bool IsEmpty ( STACKV *SV )
{
	if( !SV )
	{
		return true;
	}
	return SV->empty();
}

// This function adds character to the stack
bool PushToStack ( STACKV *SV, UCHAR ch )
{
	if( !SV || SV->size() == SV->capacity() )
	{
		return false;
	}
	SV->push_back( ch );
	return true;
}

// This function returns the value of top of stack
bool GetTop ( STACKV *SV, UCHAR *ch )
{
	if( !SV || SV->empty() )
	{
		return false;
	}
	*ch = SV->back();
	return true;
}

// This function removes the top of stack
bool Pop ( STACKV *SV )
{
	if( !SV || SV->empty() )
	{
		return false;
	}
	SV->pop_back();
	return true;
}

// This function removes the stack
void DeleteStack ( STACKV *SV )
{
	SV->~vector();
}