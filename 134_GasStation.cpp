//Ques link- https://leetcode.com/problems/gas-station/

/*
check totalgas and totalcost
if cost is high than gas we have, return -1
else 
ans is there
traverse
check currfuel+=(gas[i]-cost[i])
if current fuel<0 not possible choose next index
*/

class Solution {
public:
    //TC O(N)
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int totalgas=0,totalcost=0;
        for(int i=0;i<n;i++)
        {
            totalgas+=gas[i];
            totalcost+=cost[i];
        }
        
        if(totalgas<totalcost)return -1; //required is less than availabe, so not possible
        
        int start=0,currfuel=0;
        for(int i=0;i<n;i++)
        {
            currfuel=currfuel+(gas[i]-cost[i]);
            if(currfuel<0)//not possible to start, check next index
            {
                currfuel=0;
                start=i+1;
            }
        }
        return start;
    }
};
