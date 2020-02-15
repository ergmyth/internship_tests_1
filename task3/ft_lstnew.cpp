//
// Created by Earl Leonarda on 15/02/2020.
//

#include "task3.hpp"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	tmp = (t_list*)malloc(sizeof(t_list));
	if (tmp)
	{
		if (content)
		{
			tmp->content = malloc(content_size);
			if (!(tmp->content))
			{
				free(tmp);
				return (nullptr);
			}
			tmp->content = ft_memcpy(tmp->content, content, content_size);
			tmp->content_size = content_size;
		}
		else
		{
			tmp->content_size = 0;
			tmp->content = nullptr;
		}
		tmp->next = nullptr;
		return (tmp);
	}
	return (nullptr);
}
