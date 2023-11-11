#include "Header.h"

std::string reverce(std::string str)
{
	std::string result = "";

	for (int i = len(str) - 1; i >= 0; i--)
		result += str[i];
	return result;
}