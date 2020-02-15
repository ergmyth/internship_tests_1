//
// Created by Earl Leonarda on 15/02/2020.
//

#include "task3.hpp"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*str;
	size_t	t;

	if (s1 && s2)
	{
		size = ft_strlen(s1) + ft_strlen(s2);
		str = (char*)malloc(size + 1);
		if (!str)
			return (nullptr);
		str[size] = '\0';
		t = 0;
		while (s1[t])
		{
			str[t] = s1[t];
			t++;
		}
		size = t;
		t = 0;
		while (s2[t] && (str[size + t] = s2[t]))
			t++;
		return (str);
	}
	return (nullptr);
}
