//Ques link- https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

bool comp(vector<int>&a, vector<int>&b)
    {
        return a[1]<b[1]; //sorting according to ascending order of end points
    }
class Solution {
public:
    //TC O(N log N)
    //SC O(1)
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0)return 0;
        sort(points.begin(),points.end(),comp);
        
        int arrows=1;
        int end=points[0][1];
        for(int i=1;i<points.size();i++)
        {
            if(points[i][0]<=end)
                continue; //overlaps
            else
            {
                arrows++; //new arrow used
                end=points[i][1]; //end updated to new arrow
            } 
        }
        return arrows;
    }
};
