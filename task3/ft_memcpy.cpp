//
// Created by Earl Leonarda on 15/02/2020.
//

#include "task3.hpp"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	d = (char*)dst;
	s = (char*)src;
	i = 0;
	if (!dst && !src)
		return (nullptr);
	if (ft_check_overlap(d, s, n) == 1)
		return (ft_memmove(dst, src, n));
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
