#include "../../push_swap.h"

void sort_stack(t_stack *a, t_stack *b)
{
    if (a->size == 2)
        sa(a);
    else if (a->size == 3)
        sort_three(a);
    else if (a->size <= 5)
        sort_five(a, b);
    // else
    //     big_sort(a, b);
}

void sort_three(t_stack *numStack)
{
	int first;
	int second;
	int third;

	first = numStack->head->value;
	second = numStack->head->next->value;
	third = numStack->head->next->next->value;

	if((first<second) && (second<third) && (first<third))
	{
		//sorted 1 2 3
		// do nothing 
	}
	else if((first<second) && (second>third) && (first<third))
	{
		// 1 3 2
		sa(numStack);
		ra(numStack);
	}
	else if((first>second) && (second<third) && (first<third))
	{
		// 2 1 3
		sa(numStack);
	}
	else if((first<second) && (second>third) && (first>third))
	{
		// 2 3 1
		rra(numStack);
	}
	else if((first>second) && (second<third) && (first>third))
	{
		// 3 1 2
		ra(numStack);
	}
	else if((first>second) && (second>third) && (first>third))
	{
		// 3 2 1
		ra(numStack);
		sa(numStack);
	}
}




void	sort_five(t_stack *a, t_stack *b)
{
	t_node *min;

	//find 1st smallest
	while(a->size > 3)
	{
		min = stack_find_min(a);
		stack_rotate_till_reached(a, min);
		pb(a,b);
	}	

	sort_three(a);
	while(b->size > 0)
	{	
		pa(a,b);
	}	
}