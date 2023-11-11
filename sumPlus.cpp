#include "Header.h"

std::string add(std::string str1, std::string str2)
{
	std::string result = "";
	int buf = 0, digit;
	long long maxLen;
	maxLen = max(len(str1), len(str2));
	str1 = reverce(str1);
	str2 = reverce(str2);
	for (int i = len(str1); i < maxLen; i++)
		str1 += '0';
	for (int i = len(str2); i < maxLen; i++)
		str2 += '0';
	for(int i = 0; i < maxLen; i++)
	{
		digit = 0;
		digit += str1[i] - '0';
		digit += str2[i] - '0';
		if(((digit % 10) + buf) < 10)
		{
			result += '0' + ((digit % 10) + buf);
			buf = digit / 10;

		}
		else
		{
			result += '0' + (((digit % 10) + buf) % 10);
			buf = digit / 10;
			buf++;
		}
	}
	if (buf != 0) 
		result += buf + '0';
	result = reverce(result);
	return result;
}