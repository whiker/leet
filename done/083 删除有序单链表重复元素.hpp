#ifndef CLASS_Solution
#define CLASS_Solution

#include "util.h"

class Solution
{
public:
	ListNode *deleteDuplicates(ListNode *head)
	{
		if (head == NULL)
			return NULL;

		ListNode *curr = head;
		ListNode *next = curr->next;

		while (next)
		{
			if (next->val == curr->val)
				next = next->next;
			else
			{
				curr->next = next;
				curr = next;
				next = curr->next;
			}
		}

		curr->next = next;
		return head;
	}
};

#endif