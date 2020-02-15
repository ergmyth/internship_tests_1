//
// Created by Earl Leonarda on 15/02/2020.
//

#include "task3.hpp"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	i = 0;
	if (!dst && !src)
		return (nullptr);
	if (s < d)
		while (++i <= len)
			*(d + len - i) = *(s + len - i);
	else
		while (len--)
			*(d++) = *(s++);
	return (dst);
}
