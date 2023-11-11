#include "Header.h"

int main()
{
	std::string str1, str2;
	std::cin >> str1 >> str2;
	if ((str1[0] != '-' && str2[0] != '-') || (str1[0] == '-' && str2[0] == '-'))
		std::cout << add(str1, str2);
	else
		std::cout << dec(str1, str2);

}