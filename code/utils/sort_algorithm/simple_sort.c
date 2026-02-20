#include "../../push_swap.h"

void sort_three(t_stack *numStack)
{
	int a;
	int b;
	int c;

	a = numStack->head;
	b = numStack->head->next;
	c = numStack->head->next->next;

	if((a<b) && (b<c) && (a<c))
	{
		//sorted 1 2 3
		// do nothing 
	}
	else if((a<b) && (b>c) && (a<c))
	{
		// 1 3 2
 		// sa ra
	}
	else if((a>b) && (b<c) && (a<c))
	{
		// 2 1 3
		// sa
	}
	else if((a<b) && (b>c) && (a>c))
	{
		// 2 3 1
		// rra
	}
	else if((a>b) && (b<c) && (a>c))
	{
		// 3 1 2
		// ra
	}
	else if((a>b) && (b>c) && (a>c))
	{
		// 3 2 1
		// ra sa
	}
	



}