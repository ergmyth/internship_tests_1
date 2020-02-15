//
// Created by Earl Leonarda on 14/02/2020.
//

#include "task1.hpp"

static bool	countNbChr(char ch, string str, int	str_len, int index)
{
	while (index < str_len)
	{
		if (ch == str[index])
			return (true);
		index++;
	}
	return (false);
}

bool		checkBase(string base)
{
	int	len;
	int	i;

	i = 0;
	len = base.length();
	while (i < len)
	{
		if (countNbChr(base[i], base, len, i + 1))
			return (false);
		i++;
	}
	return (true);
}