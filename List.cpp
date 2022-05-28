#include <iostream>
#include "global.h"
#include "List.h"

ListItem* createList() {
	ListItem* pElem = ( ListItem* )malloc( sizeof( ListItem ) ); // mem alloc for empty element ( head )
	if ( !pElem ) {
		printf( "ERROR - createList()" );
		return 0;
	}
	
	pElem->pInfo = NULL;
	pElem->pNext = NULL;
	
	return pElem; 
}

int insertFront( ListItem* pList, LISTINFO* pInfo ) {
	insert( pList, pInfo );
}

int insert( ListItem* pAfter, LISTINFO* pInfo ) {
	ListItem* pElem = ( ListItem* )malloc( sizeof( ListItem ) ); // mem alloc for empty element
	
	if ( !pElem ) {
		printf( "ERROR - insert()" );
		return 0;
	}

	// squish between elements (or add to the end)
	pElem->pInfo = pInfo;
	pElem->pNext = pAfter->pNext;
	pAfter->pNext = pElem;
	return 1;
}

LISTINFO* removeFront( ListItem* pList ) {
	return remove( pList );
}

LISTINFO* remove( ListItem* pAfter ) {
	if ( isEmpty(pAfter ) ) {
		printf( "LINKED LIST IS EMPTY" );
		return 0;
	}
 
	// [HEAD]-->[a]-->[b]-->[c]-->null
	// remove element [b] + [a]-->[c] + return userInfo
	ListItem* pTemp = pAfter->pNext;
	LISTINFO* userInfo = pTemp->pInfo;
	pAfter->pNext = pTemp->pNext;
	free( pAfter->pNext );
	return userInfo;

}

int isEmpty( ListItem* pList ) {
	return !( pList->pNext ); // 1 - empty
}

void clearList( ListItem* pList, void( __cdecl* freeMem )( const void* ) ) {
	if ( !isEmpty ) {
		freeMem( remove( pList ) );
	}
}

