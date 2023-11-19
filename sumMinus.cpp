#include "Header.h"

std::string dec(std::string str1, std::string str2)
{	
	std::string result = "";
	int buf = 0, digit;
	std::string strNegative, strPositive;
	long long maxLen;
	bool needToNeg = false;
	bool ghj = false;
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
	maxLen = max(len(strPositive), len(strNegative));
	if(len(strPositive) < len(strNegative))
	{
		std::string qwe = strNegative;
		strNegative = strPositive;
		strPositive = qwe;
		needToNeg = 1;
	}
	else if(len(strPositive) == len(strNegative))
	{
		for(int i = 0; i <= maxLen; i++)
		{
			if (strPositive[i] - '0' < strNegative[i] - '0')
			{
				std::string qwe = strNegative;
				strNegative = strPositive;
				strPositive = qwe;
				needToNeg = 1;
			}
		}
	}
	strPositive = reverce(strPositive);
	strNegative = reverce(strNegative);
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
	for(int i = 0; i <= len(result); i++)
	{
		if(result[i] != '0')
		{
			ghj = 1;
		}
	}

	if (ghj)
	{
		result = reverce(result);
		int l = 0;
		while (result[l] == '0')
		{
			l++;
		}
		std::string resultUpd;
		for (int i = l; i <= len(result); i++)
			resultUpd += result[i];
		resultUpd = reverce(resultUpd);
		if (needToNeg)
			resultUpd += '-';
		return reverce(resultUpd);
	}
	else
		return "0";
	if (needToNeg)
		result += '-';
	result = reverce(result);
	return result;
}
