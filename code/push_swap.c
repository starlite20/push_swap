#include "push_swap.h"


void validate_input(int count, char** input)
{
	int arg_index;
	int i;
	int numCount;
	int inNumber;
	int inSign;

	arg_index = 1;
	numCount = 0;
	inNumber = 0;
	inSign = 0;

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
					numCount++;
					inNumber = 0;
				}
			}
			i++;
		}
		arg_index++;
	}
	ft_printf("\n\t == numbers found = %d\n", numCount);
}




int main(int argc, char** argv)
{
	
	if (argc > 1)
	{
		validate_input(argc, argv);
		ft_printf("\n == input okay \n ");
	}
	else
	{
		ft_puterr_exit("Too Few Arguments");
	}
	return (0);
}