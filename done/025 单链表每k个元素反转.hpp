#ifndef CLASS_Solution
#define CLASS_Solution

#include "util.h"

class Solution
{
public:
	ListNode *reverseKGroup(ListNode *head, int k)
	{
		if (head == NULL || head->next == NULL || k <= 1)
			return head;

		ListNode *currStart, *currEnd;
		ListNode *nextStart, *prevEnd;

		ListNode emptyNode(0);
		prevEnd = &emptyNode;
		currStart = head;

		while (currStart)
		{
			currEnd = currStart->next;
			for (int i = 2; currEnd && i < k; i++)
				currEnd = currEnd->next;

			if (currEnd == NULL) break;
			nextStart = currEnd->next;

			reverseGroup(currStart, k);

			prevEnd->next = currEnd;
			prevEnd = currStart;

			currStart->next = nextStart;
			currStart = nextStart;
		}

		return emptyNode.next ? emptyNode.next : head;
	}

private:
	void reverseGroup(ListNode *start, int k)
	{
		ListNode *curr = start;
		ListNode *next = curr->next;
		ListNode *t;

		for (int i = 1; i < k; i++)
		{
			t = next->next;
			next->next = curr;
			curr = next;
			next = t;
		}
	}
};

#endif