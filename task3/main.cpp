#include "task3.hpp"

/*
 * Не понятно, что делать с отрицательными значениями в строках с датами, так что я их обработал.
 * Также было лень обрабатывать значения превышающие long long.
 * Мог бы применить для этого длинную арифметику, если бы такое требовалось.
 */

static void	validation(t_main *s, int fd)
{
	if (ft_strcmp(s->start, s->end) >= 0)
		case_of_error(ERR_ARGS);
	if (fd == -1)
		case_of_error(ERR_FILE);
}

static void	free_structs(t_main *s)
{
	free(s->scoop);
	free(s->top_up);
	free(s);
}

int 		main(int argc, char *argv[])
{
	int 	fd;
	t_main	*s;

	if (argc == 4)
	{
		fd = open(argv[1], O_RDONLY);
		s = init_struct(argv);
		validation(s, fd);
		read_file(fd, s);
		create_file(s);
		free_structs(s);
		close(fd);
	}
	else
		cout << "Usage: <file> <start_time> <end_time>" << endl;
	return (0);
}