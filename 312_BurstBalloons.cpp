//Ques link- https://leetcode.com/problems/burst-balloons/

//Topic- DP

/*
TC- O(n^3)
SC- O(n^2)

Using gap strategy

Gap strategy DP- fill only half of table, diagonal onwards.
diagonals are subproblems of length 1

Here we are concerned with which balloon to burst last qki the subproblems aren't completely independent!
*/

class Solution {
public:
    int maxCoins(vector<int>& a) {
       int n=a.size();
       int dp[n][n];
        
       for(int i=0;i<n;i++)
           for(int j=0;j<n;j++)
               dp[i][j]=0;
        
        // loop to move diagonally
       for(int l=1;l<=n;l++)
       {
           //loop to move across the diagonal
           for(int i=0;i<=n-l;i++)
           {
               int j=i+l-1; //l=j-i+1
               
               //loop to find which baloon to burst last
               for(int k=i;k<=j;k++)
               {
                   int left,right,val;
                   left=(k==i ? 0 : (dp[i][k-1]));
                   right=(k==j ? 0 : (dp[k+1][j]));
                   
                   val=(i==0 ? 1 : a[i-1]) * a[k] * (j==(n-1) ? 1 : a[j+1]);
                   
                   dp[i][j]=max(dp[i][j], val+left+right);
               }
           }
       }
      return dp[0][n-1]; 
    }
};
