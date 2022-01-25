//Ques link- https://leetcode.com/problems/valid-mountain-array/

/*
TC O(N)
SC O(1)

check where dec seq starts,
from there check if any inc present

also note strictly dec nhi hona chahiye so dec should be from inc 2 onwards!
*/

class Solution {
public:
    bool validMountainArray(vector<int>& a) {
        int n=a.size();
        if(n<3)return false;
        int i=0;
        
        for(;i<n-1;i++)
        {
            if(a[i]==a[i+1])
                return false;
            else if(a[i]>a[i+1])//dec sequence has started
            {
                i++;
                break;
            }
            else
                continue;
        }
        if(i<2) return false; //otherwise sequence is strictly decreasing
        for(;i<n;i++)
        {
            if(a[i]>=a[i-1]) return false;
        }
        return true;
        
    }
};
