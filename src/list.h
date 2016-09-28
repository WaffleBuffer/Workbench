#ifndef LIST__H
#define LIST__H

// The type of the list
typedef int TYPE;

typedef struct node{
	TYPE value;
	struct node* next;	
	
	void (*new_LIST);
	void (*free);
}NODE, *LIST;

#endif /* LIST__H */
