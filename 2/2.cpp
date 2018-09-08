#include <cstdio>
#include <climits>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode *p = nullptr;
	ListNode *head = nullptr;
	int flag = 0;
	while (l1 || l2 || flag)
	{
		int v1 = 0, v2 = 0;
		if (l1)
		{
			v1 = l1->val;
			l1 = l1->next;
		}
		if (l2)
		{
			v2 = l2->val;
			l2 = l2->next;
		}
		int x = v1 + v2 + flag;
		flag = x / 10;
		ListNode *node = new ListNode(x % 10);
		if (p)
		{
			p->next = node;
		}
		else
		{
			p = node;
			head = node;
		}
		p = node;
	}
	return head;
}
