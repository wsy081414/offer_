//删除一个无头单链表的非尾节点
class solution {
	int delListNoHead(ListNode* del) {
		ListNode* cur = del->next;
		del->value = cur->value;
		del->next = cur ->next;
		cur->next = NULL;
		delete cur;
	}

}

//从头到尾打印
class solution {
	vector<int > printListFromTailToHead(ListNode* head) {
		vector<int > ret;
		ListNode *cur = head;
		while(cur) {
			ret.insert(ret.begin(), cur->val);
			cur = cur->next;
		}
		return ret;
	}
}