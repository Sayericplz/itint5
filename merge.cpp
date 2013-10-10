/*链表结点的定义(请不要在代码中定义该类型)
struct ListNode {
  int val;
  ListNode *next;
};
*/
struct cmp{
    bool operator() ( ListNode *a, ListNode *b ){
        return a->val > b->val; 
    }
};

//lists包含k个链表的头结点,返回合并后链表头结点
ListNode* merge(vector<ListNode*> &lists) {
	priority_queue<ListNode*,vector<ListNode*>,cmp> q;
	//priority_queue<ListNode*> q;
	ListNode *head = NULL,*p;
	for(int i = 0;i < lists.size();i++)
	{
		if(lists[i])
			q.push(lists[i]);
	}
	while(!q.empty())
	{
		ListNode *r = q.top();
		q.pop();
		if(r->next) q.push(r->next);
		if(!head)
		{
			head = r;
			p = head;
		}
		else
		{
			p->next = r;
			p = p->next;
		}
	}
	return head;
}