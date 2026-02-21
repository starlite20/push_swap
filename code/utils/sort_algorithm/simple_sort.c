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


t_node *find_spot_in_b(t_stack *b, int value_to_push)
{
	t_node *target_spot;
	t_node *cur;

	//if b is empty, this is the first value to push.. so no rotation.
	if(!b || b->size == 0)
		return NULL;

	target_spot = NULL;
	cur = b->head;

	int nodes_traversed = 0;
	while(nodes_traversed < b->size)
	{
		//go through each element
		// if the current value is less than the value to push... it means this is could be a potential node after which the new value to push should appear
		if(cur->value < value_to_push)
		{
			// if targetspot is null, it means its the first value we are checking, so we set to targetspot
			// we verify if the value in targetspot is lesser than the current value traversing... 
			// this would mean that the current value is larger than the target we have, and refers that this current is closer to the value to push... so we update  it.
			if(!target_spot || (target_spot->value < cur->value))
			{
				target_spot = cur;
			}
		}
		cur = cur->next;
		nodes_traversed++;
	}

	// if null, it means it found no smaller number, indicating that value is the smallest one.
	if(!target_spot)
	{
		target_spot = stack_find_min(b);
	}

	return(target_spot);
}

void pb_in_right_spot(t_stack *a, t_stack *b)
{
	//each push to stack b should be in the right spot... ensuring descending order of num
	int value = a->head->value;
	t_node *push_before_this;

	push_before_this = find_spot_in_b(b, value);
	if(push_before_this != NULL)
		stack_rotate_till_reached(b, push_before_this);

	pb(a,b);
}

t_node *find_cheapest_node_in_chunk(t_stack *stack, int low_val, int high_val)
{
	t_node *cur;
	cur = stack->head;

	t_node *min_cost_node;
	min_cost_node = NULL;

	int min_cost;
	min_cost = INT_MAX;

	int nodes_traversed = 0;
	int cost_of_node;


	while(nodes_traversed < stack->size)
	{
		if((cur->value >= low_val) && (cur->value <= high_val))
		{
			cost_of_node = stack_node_distance(stack, cur);
			if(min_cost > cost_of_node)
			{
				min_cost = cost_of_node;
				min_cost_node = cur;
			}
		}
		cur = cur->next;
		nodes_traversed++;
	}

	return(min_cost_node);
}

void turk_sort(t_stack *a, t_stack *b)
{
	int chunk_size = 20;
	int low_val;
	int high_val;

	low_val = stack_find_min(a)->value;
	high_val = low_val + chunk_size;

	t_node *node_to_push;

	while(a->size > 0)
	{
		node_to_push = find_cheapest_node_in_chunk(a, low_val, high_val);
		if(node_to_push)
		{
			stack_rotate_till_reached(a, node_to_push);
			pb_in_right_spot(a,b);
		}
		else
		{
			low_val = high_val + 1;
			high_val = low_val + chunk_size;
		}
	}
	
	while(b->size>0)
	{
		pa(a,b);
	}

}