#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

/*/////////////////////////////////////////
/////////   Manacher Algorithm   //////////
*//////////////////////////////////////////

std::string longestPalindrome(std::string &s)
{
	std::string manacherString = "@#";
	for (auto ch : s)
	{
		manacherString.push_back(ch);
		manacherString.push_back('#');
	}
	size_t size = manacherString.length();
	std::vector<int> len(size, 0);
	int mid = 0, boundary = 0;
	int maxLength = 0;
	int index = 0;
	for (int i = 1; i < size; ++i)
	{
		if (i < boundary)
		{
			len[i] = std::min(len[2 * mid - i], boundary - i);
		}
		else
		{
			len[i] = 1;
		}
		while (manacherString[i + len[i]] == manacherString[i - len[i]])
		{
			len[i]++;
		}
		if (i + len[i] > boundary)
		{
			mid = i;
			boundary = len[i] + i;
		}
		if (len[i] > maxLength)
		{
			maxLength = len[i];
			index = i;
		}
	}
	maxLength--;
	int midIndex = index / 2 - 1;
	index = midIndex - (maxLength - 1) / 2;
	std::string ans;
	for (int i = 0; i < maxLength; ++i)
	{
		ans.push_back(s[index + i]);
	}
	return ans;
}