//Ques link- https://leetcode.com/problems/sequential-digits/

/*
1,2,...9
mein hi hoga 
so basically, we will do dfs for each and check which numbers are in range!
*/

class Solution {
public:
    //TC O(NlogN) and SC O(N)
    vector<int>ans;
    void dfs(int low,int high, int i, int num)
    {
        if(num>=low && num<=high)
            ans.push_back(num); //lies in range
        
        if(num>high || i>9) return;
        
        dfs(low,high,i+1,num*10+i);      
    }
    vector<int> sequentialDigits(int low, int high) {
        for(int i=1;i<=9;i++)
            dfs(low,high,i,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
