class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*, bool>vis;
        while (head) {
            if (vis.count(head))return true;
            vis[head] = true;
            head = head->next;
        }
        return false;
    }
};