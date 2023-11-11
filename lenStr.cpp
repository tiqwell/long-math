#include "Header.h"

long long len(std::string str)
{
	int a = 0;
	while (str[a] != '\0')
		a++;
	return a;
}