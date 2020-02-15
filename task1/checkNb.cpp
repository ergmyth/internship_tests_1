//
// Created by Earl Leonarda on 14/02/2020.
//

#include "task1.hpp"

bool	checkNb(string nb, string base)
{
	int	nb_len;
	int base_len;

	nb_len = nb.length();
	base_len = base.length();
	for (int i = 0; i < nb_len; i++)
	{
		int k;
		for (k = 0; k < base_len; k++)
		{
			if (nb[i] == base[k])
			{
				k = -1;
				break ;
			}
		}
		if (k != -1)
			return (false);
	}
	return (true);
}
