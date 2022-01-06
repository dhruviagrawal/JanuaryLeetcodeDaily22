//Ques link- https://leetcode.com/problems/car-pooling/
//Cumulative Sum and Heap Methods

class Solution {
public:
    //Cumulative Sum method- TC O(N) 
    //Cumulative Sum methods make note of total no. of passengers at any given instant of time
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=trips.size();
        int lastDrop=-1;
        
        for(int i=0;i<n;i++)
        {
            lastDrop=max(lastDrop, trips[i][2]);
        }
        
        int passengers[lastDrop+1];
        
        for(int i=0;i<=lastDrop;i++)
            passengers[i]=0;
        
        for(int i=0;i<n;i++)
        {
            passengers[trips[i][1]] += trips[i][0];
            passengers[trips[i][2]] -= trips[i][0];
        }
        
        if(passengers[0]>capacity) return false;
        //cumulative sum
        for(int i=1;i<=lastDrop;i++)
        {
            passengers[i]+=passengers[i-1];
            if(passengers[i]>capacity) return false;
        }
        
        return true;
    }
};




class Solution {
public:
    //Min Heap used- TC O(N log N) 
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> heap;
        for(int i=0;i<trips.size();i++)
        {
            heap.push({trips[i][1], trips[i][0]});
            heap.push({trips[i][2], -trips[i][0]});
        }
        int onboard=0;
        while(!heap.empty())
        {
            onboard= onboard+ heap.top().second;
            heap.pop();
            if(onboard>capacity)return false;
        }
        return true;
    }
};
