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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int> mp;
        ListNode* count=head;
        while(count!=NULL){
            mp[count->val]++;
            count=count->next;
        }
        ListNode*head1=NULL;
        ListNode* curr=NULL;
        for(auto &it:mp){
            if(it.second==1){
                ListNode* node=new ListNode(it.first);
                if(!head1){
                    head1=node;
                    curr=head1;
                }
                else{
                    curr->next=node;
                    curr=curr->next;
                }
            }
        }
        return head1;

    }
};