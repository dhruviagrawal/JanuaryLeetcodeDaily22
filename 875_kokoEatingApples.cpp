//Ques link- https://leetcode.com/problems/koko-eating-bananas/

/*
Find max element of piles=m
initial speed max possible will be this and then the hours needed will be n

Now, Brute- max speed ko kam krte jaege and will check when its not possible to eat So O(N)

use binary search O(log N)
here binary search was to be applied on speed and not on the piles array

TC O(N log M)
SC O(1)

if its possible to eat, take lesser speed and update the speed
else take higher speed and find when its possible to eat. 
*/

class Solution {
public:
    bool isPossible(vector<int>&piles, int h, int k)
    {
        int time=0;
        for(int i=0;i<piles.size();i++)
        {
            time += (piles[i]/k);
            if(piles[i]%k!=0) time++;
        }
        return time<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        
        //find max element and initialise it to speed
        int m=INT_MIN;
        for(int a:piles)
        m=max(a,m);
        
        //if h is no. of piles, then max element will be speed 
        if(h==n) return m;
        
        //binary search of speeds
        int lo=1,hi=m,speed=m;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            
            if(isPossible(piles,h,mid))
            {
                speed=mid; 
                hi=mid-1;
            }
            else
            {
                lo=mid+1;
            }
        }
        return speed;
    }
};
