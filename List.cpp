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
	return insert( pList, pInfo );
}

int insert( ListItem* pAfter, LISTINFO* pInfo ) {
	ListItem* pElem = ( ListItem* )malloc( sizeof( ListItem ) ); // mem alloc for new element
	
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
		printf( "LINKED LIST IS EMPTY - remove()" );
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

void removeList( ListItem** pAdr, void( __cdecl* freeMem )( const void* ) ) {
	clearList( *pAdr, freeMem ); // clear list
	free( *pAdr ); // release mem
	*pAdr = NULL; // set pointer to NULL
}

void sortList( ListItem* pList, int( __cdecl* compareInfo )( const void*, const void* ) ) {
	if ( isEmpty( pList ) ) {
		return;
	}

	ListItem* pFirst = pList; // pointer from which search begins 
	
	while ( !isEmpty( pFirst ) ) {
		ListItem* pMin = pFirst; // points to element before smallest one
		ListItem* pCurr = pMin->pNext; // points to element before compared one

		while ( !isEmpty( pCurr ) ) {
			if ( compare( ( const void* )( pMin->pNext->pInfo ), ( const void* )( pCurr->pNext->pInfo ) ) == 1 ) { // check if compared is smaller than smallest one
				pMin = pCurr;
			}
			pCurr = pCurr->pNext;
		}

		if ( pMin != pFirst ) {
			pCurr = pMin->pNext->pNext;
			pMin->pNext->pNext = pFirst->pNext;
			pFirst->pNext = pMin->pNext;
			pMin->pNext = pCurr;
		}

		pFirst = pFirst->pNext;
	}
}

ListItem* find( ListItem* pList, const void* pInfo, ListItem** pPrev, int( __cdecl* compareInfo )( const void*, const void* ) ) {
	if ( ( isEmpty( pList ) ) ) {
		printf( "LINKED LIST IS EMPTY - find()" );
		return NULL;
	}

	ListItem* pTemp = pList;
	while ( !isEmpty( pTemp ) ) {
		if ( compareInfo( ( const void* )( pTemp->pNext->pInfo ), pInfo ) == 0 ) {
			*pPrev = pTemp;
			return pTemp->pNext;
		}
		pTemp = pTemp->pNext;
	}
	return NULL;
}



