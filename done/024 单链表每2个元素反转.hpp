#ifndef CLASS_Solution
#define CLASS_Solution

#include "util.h"

class Solution
{
public:
	ListNode* swapPairs(ListNode *head)
	{
		ListNode *p1, *p2, *q1, *prev;

		ListNode empty(0);
		prev = &empty;
		p1 = head;

		while (p1 && p1->next)
		{
			prev->next = p2 = p1->next;
			q1 = p2->next;
			prev = p2->next = p1;
			p1 = q1;
		}
		prev->next = p1;

		return empty.next;
	}
};

#endif