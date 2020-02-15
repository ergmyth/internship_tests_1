#include <iostream>

using namespace std;

static int	match(const char *s1, const char *s2)
{
	if (*s1 && *s2 == '*')
		return (match(s1 + 1, s2) || match(s1, s2 + 1));
	else if (!(*s1) && !(*s2))
		return (1);
	else if (*s1 == *s2)
		return (match(s1 + 1, s2 + 1));
	else if (*s2 == '*' && !(*s1))
	{
		while (*s2 == '*')
			s2++;
		return (match(s1, s2));
	}
	return (0);
}

int 		main(int argc, char *argv[])
{
	if (argc == 3)
	{
		if (match(argv[1], argv[2]))
			cout << "OK" << endl;
		else
			cout << "KO" << endl;
	}
	return (0);
}
