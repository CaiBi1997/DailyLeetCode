#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>


double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
{
	double ans = 0.0;
	size_t lIndex = 0, lSize = nums1.size();
	size_t rIndex = 0, rSize = nums2.size();
	size_t m = lSize + rSize;
	size_t c = (lSize + rSize) / 2 + 1;
	int flag = 0;
	for (size_t i = 0; i < c; ++i)
	{
		int l = INT_MAX;
		int r = INT_MAX;
		if (lIndex < lSize)
		{
			l = nums1[lIndex];
		}
		if (rIndex < rSize)
		{
			r = nums2[rIndex];
		}
		int k;
		if (l <= r)
		{
			k = l;
			lIndex++;
		}
		else
		{
			k = r;
			rIndex++;
		}
		if (m / 2 == i || (m - 1) / 2 == i)
		{
			flag++;
			ans += k;
		}
	}
	return ans / flag;
}
