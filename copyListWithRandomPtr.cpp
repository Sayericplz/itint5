/**
链表结点的定义(请不要在代码中定义该类型)
struct ListNode {
    ListNode *next;
    ListNode *random;
};
*/
// 返回复制的新链表头结点
ListNode* copyListWithRandomPtr(ListNode *head) {  
    if ( !head )   
        return head;  
    ListNode* pcur=head;  
    while(pcur)  
    {  
        ListNode* newAdd= new ListNode;  
        newAdd->next=pcur->next;  
        pcur->next=newAdd;  
        pcur=newAdd->next;  
    }  
    ListNode* pre=head;  
    while(pre)  
    {  
        pcur=pre->next;  
        pcur->random=pre->random->next;  
        pre=pcur->next;  
    }  
    ListNode guard;  
    ListNode* tail=&guard;  
    pre=head;  
    while(pre)  
    {  
        tail->next=pre->next;  
        tail=tail->next;  
        pre->next=pre->next->next;  
        pre=pre->next;  
    }     
    return guard.next;  
} 