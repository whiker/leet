#include "util.h"

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		if (l1 == NULL)
			return l2;
		else if (l2 == NULL)
			return l1;

		ListNode *p1=l1, *p2=l2, *p3;
		int carry = 0, t;

		while (p1 != NULL && p2 != NULL)
		{
			t = p1->val + p2->val + carry;
			p1->val = t%10;
			carry = t/10;
			p3 = p1;
			p1 = p1->next;
			p2 = p2->next;
		}

		if (p2 != NULL)
		{
			p3->next = p2;
			p1 = p2;
		}

		while (carry > 0 && p1 != NULL)
		{
			t = p1->val + carry;
			p1->val = t%10;
			carry = t/10;
			p3 = p1;
			p1 = p1->next;
		}
		if (carry > 0)
			p3->next = new ListNode(carry);

		return l1;
	}
};