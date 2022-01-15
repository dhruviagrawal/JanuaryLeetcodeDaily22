//Ques link- https://leetcode.com/problems/jump-game-iv/

/*
BFS is used since question is like minimum path
nodes given by indices
edges by steps

steps is updated when all next are taken care of to ensure any one of method/steps was taken of them.

TC O(N)
SC O(N)
*/

class Solution {
public:
    //usimg BFS
    
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int>>indices;
        for(int i=0;i<n;i++)
            indices[arr[i]].push_back(i);
        vector<bool>vis(n);
        vis[0]=true; //starts at node 0
        queue<int>q;
        q.push(0);
        int steps=0;
        
        while(!q.empty())
        {
            for(int size=q.size();size>0;size--)
            {
                int i=q.front();
                q.pop();
                if(i==n-1) return steps; //reached last node
                vector<int>next=indices[arr[i]];
                next.push_back(i-1);
                next.push_back(i+1);
                for(int j:next)
                {
                    if(j>=0 && j<n && !vis[j])
                    {
                        vis[j]=true;
                        q.push(j);
                    }
                }
                indices[arr[i]].clear();//avoid later lookups when same element encountered
            }
            steps++;
        }
        return 0;
    }
};
