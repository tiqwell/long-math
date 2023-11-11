#include "Header.h"

std::string dec(std::string str1, std::string str2)
{	
	std::string result = "";
	int buf = 0, digit;
	std::string strNegative, strPositive;
	long long maxLen;
	bool needToNeg = false;

	if(str1[0] == '-')
	{
		for (int i = 1; i <= len(str1); i++)
			strNegative += str1[i];
		strPositive = str2;
	}
	else
	{
		for (int i = 1; i <= len(str2); i++)
			strNegative += str2[i];
		strPositive = str1;
	}
	if(len(strNegative) > len(strPositive) || strNegative[0] - '0' > strPositive[0] - '0')
	{
		needToNeg = true;
		std::string bufStr = strNegative;
		strNegative = strPositive;
		strPositive = bufStr;
	}
	if (len(strNegative) == len(strPositive) && strPositive[0] == strNegative[0] && strPositive[len(strPositive)] < strNegative[len(strNegative)])
	{
		needToNeg = true;
		std::string bufStr = strNegative;
		strNegative = strPositive;
		strPositive = bufStr;
	}
	strPositive = reverce(strPositive);
	strNegative = reverce(strNegative);
	maxLen = max(len(strPositive), len(strNegative));
	for (int i = len(strPositive); i < maxLen; i++)
		strPositive += '0';
	for (int i = len(strNegative); i < maxLen; i++)
		strNegative += '0';

	for(int i = 0; i <= maxLen; i++)
	{
		int dig1 = strPositive[i] - '0', dig2 = strNegative[i] - '0';
		if((strPositive[i] - '0') < (strNegative[i] - '0'))
		{
			dig1 += 10;
			int k = i + 1;
			while(strPositive[k] == 0)
			{
				strPositive[k] = 9;
				k++;
			}
			strPositive[k] -= 1;
		}
		digit = dig1;
		digit -= dig2;
		if (((digit % 10) + buf) < 10)
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
	if (needToNeg)
		result += '-';
	result = reverce(result);
	return result;
}
