#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

int reverse(int x)
{
	std::string num = std::to_string(x);
	int index = 0;
	if (x < 0)
	{
		index = 1;
	}
	std::reverse(num.begin() + index, num.end());
	long long n = std::stoll(num);
	if (n > INT_MAX || n < INT_MIN)
	{
		return 0;
	}
	return static_cast<int>(n);
}
