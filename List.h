#pragma once
#include "global.h"

typedef struct tagListItem {
	LISTINFO* pInfo;
	tagListItem* pNext;
} ListItem;

// creates empty list
ListItem* createList(); //empty element on top (GUARD)

// inserts new elem at the front of the list, returns 0 if fails else 1
int insertFront( ListItem* pList, LISTINFO* pInfo ); // pList - the List, pInfo - wsk do info

// inserts new elem to the list after pointer pAfter, returns 0 if fails else 1
int insert( ListItem* pAfter, LISTINFO* pInfo ); // pInfo - wsk do informacji

// removes first elem from the list and returns user info,
// if list is empty returns NULL
LISTINFO* removeFront( ListItem* pList );

// removes elem after the pointer pAfter from the list and returns user info
// if list is empty returns NULL
LISTINFO* remove( ListItem* pAfter );

// returns 1 if list is empty else returns 0
int isEmpty( ListItem* pList ); // pList - the List 

// clears list, so list is empty and ready to father use
// uses user releasing memory function to free the user info
void clearList( ListItem* pList );