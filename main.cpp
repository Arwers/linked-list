#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <time.h>

#include "list.h"
#include "global.h"

#define DEBUG

void printList( ListItem* pList );
listInfo* createInf();

int main() {
	
	// create list
	ListItem* pList = createList();
	srand( time( NULL ) );

	// add 20 elements with random keys < 50 (task requirement)
	for ( int i = 0; i < 20; i++ ) {
		listInfo* pInfo = createInf();
		pInfo->nKey = rand() % 50;
		pInfo->p[ 0 ] = i + 1;
		
		if ( i == 11 ) {
			// for 9th element key should be 2000 (task requirement)
			pInfo->nKey = 2000;
		}

		if ( !insertFront( pList, pInfo ) ) {
			printf( "ERROR - 20 random elements segment" );
			return 0;
		}
	}

#ifdef DEBUG
	printf( "LINKED LIST: \n" );
	printList( pList );
#endif

	// sort list (task requirement)
	sortList( pList, compare );

#ifdef DEBUG
	printf( "SORTED LINKED LIST: \n" );
	printList( pList );
#endif
	// find element with key = 2000 ( task requirement )
	listInfo* pInfo = createInf();
	pInfo->nKey = 2000;

	ListItem* pPrev = createList();
	ListItem* pFind = createList();

	pFind = find( pList, pInfo, &pPrev, compare );
	
	// add element with key = 3000 BEFORE elem with key = 2000 ( task requirement )
	listInfo* pTemp = createInf();
	pTemp->nKey = 3000;
	if ( !insert( pPrev, pTemp ) ) {
		printf( "ERROR - find element with key = 2000 segment" );
		return 0;
	}

#ifdef DEBUG
	printf( "LINKED LIST AFTER INSERTION: \n" );
	printList( pList );
#endif

	// remove element with key = 2000 ( task requirement)
	remove( pPrev->pNext );

#ifdef DEBUG
	printf( "LINKED LIST AFTER ITEM REMOVAL: \n" );
	printList( pList );
#endif

	// clear list ( task requirement)
	clearList( pList, freeInfo );

	// add two elements ( task requirement)
	listInfo* pElem1 = createInf();
	pElem1->nKey = 5318008;
	pElem1->p[ 0 ] = 1;
	pElem1->p[ 1 ] = 1;
	insert( pList, pElem1 );
	
	listInfo* pElem2 = createInf();
	pElem2->nKey = 71830;
	pElem2->p[ 0 ] = 2;
	pElem2->p[ 1 ] = 1;
	insert( pList, pElem2 );

#ifdef DEBUG
	printf( "LINKED LIST CLEARED + 2 NEW ELEMENTS: \n" );
	printList( pList );
#endif

	// delete list ( task requirement)
	removeList( &pList, freeInfo );

}

void printList( ListItem* pList ) {
	ListItem* pom = pList;
	int i = 1;
	while ( !isEmpty( pom ) ) {
		pom = pom->pNext;
		printf( "Element[ %d ] = %d\n", i++, pom->pInfo->nKey );
	}
}

listInfo* createInf() {
	listInfo* pTemp = ( listInfo* )malloc( sizeof( listInfo ) );

	if ( !pTemp ) {
		printf( "ERROR - CreateInf() - 1" );
		return NULL;
	}

	pTemp->p = ( int* )malloc( 2 * sizeof( int ) );

	if ( !( pTemp->p ) ) {
		printf( "ERROR - CreateInf() - 2" );
		return NULL;
	}

	return pTemp;
}

void freeInfo( const void* itemInfo ) {
	free( ( ( listInfo* )itemInfo )->p );
	free( ( listInfo* )itemInfo );
	itemInfo = NULL;
}

int compare( const void* first, const void* second ) {
	if ( ( ( listInfo* )first )->nKey < ( ( listInfo* )second )->nKey ) return -1;
	if ( ( ( listInfo* )first )->nKey == ( ( listInfo* )second )->nKey ) return 0;
	return 1;
}