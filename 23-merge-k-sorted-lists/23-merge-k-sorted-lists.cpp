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
#define pil ListNode*
struct myCmp {
    bool operator()(ListNode* const &p, ListNode* const &q){
        return p->val > q->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,myCmp> first;
        int n = lists.size();
        if(n==0)
            return nullptr;
        
        for(int i = 0; i < n; i++){
            if(lists[i])
            {
                first.push(lists[i]);
            }
        }
        if(first.empty())
            return nullptr;
        ListNode* temp = first.top();
        first.pop();
        ListNode *head = new ListNode(temp->val);
        ListNode* cur = head;
        if(temp->next)
        {
            first.push(temp->next);
        }
        while(!first.empty())
        {
            pil temp = first.top();
            first.pop();
            cur->next = new ListNode(temp->val);
            cur = cur->next;
            if(temp->next)
            {
                first.push(temp->next);
            }
        }
        return head;
    }
};