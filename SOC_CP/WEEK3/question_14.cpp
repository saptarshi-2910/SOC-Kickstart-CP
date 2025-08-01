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
class Solution {
public:
   ListNode* sortList(ListNode* head) {
        if(!head) return nullptr;

        vector<int> vals;

        ListNode* curr = head;
        while(curr){
            vals.push_back(curr->val);
            curr=curr->next;
        }

        sort(vals.begin(),vals.end());

        curr=head;
        int i=0;
        while(curr){
            curr->val=vals[i++];
            curr=curr->next;
        }

        return head;
    }
};