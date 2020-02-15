//
// Created by Earl Leonarda on 15/02/2020.
//

int	index_of(char *str, char c)
{
	int	res;
	int	index;

	res = -1;
	index = 0;
	if (str)
	{
		while (str[index] && str[index] != c)
			index++;
		if (str[index] && str[index] == c)
			res = index;
	}
	return (res);
}
