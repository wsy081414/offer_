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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead2 == NULL) return pHead1;
        if (pHead1 == NULL) return pHead2;
        ListNode* newlist = NULL;
        ListNode* cur1 = pHead1;
        ListNode* cur2 = pHead2;
        ListNode* curnew = NULL;
        if (cur1->val < cur2->val) {
            curnew = cur1;
            cur1 = cur1->next;
        } else {
            curnew = cur2;
            cur2 = cur2->next;
        }
        newlist = curnew;
        while (cur1 != NULL && cur2 != NULL) {
            if (cur1->val < cur2->val) {
                curnew->next = cur1;
                cur1 = cur1->next;
                
            }else {
                curnew->next = cur2;
                cur2 = cur2->next;
            }
            curnew = curnew->next;
        }
        if(cur1 != NULL) {
            curnew->next = cur1;
        }
        if(cur2 != NULL) {
            curnew->next = cur2;
        }
        return newlist;
    }
};