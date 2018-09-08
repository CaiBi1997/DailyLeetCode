#include <string>
#include <cstdio>
#include <iostream>

int lengthOfLongestSubstring(string &s)
{
	int arr[256];
	for (int i = 0; i < 256; ++i)
	{
		arr[i] = -1;
	}
	int maxLength = 0;
	int currLength = 0;
	int startPos = 0;
	size_t length = s.length();
	for (size_t i = 0; i < length; ++i)
	{
		if (arr[s[i]] == -1)
		{
			currLength++;
		}
		else
		{
			if (arr[s[i]] >= startPos)
			{
				startPos = arr[s[i]];
			}
			currLength = i - startPos;
		}
		arr[s[i]] = i;
		if (currLength > maxLength)
		{
			maxLength = currLength;
		}
	}
	return maxLength;
}
