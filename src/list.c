#include "list.h"

#include <stdlib.h>

void new_NODE (NODE* This) {
	This = (NODE) malloc(sizeof(NODE));
}

void free_NODE(NODE* This) {
	free(This);
}
