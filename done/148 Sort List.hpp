#ifndef CLASS_Solution
#define CLASS_Solution

#include "util.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(NULL) {}
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode *sortList(ListNode *head)
	{
		if (head == NULL)
			return NULL;
		else if (head->next == NULL)
			return head;
		else if (head->next->next == NULL)
		{
			if (head->next->val < head->val)
			{
				int t = head->val;
				head->val = head->next->val;
				head->next->val = t;
			}
			return head;
		}

		ListNode *fast, *slow;
		fast = slow = head;

		while (fast->next != NULL)
		{
			fast = fast->next;
			if (fast->next != NULL)
			{
				fast = fast->next;
				slow = slow->next;
			}
		}

		ListNode *head1 = slow->next;
		slow->next = NULL;
		head  = sortList(head);
		head1 = sortList(head1);
		return merge(head, head1);
	}

private:
	ListNode* merge(ListNode *h1, ListNode *h2)
	{
		if (h1 == NULL)
			return h2;
		else if (h2 == NULL)
			return h1;

		ListNode node(0);     // 空头节点
		ListNode *h = &node;

		while (h1 && h2)
		{
			if (h1->val < h2->val)
			{
				h->next = h1;
				h1 = h1->next;
			}
			else
			{
				h->next = h2;
				h2 = h2->next;
			}
			h = h->next;
		}
		h->next = (h1 != NULL) ? h1 : h2;

		return node.next;
	}
};

#endif