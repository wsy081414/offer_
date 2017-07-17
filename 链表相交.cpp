//假设链表无环
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
        int len1 = findListLenth(pHead1);
        int len2 = findListLenth(pHead2);
        if(len1 > len2) {
            pHead1 = walkStep(pHead1,len1 - len2);
        }else {
            pHead2 = walkStep(pHead2,len2 - len1);
        }
        while(pHead1 != NULL) {
            if(pHead1 == pHead2) 
                return pHead1;
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return NULL;
    }
     
    int findListLenth(ListNode *pHead1) {
        if(pHead1 == NULL) return 0; 
        int sum = 1;
        while(pHead1 = pHead1->next) 
            sum++;
        return sum;
    }
     
    ListNode* walkStep(ListNode *pHead1, int step) {
        while(step--) {
            pHead1 = pHead1->next;
        }
        return pHead1;
    }
};
//假设链表可能环

class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode *plist1, ListNode *plist2) {
        if ((plist1 == NULL) || (plist2== NULL)) {
            return NULL;
        }
        ListNode* enter1 = EnterNode(plist1);    
        ListNode* enter2 = EnterNode(plist2);    
         
        if ((enter1 == NULL) && (enter2 == NULL)) {    
            return IsListIntersect(plist1, plist2);    
        }       
        else if ((enter1 == NULL) && (enter2 != NULL) || (enter1 != NULL) && (enter2 == NULL)) {    
            return NULL;    
        }      
        else if (enter1 == enter2) {    
            enter1->next = NULL;    
            enter2->next = NULL;    
            return IsListIntersect(plist1, plist2);    
        } else {    
            ListNode* tmp = enter1->next;    
            while (tmp != enter1) {    
                if (tmp == enter2) {    
                    return enter1;    
                }    
                tmp = tmp->next;    
            }    
            return NULL;    
        }           
    }
    ListNode* EnterNode( ListNode *pHead) {
        ListNode* fast = pHead;
        ListNode* slow = pHead;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow ->next;
            if(fast == slow)
                break;
        }
        if (fast == NULL || fast->next == NULL)
            return NULL;
        else {
            slow = pHead;
            while(slow != fast) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }
};