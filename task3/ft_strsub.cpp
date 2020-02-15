//
// Created by Earl Leonarda on 15/02/2020.
//

#include "task3.hpp"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	index;

	index = 0;
	if (s)
	{
		substr = (char*)malloc(len + 1);
		if (!substr)
			return (nullptr);
		substr[len] = '\0';
		while (index < len)
		{
			substr[index] = s[start + index];
			index++;
		}
		return (substr);
	}
	return (nullptr);
}
