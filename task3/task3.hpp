//
// Created by Earl Leonarda on 15/02/2020.
//

#ifndef TASK3_TASK3_HPP
# define TASK3_TASK3_HPP

#include <iostream>
# include <unistd.h>
# include <cstdlib>
# include <fcntl.h>
# include <string>
# include <fstream>

# define BUFF_SIZE 32000
# define ERR_GNL "Get_next_line error"
# define ERR_MALLOC "Allocation error"
# define ERR_NEGATIVE_VALUE "Value can't be negative number"
# define ERR_FILE "File cannot be opened"
# define ERR_ARGS "End time > start time"

using namespace std;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_op
{
	long long		attempts;
	long long		attempts_ok;
	long long		ok_value;
	long long		ko_value;
}					t_op;

typedef struct		s_main
{
	char			*start;
	char			*end;
	bool			start_defined;
	bool			end_defined;

	long long		volume_start;
	long long		volume_end;

	long long		barrel_volume;
	long long		cur_volume;

	t_op			*top_up;
	t_op			*scoop;
}					t_main;

void				read_file(int fd, t_main *s);
void 				create_file(t_main *s);
t_main				*init_struct(char *argv[]);

int					get_next_line(int fd, char **line);
void				ft_bzero(void *s, size_t n);
t_list				*ft_lstnew(void const *content, size_t content_size);
long long			ft_atoi(const char *str);

void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_memdel(void **ap);

char				*ft_strstr(const char *str, const char *to_find);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_strclr(char *s);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_strdel(char **as);
char				*ft_strdup(const char *src);

int					ft_check_overlap(char *d, char *s, size_t n);
void				case_of_error(const string& str);
void				ft_lstappend(t_list **alst, t_list *new_elem);
int					index_of(char *str, char c);
int					last_index_of(char *str, char c);

#endif //TASK3_TASK3_HPP
