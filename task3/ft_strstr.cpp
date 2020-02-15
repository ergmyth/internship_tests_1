//
// Created by Earl Leonarda on 15/02/2020.
//

#include "task3.hpp"

char	*ft_strstr(const char *str, const char *to_find)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (!*to_find)
		return ((char*)str);
	while (str[i])
	{
		k = 0;
		while (str[k + i] == to_find[k])
			if (++k && !to_find[k])
				return ((char*)str + i);
		i++;
	}
	return (nullptr);
}
