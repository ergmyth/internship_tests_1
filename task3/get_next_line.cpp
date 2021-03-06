//
// Created by Earl Leonarda on 15/02/2020.
//

#include "task3.hpp"

static t_list	*add_to_list(int fd, t_list **list, char *buffer)
{
	char	*tmp;
	t_list	*elem;

	elem = *list;
	while (elem && elem->content_size != (size_t)fd)
		elem = elem->next;
	if (elem && elem->content_size == (size_t)fd)
	{
		if (*buffer)
		{
			if (!elem->content && (elem->content = ft_strdup(buffer)))
				return (elem);
			tmp = ft_strjoin((char*)elem->content, buffer);
			free(elem->content);
			elem->content = ft_strdup(tmp);
			free(tmp);
		}
		return (elem);
	}
	elem = ft_lstnew(NULL, 0);
	elem->content = ft_strdup(buffer);
	elem->content_size = (size_t)fd;
	ft_lstappend(list, elem);
	return (elem);
}

static int		find_n(t_list *elem, char **line, char *buffer)
{
	int		n_ind;
	char	*begin;
	int		size;

	if (!elem->content && !*buffer && (*line = (char*)"\0"))
		return (0);
	size = ft_strlen((char*)elem->content);
	n_ind = index_of((char*)elem->content, '\n');
	if (n_ind == -1 && !*buffer)
		n_ind = size;
	if (n_ind == -1)
		return (2);
	*line = ft_strsub((char*)elem->content, 0, n_ind);
	size = size - n_ind - 1;
	begin = ft_strdup((char*)elem->content);
	free(elem->content);
	elem->content = NULL;
	if (size > 0)
		elem->content = ft_strsub(begin, (unsigned int)n_ind + 1, size);
	free(begin);
	if (elem->content || *buffer || *line)
		return (1);
	return (0);
}

int				get_next_line(int fd, char **line)
{
	char			buffer[BUFF_SIZE + 1];
	int				result;
	static t_list	*list;

	if (BUFF_SIZE < 1 || !line || fd < 0 || read(fd, buffer, 0) < 0)
		return (-1);
	ft_bzero(buffer, BUFF_SIZE + 1);
	while (1)
	{
		if (read(fd, buffer, BUFF_SIZE) == 0)
			ft_strclr(buffer);
		if (!list && (list = ft_lstnew(NULL, 0)))
			list->content_size = fd;
		result = find_n(add_to_list(fd, &list, buffer), line, buffer);
		if (*buffer)
			ft_strclr(buffer);
		if (result != 2)
			return (result);
	}
}
