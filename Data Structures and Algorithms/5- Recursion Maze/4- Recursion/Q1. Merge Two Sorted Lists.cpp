class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL && list2 == NULL)return NULL;
        ListNode* ans = NULL;
        ListNode* start = NULL;
        start = new ListNode();
        ans = start;
        while (list1 != NULL || list2 != NULL) {
            int val1 = list1 == NULL ? INT_MAX : list1->val;
            int val2 = list2 == NULL ? INT_MAX : list2->val;
            if (val1 < val2) {
                start->val = val1;
                list1 = list1->next;
            } else {
                start->val = val2;
                list2 = list2->next;
            }
            if (list1 != NULL || list2 != NULL)start->next = new ListNode();
            start = start->next;
        }
        return ans;
    }
};