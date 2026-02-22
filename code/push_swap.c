#include "push_swap.h"


int is_just_number(char *str)
{
	int i;

	i=0;
	if((str[i] == '-') || (str[i] == '+'))
		i++;
	if (str[i] == '\0')
    	return (0);
	while(str[i] != '\0')
	{
		if(!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return(1);
}

void *process_and_store_num(t_stack *numList, char *str)
{
	int num;
	num = ft_atoll(str);
	if(!stack_find_node(numList, num))
		stack_push_back(numList, num);
	else
		ft_puterr_exit("Duplicate Values Present in Input\n");
}

void free_splitted_str(char **splitted_str)
{
    char **temp = splitted_str; 

    while(*temp)
    {
        free(*temp);
        temp++;
    }
    free(splitted_str); 
}
void validate_and_store(t_stack *numList, int count, char** input)
{
	int arg_index;
	char **splitted_str;
	int split_index;


	arg_index = 1;


	while((arg_index < count))
	{
		splitted_str = ft_split(input[arg_index], ' ');
		if(!splitted_str)
			ft_puterr_exit("failed splitting");
		
		split_index = 0;
		while(splitted_str[split_index])
		{
			if(is_just_number(splitted_str[split_index]))
			{
				process_and_store_num(numList, splitted_str[split_index]);
			}
			else
			{
				free_splitted_str(splitted_str);
				ft_puterr_exit("Invalid Input.\n");
			}
			split_index++;
		}
		free_splitted_str(splitted_str);

		arg_index++;
	}
}

int main(int argc, char** argv)
{
	int numCount;
	int *num;
	t_stack *stack_a;
	t_stack *stack_b;
	
	if (argc > 1)
	{
		stack_a = stack_init();
		stack_b = stack_init();

		//input validation and storing
		validate_and_store(stack_a, argc, argv);
		// ft_printf("\n\n ==start==================");
		// stack_print(stack_a);
		// ft_printf("====================\n");
		
		// ft_printf("\nsorting\n");
		sort_stack(stack_a, stack_b);
		// ft_printf("\n\n====================");
		// stack_print(stack_a);
		// ft_printf("====================\n\n");

		
		
	}
	else
	{
		ft_puterr_exit("Too Few Arguments");
	}
	return (0);
}