/**
 * \file list.c
 * \brief Implementation of List struct from list.h.
 * \author Thomas MEDARD, Remi SEGRETAIN
 */

#include "list.h"

#include <stdlib.h>
#include <stdio.h>

/**
 * \class List list.h
 * \brief A chained list.
 */

/**
 * \fn int List_push(List *This, const TYPE val)
 * \brief Push the list to add a new node with a value.
 * \param[in, out] This The List to add into.
 * \param[in] val The value to add.
 * \return 0 if no error detected. See list.h for error values.
 */
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

/**
 * \fn TYPE List_pop(List *This)
 * \brief Pop a value from a List. Delete from the List and return the last value.
 * \param[in, out] This The List to pop from.
 * \return The value poped.
 */
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
 
/**
 * \fn void List_clear(List *This)
 * \brief Free all values from a List.
 * \param[in, out] This The List to free.
 */
void List_clear(List *This){
	Node *tmp;
	
	while(This->top){
		tmp = This->top->next;
		free(This->top);
		This->top = tmp;
	}
	
	This->size = 0;
}
 
/**
 * \fn int List_length(List *This)
 * \brief Get the current size/length of a List.
 * \param[in, out] This The List to free.
 * \return The current size/length of a List.
 */
int List_length(List *This){
	return This->size;
}
 
// TODO correct this
/**
 * \fn void List_view(List *This)
 * \brief Display the List on the standard output.
 * \param[in, out] This The List to display.
 * \bug Problems on the display.
 */
void List_view(List *This){
	Node *tmp = This->top;
	
	while(tmp){
		printf("%d\n",tmp->value);
		tmp = tmp->next;
	}
}

/**
 * \fn void List_free(List *This)
 * \brief Free all values from a List. but not List itself.
 * \param[in, out] This The List to free.
 */
void List_free(List *This){
	List_clear(This);
}

/**
 * \fn void List_newFree(List *This)
 * \brief Free all values from a List with List itslef.
 * \param[in, out] This The List to free.
 */
void List_newFree(List *This){
	if(This) {
		List_clear(This);
	}
	free(This);        
}

/**
 * \fn static void List_init(List *This)
 * \brief initialize all values of a List.
 * \param[in, out] This The List to initialize.
 */
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

/**
 * \fn List List_create()
 * \brief Create statically a List.
 * \return The new List.
 */
List List_create(){
	List This;
	List_init(&This);
	
	This.free = List_free;
	return This;
}

/**
 * \fn List* new_List()
 * \brief Create dynamically (with a malloc) a List.
 * \return The new List pointer.
 */
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
