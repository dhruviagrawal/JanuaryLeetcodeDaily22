//Ques link- https://www.youtube.com/watch?v=_WKJX77JpYY

class Solution {
public:
    //TC O(N^2) 
    int maximumWealth(vector<vector<int>>& accounts) {
        int n=accounts.size();
        int m=accounts[0].size();
        int maxWealth=0;
        for(int i=0;i<n;i++)
        {
            int w=0;
            for(int j=0;j<m;j++)
            {
                w+=accounts[i][j];
            }
            maxWealth=max(maxWealth,w);
        }
        return maxWealth;
    }
};
