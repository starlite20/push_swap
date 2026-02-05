#include "libft/libft.h"


void ft_puterr(char *str)
{
	ft_putstr_fd(str, 2);
}

int validate_input(int count, char** input)
{
	int arg_index;
	int i;
	int validity_flag;
	int numCount;
	int inNumber;

	arg_index = 1;
	validity_flag = 1;
	numCount = 0;
	inNumber = 0;

	while((arg_index < count) && (validity_flag == 1))
	{
		i = 0;
		while(input[arg_index][i] != '\0')
		{

			if(ft_isdigit(input[arg_index][i]) == 1)
			{
				if(inNumber == 0)
					inNumber = 1;
			}

			else if(input[arg_index][i] == ' ')
			{
				if(inNumber == 1)
				{
					numCount++;
					inNumber = 0;
				}
			}
			else //if((ft_isdigit(input[arg_index][i]) == 0) && input[arg_index][i] != ' ')
			{
				validity_flag = 0;
				break;
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
	return(validity_flag);
}


int main(int argc, char** argv)
{
	
	if (argc > 1)
	{
		if(validate_input(argc, argv))
		{
			ft_printf("\n == input okay \n ");
		}
		else
			ft_puterr("Error\n");		
	}
	else
	{
		ft_puterr("Error\n");
	}
	return (0);
}