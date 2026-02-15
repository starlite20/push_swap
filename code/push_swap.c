#include "push_swap.h"



int validate_input(int count, char** input)
{
	int arg_index;
	int i;
	int numCount;
	int inNumber;
	int inSign;
	int startPt;

	arg_index = 1;
	numCount = 0;
	inNumber = 0;
	inSign = 0;
	startPt = 0;

	while((arg_index < count))
	{
		i = 0;
		while(input[arg_index][i] != '\0')
		{

			if(ft_isdigit(input[arg_index][i]) == 1)
			{
				if(inNumber == 0)
				{
					inNumber = 1;
					inSign = 0;
					startPt = i;
				}
			}
			else if((input[arg_index][i] == '+') || (input[arg_index][i] == '-'))
			{
				if((inSign == 0) && (inNumber == 0))
				{
					inNumber = 1;
					inSign = 1;
				}
				else if((inSign == 0) && (inNumber == 1))
					ft_puterr_exit("Sign inbetween digits.\n");
				else if(inSign == 1)
					ft_puterr_exit("Too many signs.");
			}

			else if(input[arg_index][i] == ' ')
			{
				if(inNumber == 1)
				{
					// ft_printf("\n\n number start index : %d", startPt);
					// store_number(&input[arg_index][startPt], i - startPt);
					numCount++;
					inNumber = 0;
					inSign = 0;
				}
			}
			else //if((ft_isdigit(input[arg_index][i]) == 0) && input[arg_index][i] != ' ')
			{
				ft_puterr_exit("Invalid Character present in Input.");
			}

			if(input[arg_index][i + 1] == '\0')
			{
				if(inNumber == 1)
				{
					// ft_printf("\n\n number start index : %d", startPt);
					// store_number(&input[arg_index][startPt], (i+1) - startPt);
					numCount++;
					inNumber = 0;
				}
			}
			i++;
		}
		arg_index++;
	}
	return (numCount);
}



void *store_number(t_stack *numList, int totalNumCount, int count, char** input)
{
	int arg_index;
	int i;
	int numIndex;
	int inNumber;
	int startPt;
	int temp;

	if(!numList)
		ft_puterr_exit("List Creation Failure.");

	arg_index = count - 1;
	numIndex = 0;
	inNumber = 0;
	startPt = 0;

	while((arg_index >= 0))
	{
		i = ft_strlen(input[arg_index]) - 1;
		while(input[arg_index][i] >= 0)
		{
			if((ft_isdigit(input[arg_index][i]) == 1) || (input[arg_index][i] == '+') || (input[arg_index][i] == '-'))
			{
				if(inNumber == 0)
				{
					inNumber = 1;
					startPt = i;
				}
			}

			else if(input[arg_index][i] == ' ')
			{
				if(inNumber == 1)
				{
					temp = ft_atoi(ft_substr(input[arg_index], startPt, i-startPt));
					stack_push(numList, temp);
					inNumber = 0;
				}
			}

			i--;
		}
		arg_index--;
	}


	ft_printf("\n\n=======\n");
	stack_print(numList);
}


// int *store_number(t_stack *numList, int totalNumCount, int count, char** input)
// {
// 	int *numArray;

// 	numArray = malloc(sizeof(int *) * totalNumCount);
// 	if(!numArray)
// 		return NULL;

// 	int arg_index;
// 	int i;
// 	int numIndex;
// 	int inNumber;
// 	int startPt;

// 	arg_index = 1;
// 	numIndex = 0;
// 	inNumber = 0;
// 	startPt = 0;

// 	while((arg_index < count))
// 	{
// 		i = 0;
// 		while(input[arg_index][i] != '\0')
// 		{
// 			if((ft_isdigit(input[arg_index][i]) == 1) || (input[arg_index][i] == '+') || (input[arg_index][i] == '-'))
// 			{
// 				if(inNumber == 0)
// 				{
// 					inNumber = 1;
// 					startPt = i;
// 				}
// 			}

// 			else if(input[arg_index][i] == ' ')
// 			{
// 				if(inNumber == 1)
// 				{
// 					// ft_printf("\n storing : %s at %d", &input[arg_index][startPt], numIndex);
// 					numArray[numIndex++] = ft_atoi(ft_substr(input[arg_index], startPt, i-startPt));
// 					inNumber = 0;
// 				}
// 			}

// 			if(input[arg_index][i + 1] == '\0')
// 			{
// 				if(inNumber == 1)
// 				{
// 					// ft_printf("\n storing : %s at %d", &input[arg_index][startPt], numIndex);
// 					numArray[numIndex++] = ft_atoi(ft_substr(input[arg_index], startPt, (i+1)-startPt));
// 					inNumber = 0;
// 				}
// 			}
// 			i++;
// 		}
// 		arg_index++;
// 	}


// 	ft_printf("\n\n=======\n");
// 	for(int n=0; n < totalNumCount; n++)
// 	{
// 		ft_printf("\t  '%d'  ", n, numArray[n]);
// 	}

// 	return (numArray);
// }


int main(int argc, char** argv)
{
	int numCount;
	int *num;
	t_stack *numList;
	
	if (argc > 1)
	{
		numCount = validate_input(argc, argv);
		ft_printf("\n == input okay \n ");
		// ft_printf("\n\t == numbers found = %d\n", numCount);
		
		numList = stack_init();
		store_number(numList, numCount, argc, argv);


	}
	else
	{
		ft_puterr_exit("Too Few Arguments");
	}
	return (0);
}