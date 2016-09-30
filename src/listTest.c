#include <stdlib.h>
#include <stdio.h>
 
#include "List.h"
 
/*int main() {
	
	// Static
	List list = List_create();

	list.push(&list, 10);
	list.push(&list, 25);
	list.push(&list, 33);
	list.push(&list, 12);

	puts("Affichage de la pile :");
	list.view(&list);
	puts("------");

	printf("Nb d'elements : %d\n",list.length(&list));
	puts("------");

	puts("Deux valeurs soutirees de la pile :");
	printf("%d\n",list.pop(&list));
	printf("%d\n",list.pop(&list));
	puts("------");

	puts("Affichage de la pile :");
	list.view(&list);
	puts("------");

	list.clear(&list);
	list.push(&list, 18);

	puts("Affichage de la pile apres vidage et ajout d'une valeur :");
	list.view(&list);
	puts("------\n");

	list.free(&list);
	
	// Dynamic 
	
	List *list2 = new_List();

	list2->push(list2, 10);
	list2->push(list2, 25);
	list2->push(list2, 33);
	list2->push(list2, 12);

	puts("Affichage de la pile :");
	list2->view(list2);
	puts("------");

	printf("Nb d'elements : %d\n",list2->length(list2));
	puts("------");

	puts("Deux valeurs soutirees de la pile :");
	printf("%d\n",list2->pop(list2));
	printf("%d\n",list2->pop(list2));
	puts("------");

	puts("Affichage de la pile :");
	list2->view(list2);
	puts("------");

	list2->clear(list2);
	list2->push(list2, 18);

	puts("Affichage de la pile apres vidage et ajout d'une valeur :");
	list2->view(list2);
	puts("------\n");

	list2->free(list2);
	list2 = NULL;
 
	#ifdef __WIN32__
		system("PAUSE");
	#endif

	return 0;
}*/