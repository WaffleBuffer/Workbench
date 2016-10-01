#include "list.h"

#include <stdlib.h>
#include <stdio.h>

int List_push(List *This, const TYPE val){
	Node *newNode = malloc(sizeof(Node));
	
	if(!newNode) {
		return NODE_ALLOC_ERROR;
	}
	
	newNode->value = val;
	newNode->next = This->top;
	This->top = newNode;
	This->size++;
	
	return 0;
}

TYPE List_pop(List *This){
	TYPE val;
	Node *tmp;

	if(!This->top) {
		return LIST_EMPTY;
	}
	
	tmp = This->top->next;
	val = This->top->value;
	
	free(This->top);
	This->top = tmp;
	This->size++;
	
	return val;
}
 
void List_clear(List *This){
	Node *tmp;
	
	while(This->top){
		tmp = This->top->next;
		free(This->top);
		This->top = tmp;
	}
	
	This->size = 0;
}
 
int List_length(List *This){
	return This->size;
}
 
// TODO correct this
void List_view(List *This){
	Node *tmp = This->top;
	
	while(tmp){
		printf("%d\n",tmp->value);
		tmp = tmp->next;
	}
}

void List_free(List *This){
	List_clear(This);
}

void List_newFree(List *This){
	if(This) {
		List_clear(This);
	}
	free(This);        
}

static void List_init(List *This){
	// Object propertys
	This->size = 0;
	This->top = NULL;
	
	// Object functions
	This->push = List_push;
	This->pop = List_pop;
	This->clear = List_clear;
	This->length = List_length;
	This->view = List_view;
}

List List_create(){
	List This;
	List_init(&This);
	
	This.free = List_free;
	return This;
}

List* new_List(){
	List *This = malloc(sizeof(List));
	
	if(!This) {
		perror("malloc");
		return NULL;
	}
	
	List_init(This);
	This->free = List_newFree;
	return This;
}
