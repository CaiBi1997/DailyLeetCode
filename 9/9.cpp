#include <cstdio>
#include <cstring>
#include <iostream>


bool isPalindrome(int x)
{
	char buf[64];
	sprintf(buf, "%d", x);
	int len = strlen(buf);
	int index = 0;
	int end = len - 1;
	while (index < end)
	{
		if (buf[index] != buf[end])
		{
			return false;
		}
		++index;
		--end;
	}
	return true;
}
