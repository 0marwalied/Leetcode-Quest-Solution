/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#define all(v)    v.begin(),v.end()

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head)return head;
        ListNode* use = new ListNode();
        ListNode* ans = use;
        vector<int>v;
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }
        reverse(all(v));
        for (int i = 0; i < v.size(); i++) {
            use->val = v[i];
            if (i + 1 < v.size())use->next = new ListNode(), use = use->next;
        }
        return ans;
    }
};