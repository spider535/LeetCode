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
#define pil pair<int,ListNode*>
struct myCmp {
    bool operator()(pil const &p, pil const &q){
        return p.first > q.first;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pil,vector<pil>,myCmp> first;
        int n = lists.size();
        if(n==0)
            return nullptr;
        
        for(int i = 0; i < n; i++){
            if(lists[i])
            {
                first.push({lists[i]->val,lists[i]});
            }
        }
        if(first.empty())
            return nullptr;
        pil temp = first.top();
        first.pop();
        ListNode *head = new ListNode(temp.first);
        ListNode* cur = head;
        if(temp.second->next)
        {
            first.push({temp.second->next->val,temp.second->next});
        }
        while(!first.empty())
        {
            pil temp = first.top();
            first.pop();
            cur->next = new ListNode(temp.first);
            cur = cur->next;
            if(temp.second->next)
            {
                first.push({temp.second->next->val,temp.second->next});
            }
        }
        return head;
    }
};