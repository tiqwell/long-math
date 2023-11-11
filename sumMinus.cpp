#include "Header.h"
std::string dec(std::string str1, std::string str2)
{
	std::string result = "";
	int buf = 0, digit, digit1, digit2, posOfNext;
	long long maxLen;
	maxLen = max(len(str1), len(str2));
	str1 = reverce(str1);
	str2 = reverce(str2);
	for (int i = len(str1); i < maxLen; i++)
		str1 += '0';
	for (int i = len(str2); i < maxLen; i++)
		str2 += '0';
	for (int i = 0; i < maxLen; i++)
	{
		digit1 = (str1[i] + '0');
		digit2 = (str2[i] + '0');
		if (str1[i] < str2[i])
		{
			posOfNext = i + 1;
			while (str1[posOfNext] == '0')
			{
				str1[posOfNext] = '9';
				posOfNext++;
			}
			str1[posOfNext + 1] = (((str1[posOfNext + 1] + '0') - 1) + '0');
			digit1 += 10;s
		}
		digit = digit1 - digit2;
		result += digit % 10 + '0';
		buf = digit / 10;
	}
	if (buf != 0)
		result += buf + '0';
	result = reverce(result);
	return result;
}
