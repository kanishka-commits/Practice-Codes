#https://leetcode.com/problems/linked-list-cycle-ii/description/?envType=problem-list-v2&envId=linked-list

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *s=head;
        ListNode *f=head;

        while(f && f->next){
            f=f->next->next;
            s=s->next;

            if(f==s) break;
        }

        if(!f || !f->next) return NULL;

        s=head;
        int c=0;
        while(s!=f){
            s=s->next;
            f=f->next;

        }

         while(s){
             if(s==f && c>0) {
                        cout<<c;
                        break;}
                    c++;
                   
                    s=s->next;
                }

        return s;    
    }
};
