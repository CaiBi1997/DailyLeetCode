#include <cstdio>
#include <climits>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>


std::vector<int> twoSum(vector<int>& nums, int target)
{
	std::vector<int> ans;
	std::map<int, int> kv;
	size_t size = nums.size();
	for (size_t i = 0; i < size; ++i)
	{
		kv[nums[i]] = i;
	}
	for (size_t i = 0; i < size; ++i)
	{
		int n = target - nums[i];
		auto it = kv.find(n);
		if (it != kv.end() && i != it->second)
		{
			ans.push_back(i);
			ans.push_back(it->second);
			break;
		}
	}
	return ans;
}
