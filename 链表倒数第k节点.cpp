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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == NULL || k<=0)
            return NULL;
        ListNode* cur = pListHead;
        ListNode* res = pListHead;
        while(--k) {
            if(cur->next)
                cur = cur->next;
            else
                return NULL;
        }
        while(cur->next != NULL) {
            cur = cur->next;
            res = res->next;
        }
        return res;
    }
};