//
// Created by Earl Leonarda on 15/02/2020.
//

#include "task3.hpp"

void	ft_memdel(void **ap)
{
	if (ap != NULL && *ap != NULL)
	{
		free(*ap);
		*ap = NULL;
	}
}
