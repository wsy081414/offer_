//反转链表
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead->next == NULL || pHead == NULL) {
            return pHead;
        }
        ListNode* cur1 = pHead;
        ListNode* cur2 = pHead->next;
        ListNode* tmp = NULL;
        cur1->next = NULL;
        while(cur2 != NULL) {
            tmp = cur2->next; 
            cur2->next = cur1; 
            cur1 = cur2;
            cur2 = tmp;
        }
        return cur1;
    }
};

