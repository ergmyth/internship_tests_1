//
// Created by Earl Leonarda on 15/02/2020.
//

#include "task3.hpp"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}
