#include "../../push_swap.h"

void sort_stack(t_stack *a, t_stack *b)
{
    if (a->size == 2)
        sa(a);
    else if (a->size == 3)
        sort_three(a);
    // else if (a->size <= 5)
    //     sort_five(a);
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
	t_node *cur;
	t_node *min;

	min = a->head;
	cur = a->head->next;
	while(cur != a->head)
	{
		if(cur->value < min->value)
			min = cur;
		cur = cur->next;
	}

	//push min node to b..
	//find next min in a
	//push min node to b
	//sort three for a
	//pop b
	//pop b
	
}