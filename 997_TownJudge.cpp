//Ques link- https://leetcode.com/problems/find-the-town-judge/
//Topic- Graphs easy

/*
TC O(n)
SC O(n)

degree array keeps count of indegree

since town judge is trusted by all, it should have indegree=(n-1)
we use this observation

we make indegree -1 for each outdegree
*/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>degree(n+1,0); //indegree array
        for(auto it:trust)
        {
            degree[it[0]]--;
            degree[it[1]]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(degree[i]==(n-1))
                return i;
        }
        return -1;
    }
};
