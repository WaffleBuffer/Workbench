/**
 * \file list.h
 * \brief Declaration of List struct.
 * \author Thomas MEDARD, Remi SEGRETAIN
 */

#include "Utils.c"

#include <stdlib.h>

#ifndef LIST__H
#define LIST__H

/**
 * \class List list.h
 * \brief A chained list.
 */

/**
 * \def NODE_ALLOC_ERROR
 * \brief Error value when malloc failed.
 */
#define NODE_ALLOC_ERROR -2

/**
 * \def LIST_EMPTY
 * \brief Error value when try to pop an empty List.
 */
#define LIST_EMPTY -1

#ifdef __cplusplus
	extern "C" {
#endif

/**
 * \struct Node list.h
 * \brief Node contained inside a List. A Node has a value and a next.
 */
typedef struct Node {
	TYPE value;
	struct Node *next;
} Node;

/**
 * \struct List list.h
 * \brief A chained list. Contains a size and a pointer to the first Node.
 */
typedef struct List {
	size_t size;
	struct Node *top;	
	
	/**
	 * \fn int List_push(List *This, const TYPE val)
	 * \brief Push the list to add a new node with a value.
	 * \param[in, out] This The List to add into.
	 * \param[in] val The value to add.
	 * \return 0 if no error detected. See list.h for error values.
	 */
	int(*push)(struct List*, const TYPE);

	/**
	 * \fn TYPE List_pop(List *This)
	 * \brief Pop a value from a List. Delete from the List and return the last value.
	 * \param[in, out] This The List to pop from.
	 * \return The value poped.
	 */
	TYPE(*pop)(struct List*);

	/**
	 * \fn void List_clear(List *This)
	 * \brief Free all values from a List.
	 * \param[in, out] This The List to free.
	 */
	void(*clear)(struct List*);

	/**
	 * \fn void List_free(List *This)
	 * \brief Free all values from a List. but not List itself.
	 * \param[in, out] This The List to free.
	 */
	void(*free)(struct List*);

	/**
	 * \fn int List_length(List *This)
	 * \brief Get the current size/length of a List.
	 * \param[in, out] This The List to free.
	 * \return The current size/length of a List.
	 */
	int(*length)(struct List*);

	/**
	 * \fn void List_view(List *This)
	 * \brief Display the List on the standard output.
	 * \param[in, out] This The List to display.
	 * \bug Problems on the display.
	 */
	void(*view)(struct List*);
}List;

/**
 * \fn List List_create()
 * \brief Create statically a List.
 * \return The new List.
 */
List List_create(void);

/**
 * \fn void List_newFree(List *This)
 * \brief Free all values from a List with List itslef.
 * \param[in, out] This The List to free.
 */
List* new_List(void);

#ifdef __cplusplus
}
#endif

#endif /* LIST__H */
