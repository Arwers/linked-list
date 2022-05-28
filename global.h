#pragma once
#ifndef _GLOBAL_H_
#define _GLOBAL_H_

typedef struct listInfo {
	int nKey;
	// two-element array (dynamically allocated)
	// contains: {index, data} (?)
	int* p;
} listInfo;

#define LISTINFO listInfo

#endif
