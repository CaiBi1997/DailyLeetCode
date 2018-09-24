#include <cstdio>
#include <cctype>
#include <iostream>
#include <string>
int myAtoi(const std::string &str)
{
	std::string numStr;
	std::string maxInt = "2147483647";
	std::string minInt = "-2147483648";
	bool flag = false, blank = false, zero = false, sign = false;
	for (auto it = str.begin(); it != str.end(); ++it)
	{
		char ch = *it;
		if (ch == ' ' && blank == false)
		{
			continue;
		}
		if (ch == '0' && zero == false)
		{
			sign = true;
			blank = true;
			continue;
		}
		else if (ch == '+' && sign == false)
		{
			blank = true;
			sign = true;
		}
		else if (ch == '-' && sign == false)
		{
			blank = true;
			sign = true;
			numStr.push_back('-');
		}
		else if (std::isdigit(ch))
		{
			blank = true;
			flag = true;
			zero = true;
			sign = true;
			numStr.push_back(ch);
		}
		else
		{
			break;
		}
	}
	if (!flag)
	{
		return 0;
	}
	int value = 0;
	int radix = 1;
	auto end = numStr.rend();
	if (numStr[0] == '-')
	{
		if ((numStr.length() == minInt.length() && numStr > minInt) || numStr.length() > minInt.length())
		{
			return INT_MIN;
		}
		end--;
		radix = -1;
	}
	else
	{
		if ((numStr.length() == maxInt.length() && numStr > maxInt) || numStr.length() > maxInt.length())
		{
			return INT_MAX;
		}
	}
	for (auto it = numStr.rbegin(); it != end; ++it)
	{
		value += radix * (*it - '0');
		radix *= 10;
	}
	return value;
}
