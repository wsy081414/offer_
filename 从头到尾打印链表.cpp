/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector <int > d;
        if (head == NULL) return d;
        ListNode* cur = head;
        while (cur != NULL) {
            d.insert(d.begin(), cur->val);
            cur = cur->next;
        }
        return d;
    }
};