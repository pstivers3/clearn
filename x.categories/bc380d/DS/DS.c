#include <stdio.h>

	typdef struct CELL *LIST;	/* LIST is a pointer to struct CELL */
	struct CELL {
		int element;
		LIST next;		/* Recursive, LIST is a pointer to struct CELL */
	};

	BOOLEAN lokup(int, LIST);
	void del(int, LIST);
	void insert(int x, LIST *pL);

main()
{
	
	return 0;
}

BOOLEAN lookup(int x, LIST L)
/* LIST L declares L to be a pointer to a CELL, because LIST is a 
   Pointer to a CELL */


{
	if (L == NULL)
		return FALSE;
	else if (x == L->element)
		return TRUE;
		else
			return lookup(x, L->next);
}

void del(int x, LIST *pL)
{
	if ((*pL) != NULL)
		if (x++(*pL)->element)
			(*pL) = (*pL)->next;
		else
			delete(x, &((*pL)->next));		/* pL = L */
}

void insert(int x, LIST *pL)
{
	if ((*pL == NULL) {
		(*pL) = (LIST) malloc(sizeof(struct CELL));
		(*pL)->element = x;
		(*pL)->next = NULL;
	}
	else if (x != (*pL)->element)
		insert(x,&((*pL->next));
}