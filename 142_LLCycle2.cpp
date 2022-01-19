//Ques link- https://leetcode.com/problems/linked-list-cycle-ii/

/*
Brute-
hashing can be used
if map has node, cycle exists so return the node
else insert the node in map
TC O(N) and SC O(N)

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        int pos=0;
        unordered_map<ListNode*,ListNode*>mp;
        ListNode *temp=head;
        while(temp)
        {
            if(mp.find(temp)!=mp.end())
                return mp[temp];
            else
            {
                mp[temp]=temp;
                pos++;
                temp=temp->next;
            }
        }
        return NULL;
    }
};
*/

/*
optimal
we use floyd loop detection algo 
finding the entry point of loop
SC becomes O(1)

when slow==fast found,
slow=head again
now slow 1 step and fast 1 step
so next time slow n fast collide (here slow is called entry), that is entry point of loop.

great video for intuition- https://www.youtube.com/watch?v=qsPoOVAHV_I&list=PLPyD8bF-abzuor0yYzO1g7v8y7u6vO-Fe&t=0s 
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
            return NULL;
        ListNode *slow=head, *fast=head, *entry=head;
        
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast) //loop
            {
                while(fast!=entry) //fast isn't entry now
                {
                    fast=fast->next;
                    entry=entry->next;
                }
                return entry; //when fast n entry collide
            }
        }
        return NULL;
    }
};
