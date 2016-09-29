#include "list.h"

#include <stdlib.h>

static void TPile_Init(TPile *This)
{
       This->Push = TPile_Push;
       This->Pop = TPile_Pop;
       This->Clear = TPile_Clear;
       This->Length = TPile_Length;
       This->View = TPile_View;
       This->Nombre = 0;
       This->Top = NULL;
}

int List_push(List *This, const TYPE val)
{
	Node *newNode = malloc(sizeof(Node));
	
	if(!newNode) {
		return NODE_ALLOC_ERROR;
	}
	
	newNode->value = val;
	newNode->next = This->top;
	This->top = newNode;
	This->++size;
	
	return 0;
}

int TPile_Pop(TPile *This)
{
        int Val;
        Titem *tmp;
        if(!This->Top) return PILE_EMPTY;
        tmp = This->Top->prec;
        Val = This->Top->Value;
        free(This->Top);
        This->Top = tmp;
        This->Nombre--;
        return Val;
}
/******************************************************************************/
 
void TPile_Clear(TPile *This)
{
        Titem *tmp;
        while(This->Top)
          {
             tmp = This->Top->prec;
             free(This->Top);
             This->Top = tmp;
          }
        This->Nombre = 0;
}
/******************************************************************************/
 
int TPile_Length(TPile *This)
{
        return This->Nombre;
}
/******************************************************************************/
 
void TPile_View(TPile *This)
{
       Titem *tmp = This->Top;
       while(tmp)
          {
             printf("%d\n",tmp->Value);
             tmp = (*tmp).prec;
          }
}

static void List_init(List *This)
{
	This->size = 0;
	This->top = NULL; 
	This->push = List_push;
	This->pop = List_pop;
	This->clear = List_clear;
	This->length = List_length;
	This->view = List_view;      
}

void List_free(TPile *This)
{
	List_clear(This);
	puts("Destruction de la pile statique.\n");
}

void List_newFree(TPile *This)
{
	if(This) List_clear(This);
	free(This);        
	puts("Destruction de la pile dynamique.\n");
}

List List_create()
{
	List This;
	List_Init(&This);
	List.Free = List_free;
	return This;
}

List* new_List()
{
	List *This = malloc(sizeof(List));
	if(!This) return NULL;
	List_Init(This);
	This->Free = List_newFree;
	return This;
}
