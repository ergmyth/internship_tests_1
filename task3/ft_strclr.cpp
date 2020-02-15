//
// Created by Earl Leonarda on 15/02/2020.
//

void	ft_strclr(char *s)
{
	if (s)
		while (*s)
		{
			*s = '\0';
			s++;
		}
}
