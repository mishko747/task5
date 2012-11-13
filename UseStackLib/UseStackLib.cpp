/**
 * @file	UseStackLib.cpp
 * @brief	Realization of functions and program entry point
 *
 * @autor	Sorokovskiy Muchailo
 */

#include "UseStackLib.h"

#include "../Stack/Stack.h"
#pragma comment ( lib, "../UseStackDll/Debug/Stack.lib" )

#include <stdio.h>
#include <conio.h>


// This function inverts the array of characters
UCHAR* InvertStr ( UCHAR *pStr )
{	
	UCHAR *invertStr;	// pointer to inverted array of characters
	STACKV *pStack;		// pointer to stack

	UCHAR i = 0U;	// the current number of characters
	UCHAR length = strlen( (char*)pStr );	// determining the length of the string

	try
	{
		// if the stack is not created
		if( !( pStack = CreateStack( length ) ) )
		{
			throw;
		}
		// if the term is not created
		if( !( invertStr = new UCHAR[length + 1U] ) )
		{
			throw;
		}

		// filling stack
		while( i < length && PushToStack( pStack, *(pStr + i++) ) );
		if( i < length )
		{
			throw;
		}

		i = 0U;
		// release stack and filling inverted array
		while( !IsEmpty( pStack ) )
		{
			GetTop(pStack, invertStr + i);
			Pop( pStack );
			i++;
		}
		if( i < length )
		{
			throw;
		}
		*(invertStr + i) = '\0';	// adding the end sybmol

		DeleteStack( pStack );	// remove the stack
	}
	catch(...)
	{
		delete[] invertStr;	// remove the array
		DeleteStack( pStack );	// remove the stack
		return NULL;
	}

	return invertStr;
}

void main ( void )
{
	UCHAR *pStr;
	if( !(pStr = new UCHAR[MAX_SYMBOLS + 1U]) )	// if memory not allocated
	{
		printf("Memory allocation error!\n");
		printf("Press any key to exit...");
		_getch();
		return;
	}

	do
	{
		system("cls");
		printf("Enter a string (no more than %u characters): ",  MAX_SYMBOLS);

		fflush(stdin);
		while( !scanf_s("%[^\n]s", pStr, MAX_SYMBOLS + 1U) )	// until not entered the correct value
		{
			printf("Invalid input!\nPlease re-enter data: ");
			fflush(stdin);	
		}

		// invert string
		UCHAR *pInvert;
		pInvert = InvertStr( pStr );
		if( !pInvert )
		{
			printf("Inversion error!\n");
			continue;
		}
		printf("\nInverted string: %s\n", pInvert);
		delete[] pInvert;
	}
	while( CONTINUE, _getch() != CODE_ESC );	// until not press ESC
	
	delete[] pStr;
	return;
}