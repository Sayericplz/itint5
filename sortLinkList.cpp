ListNode* merge(ListNode *h1,ListNode *h2)
{
	ListNode *head = NULL, *p;
	while(h1 && h2)
	{
		if(h1->val <= h2->val)
		{
			if(!head)
			{
				head = h1;
				p = head;
			}
			else
			{
				p->next = h1;
				p = p->next;
			}
			h1 = h1->next;
		}
		else
		{
			if(!head)
			{
				head = h2;
				p = head;
			}
			else
			{
				p->next = h2;
				p = p->next;
			}
			h2 = h2->next;
		}
	}
	if(!h1) p->next = h2;
	else p->next = h1;
	return head;
}

ListNode* sortLinkList(ListNode *head) {
	if(!head || !head->next) return head;
	ListNode *fast = head, *slow = head,*pre;
	while(fast && fast->next)
	{
		pre = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	pre->next = NULL;
	pre = sortLinkList(head);
	slow = sortLinkList(slow);
	return merge(pre,slow);
}

