//
// Created by Earl Leonarda on 15/02/2020.
//

int	last_index_of(char *str, char c)
{
	int	res;
	int	index;

	res = -1;
	index = 0;
	if (str)
	{
		while (str[index])
		{
			if (str[index] == c)
				res = index;
			index++;
		}
	}
	return (res);
}
