/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
	Node* copyRandomList(Node* head) {
		unordered_map<Node*, Node*>mp;
		mp[NULL] = NULL;
		Node *start = head;
		while (start) {
			mp[start] = new Node(start->val);
			start = start->next;
		}
		start = head;
		while (start) {
			mp[start]->next = mp[start->next];
			mp[start]->random = mp[start->random];
			start = start->next;
		}
		return mp[head];

	}
};