/**
 * @file	UseStackDll.cpp
 * @brief	Realization of functions and program entry point
 *
 * @autor	Sorokovskiy Muchailo
 */

#include "UseStackDll.h"

#include <stdio.h>
#include <conio.h>
#include <Windows.h>

#include "../Stack/Stack.h"

// pointers to functions library
HINSTANCE stackDll;
STACKV* (*pCreateStack)( unsigned short );
//void (*pClearStack)( STACKV* );
bool (*pIsEmpty)( STACKV* );
bool (*pPushToStack)( STACKV*, UCHAR );
bool (*pGetTop)( STACKV*, UCHAR* );
bool (*pPop)( STACKV *SV );
void (*pDeleteStack)( STACKV *SV );

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
		if( !( pStack = pCreateStack( length ) ) )
		{
			throw;
		}
		// if the term is not created
		if( !( invertStr = new UCHAR[length + 1U] ) )
		{
			throw;
		}

		// filling stack
		while( i < length && pPushToStack( pStack, *(pStr + i++) ) );
		if( i < length )
		{
			throw;
		}

		i = 0U;
		// release stack and filling inverted array
		while( !pIsEmpty( pStack ) )
		{
			pGetTop(pStack, invertStr + i);
			pPop( pStack );
			i++;
		}
		if( i < length )
		{
			throw;
		}
		*(invertStr + i) = '\0';	// adding the end sybmol

		pDeleteStack( pStack );	// remove the stack
	}
	catch(...)
	{
		delete[] invertStr;	// remove the array
		pDeleteStack( pStack );	// remove the stack
		return NULL;
	}

	return invertStr;
}

void main ( void )
{
	// dynamic load library
	if ( !(stackDll = LoadLibrary( TEXT("Stack") ) )  ) // if not load library
	{
		printf("Error connecting libraries!\n");
		printf("Press any key to exit...");
		_getch();
		return;
	}

	// initialization of pointers to functions
	(FARPROC &)pCreateStack	= GetProcAddress(stackDll, "CreateStack");
	//(FARPROC &)pClearStack	= GetProcAddress(stackDll, "ClearStack");
	(FARPROC &)pIsEmpty	= GetProcAddress(stackDll, "IsEmpty");
	(FARPROC &)pPushToStack	= GetProcAddress(stackDll, "PushToStack");
	(FARPROC &)pGetTop	= GetProcAddress(stackDll, "GetTop");
	(FARPROC &)pPop	= GetProcAddress(stackDll, "Pop");
	(FARPROC &)pDeleteStack	= GetProcAddress(stackDll, "DeleteStack");

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
	FreeLibrary( stackDll );  // disable library

	return;
}