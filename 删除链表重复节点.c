ListNode* deleteDuplication(ListNode* pHead)
{
	// 先判断空
	if (pHead == NULL)
	{
		return NULL;
	}
	// 判断是否只有一个节点
	if (pHead->next == NULL)
	{
		return pHead;
	}
	// 我们采用带头链表，自己添加一个头
	ListNode* pre = new ListNode();
	pre->next = pHead; // 把头节点链接在链表上
	ListNode* pre_head = pre; // 用来保存头节点，用于返回删除后的链表
	ListNode* cur = pHead; //中指针
	ListNode* nex = pHead->next; // 后面指针
	while (nex != NULL) // 结束条件
		while (nex != NULL && cur->val == nex->val) 
		{
			nex = nex->next;
		}
		// 如果没有重复的那么cur的next一定等于nex
		if (cur->next != nex) // 如果相等说明没有相同的节点
		{
			while (cur != nex) // 删除动作
			{
				pre->next = cur->next;
				delete cur;
				cur = pre->next;
			}
			if (nex != NULL) // 这里一定要要注意，要防止走到NULL发生段错误
			nex = nex->next;
		}
		else
		{
			// 处理没有重复的情况
			pre = cur;
			nex = nex->next;
			cur = cur->next;
		}
	}
	ListNode* head = pre_head->next; // 释放空间，防止内存泄漏
	delete pre_head;
	return head;
}



ListNode* deleteDuplicates(ListNode* head) {
    ListNode *pre = head, *cur = head;
    while (cur) {
        if (pre->val != cur->val) {
            pre->next = cur;
            pre = pre->next;
        }
        cur = cur->next;
    }
    if (pre) pre->next = nullptr;
    return head;
}



//all
ListNode* deleteDuplicates(ListNode* head) {
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *pre = dummy, *cur = head;
    while (cur) {
        while (cur->next && cur->next->val == cur->val)
            cur = cur->next;
        if (pre->next == cur)
            pre = cur;
        else
            pre->next = cur->next;
        cur = cur->next;
    }
    return dummy->next;    //不能直接返回 head，因为 head 有可能被删除
}
