//
// Created by Earl Leonarda on 15/02/2020.
//

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while ((unsigned char)s1[i] == (unsigned char)s2[i] && s2[i])
		i++;
	if ((unsigned char)s1[i] == (unsigned char)s2[i])
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
