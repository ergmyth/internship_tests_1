//
// Created by Earl Leonarda on 15/02/2020.
//

#include "task3.hpp"

static void process_value(long long value, t_op *t, t_main *s)
{
	long long	nb;

	nb = s->cur_volume + value;
	t->attempts++;
	if (nb < 0 || nb > s->barrel_volume)
		t->ko_value += value;
	else
	{
		s->cur_volume = nb;
		t->ok_value += value;
		t->attempts_ok++;
	}
}

static void	get_value(char *str, t_main *s)
{
	int			sign;
	long long	value;
	size_t		len;
	size_t		i;

	sign = (ft_strstr(str, "scoop")) ? -1 : 1;
	len = ft_strlen(str);
	i = 0;
	while (i < len && (str[i] < 48 || str[i] > 57))
		i++;
	value = ft_atoi(str + i - 1) * sign;
	if (sign == -1)
		process_value(value, s->scoop, s);
	else
		process_value(value, s->top_up, s);
}

static void	check_date(char *str, t_main *s)
{
	char		*temp;
	int 		condition;
	const int	index = index_of(str, 'Z');

	if (index == -1)
		return ;
	if (!(temp = ft_strsub(str, 0, index)))
		case_of_error(ERR_MALLOC);
	if (!s->start_defined && ft_strcmp(temp, s->start) > 0)
	{
		s->start_defined = true;
		s->volume_start = s->cur_volume;
	}
	condition = ft_strcmp(temp, s->end);
	if (condition >= 0)
		s->end_defined = true;
	if (condition <= 0)
		get_value(str + last_index_of(str, '-'), s);
	ft_strdel(&temp);
}

static void	process_str(char *str, int i, t_main *s)
{
	long long	nb;

	nb = ft_atoi(str);
	if (s->barrel_volume != -1 && s->cur_volume != -1)
		check_date(str, s);
	else if (nb < 0)
		case_of_error(ERR_NEGATIVE_VALUE);
	else if (i == 1)
		s->barrel_volume = nb;
	else if (i == 2)
		s->cur_volume = nb;
}

void	read_file(int fd, t_main *s)
{
	char	*str;
	int		ret;
	int		i;

	i = 0;
	while ((ret = get_next_line(fd, &str)))
	{
		if (ret == -1)
			case_of_error(ERR_GNL);
		if (i > 0)
			process_str(str, i, s);
		ft_strdel(&str);
		if (s->end_defined)
			break ;
		i++;
	}
	s->volume_end = s->cur_volume;
}
