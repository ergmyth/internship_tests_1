//
// Created by Earl Leonarda on 15/02/2020.
//

#include "task3.hpp"

static void	nullify(t_op *t)
{
	t->attempts = 0;
	t->ko_value = 0;
	t->ok_value = 0;
	t->attempts_ok = 0;
}

t_main	*init_struct(char *argv[])
{
	t_main	*s;

	if (!(s = (t_main*)malloc(sizeof(t_main))))
		case_of_error(ERR_MALLOC);
	s->start_defined = false;
	s->start_defined = false;
	s->barrel_volume = -1;
	s->cur_volume = -1;
	s->start = argv[2];
	s->end = argv[3];
	s->volume_end = -1;
	s->volume_start = -1;
	if (!(s->top_up = (t_op*)malloc(sizeof(t_op))))
		case_of_error(ERR_MALLOC);
	if (!(s->scoop = (t_op*)malloc(sizeof(t_op))))
		case_of_error(ERR_MALLOC);
	nullify(s->top_up);
	nullify(s->scoop);
	return (s);
}
