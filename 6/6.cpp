#include <iostream>
#include <cstdio>
#include <string>


std::string convert(std::string &s, int numRows)
{
	if (numRows == 1)
	{
		return s;
	}
	std::string ans;
	int length = s.length();
	int count = numRows * 2 - 2;
	for (int i = 0; i < numRows; ++i)
	{
		int index = 0;
		while (index - i < length)
		{
			if (i > 0 && i < numRows - 1)
			{
				if (index - i > 0)
				{
					ans.push_back(s[index - i]);
				}
			}
			if (index + i < length)
			{
				ans.push_back(s[index + i]);
			}
			index += count;
		}
	}
	return ans;
}
