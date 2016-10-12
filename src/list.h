#include "Utils.c"

#include <stdlib.h>

#ifndef LIST__H
#define LIST__H

#define NODE_ALLOC_ERROR 1
#define LIST_EMPTY      -1

#ifdef __cplusplus
	extern "C" {
#endif

typedef struct Node {
	TYPE value;
	struct Node *next;
} Node;

typedef struct List {
	size_t size;
	struct Node *top;	
	
	int(*push)(struct List*, const TYPE);
	TYPE(*pop)(struct List*);
	void(*clear)(struct List*);
	void(*free)(struct List*);
	int(*length)(struct List*);
	void(*view)(struct List*);
}List;

List List_create(void);
List* new_List(void);

#ifdef __cplusplus
}
#endif

#endif /* LIST__H */
