// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        
        if(n==1 && !head->next) return NULL; 
 
        while(count<=n){
            
            dummy=dummy->next;
            count++;
        }

        ListNode* match=new ListNode(-1);
        match->next=head;

        while(dummy){
            dummy=dummy->next;
            match=match->next;
        }

        
        if(match && match->next) match->next=match->next->next;
        cout<<match->val;
        if(n==1) return head;
        if(match->val==-1 || !match->next) return match->next;
        
        return head;
    }
};
