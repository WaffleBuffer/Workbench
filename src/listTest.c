#include <stdlib.h>
#include <stdio.h>
 
#include "List.h"
 
int main()
{
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

	return 0;
}