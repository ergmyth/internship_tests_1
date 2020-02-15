//
// Created by Earl Leonarda on 15/02/2020.
//

#include "task3.hpp"

int		ft_check_overlap(char *d, char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((s + i) == d || (d + i) == s)
			return (1);
		i++;
	}
	return (0);
}
