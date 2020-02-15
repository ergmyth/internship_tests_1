//
// Created by Earl Leonarda on 14/02/2020.
//

#include "task1.hpp"

static size_t	char2nb(unsigned char chr, string baseSrc, int baseSrc_len)
{
	for (int i = 0; i < baseSrc_len; i++)
		if (baseSrc[i] == chr)
			return (i);
}

static size_t	string2nb(string nb, string baseSrc, int baseSrc_len)
{
	int		step;
	int		str_len;
	size_t	res;

	step = 0;
	str_len = nb.length();
	res = 0;
	while (--str_len > -1)
		res += char2nb(nb[str_len], baseSrc, baseSrc_len) * pow(baseSrc_len, step++);
	return (res);
}

static string	ft_itoa(size_t nb, string baseDst)
{
	string	res;
	int		baseDst_int;
	int 	res_len;
	size_t	temp;

	res_len = 1;
	temp = nb;
	baseDst_int = baseDst.length();
	while (temp /= baseDst_int)
		res_len++;
	res[--res_len] = baseDst[nb % baseDst_int];
	while (nb /= baseDst_int)
		res[--res_len] = baseDst[nb % baseDst_int];
	return (res);
}

string			itoBase(string nb, string baseSrc, string baseDst)
{
	size_t	baseSrc_len;
	string	str;
	size_t	dec;

	baseSrc_len = baseSrc.length();
	dec = string2nb(nb, baseSrc, baseSrc_len);
	str = ft_itoa(dec, baseDst);
	return (str);
}
