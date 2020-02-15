//
// Created by Earl Leonarda on 15/02/2020.
//

#include "task3.hpp"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *str;

	if (len)
	{
		str = (unsigned char*)b;
		while (len)
		{
			*str = (unsigned char)c;
			str++;
			len--;
		}
	}
	return (b);
}
