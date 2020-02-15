//
// Created by Earl Leonarda on 14/02/2020.
//

#include "task1.hpp"

int main(int argc, char *argv[])
{
	string	res;
	string	baseSrc;
	string	baseDst;
	string	nb;

	if (argc == 4)
	{
		nb = argv[1];
		baseSrc = argv[2];
		baseDst = argv[3];
		if (checkBase(baseSrc) && checkBase(baseDst) && checkNb(nb, baseSrc))
		{
			res = itoBase(nb, baseSrc, baseDst);
			cout << res.c_str() << endl;
		}
		else
			cout << USAGE << endl;
	}
	else
		cout << USAGE << endl;
    return (0);
}
