//Ques Link- https://leetcode.com/problems/linked-list-random-node/
//Linked List

/*
Approach 1st- Use extra Space
takes O(N) TC and SC
*/
class Solution {
public:
    //Using extra space
    // TC O(N)
    // SC O(N)
    vector<int>v;
    
    Solution(ListNode* head) {
       while(head!=NULL)
       {
           v.push_back(head->val);
           head=head->next;
       }
    }
    
    int getRandom() {
        int n,randomIndex,randomElement;
        n=v.size();
        randomIndex=rand() % n;
        randomElement=v[randomIndex];
        return randomElement;
    }
};


/*
follow up ques says if length large and size unknown, we will need to form a solution where its actually O(1) SC. For this we will use a technqiue called **Reservoir Sampling**

Reservoir Sampling is a randomized algorithm that is used to select k out of n samples where n is usually very large or unknown.

2) O(1) SC-
     iterates through list itself and changes probability each time.
*/
class Solution {
public:
    //Reservoir Sampling Technique - to form SC O(1) solution
    ListNode* head=NULL;
    Solution(ListNode* head) {
       this->head=head;
    }
    
    int getRandom() {
       ListNode* ans=NULL;
       ListNode* curr=head;
        int i=1;
        while(curr)
        {
            if(rand()%i==0)
                ans=curr;
            i++; //probability changes 
            curr=curr->next;
        }
        return ans->val;
    }
};
