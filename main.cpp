#include "Header.h"

int main()
{
	std::string str1, str2;
	char symbol;
	std::cin >> str1 >> symbol >> str2;
	if (symbol == '+' && str1[0] != '-' && str2[0] != '-')
		std::cout << add(str1, str2);
	//done
	if (symbol == '-' && str1[0] == '-' && str2[0] == '-') 
	{
		std::string a;
		for (int i = 1; i < len(str1); i++)
			a += str1[i];
		std::string f = dec(a, str2);
		f = reverce(f);
		f += '-';
		std::cout << reverce(f);
	}
	//done
	if(symbol == '-' && str1[0] != '-' && str2[0] == '-')
		std::cout << dec(str1, str2);
	//done
	if (symbol == '-' && str1[0] == '-' && str2[0] != '-')
	{
		std::string a;
		for (int i = 1; i < len(str1); i++)
			a += str1[i];
		std::string f = add(a, str2);
		f = reverce(f);
		f += '-';
		std::cout << reverce(f);
	}
	//done
	if (symbol == '-' && str1[0] != '-' && str2[0] != '-')
	{
		str2 = reverce(str2);
		str2 += '-';
		std::cout << dec(str1, reverce(str2));
	}
	//done
	if (symbol == '+' && str1[0] != '-' && str2[0] == '-')
		std::cout << dec(str1, str2);
	if (symbol == '+' && str1[0] == '-' && str2[0] != '-')
		std::cout << dec(str1, str2);
}
