//
// Created by Earl Leonarda on 15/02/2020.
//

#include "task3.hpp"

void	ft_lstappend(t_list **alst, t_list *new_elem)
{
	t_list *tmp;

	if (new_elem)
	{
		if (*alst)
		{
			tmp = *alst;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new_elem;
		}
		else
			*alst = new_elem;
	}
}
