//
// Created by Earl Leonarda on 15/02/2020.
//

#include "task3.hpp"

char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	k;
	char	*str;

	i = 0;
	k = ft_strlen(src);
	str = (char*)malloc(k + 1);
	if (str == NULL)
		return (NULL);
	str[k] = '\0';
	while (i < k)
	{
		str[i] = src[i];
		i++;
	}
	return (str);
}
