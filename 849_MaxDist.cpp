//Ques link-https://leetcode.com/problems/maximize-distance-to-closest-person/

/*
brute-
take two arrays, leftdist and right dist. size= size of array
initialise the array with max dist i,e. the size of array
now,
for left dist, traverse left to right, when 0, make prefixsum++;
                     else, make prefix sum 0 when 1 is encountered
for right dist, traverse right to left, when 0, make suffixsum++;
                     else, make suffix sum 0 when 1 is encountered
at end take = max(min(leftdist[i],rightdist[i])

TC O(N)
SC O(N)



**optimal**-
TC O(N)
SC O(1)
take sufflix and prefix zero
and consecutive zero/2 when zero is in middle.
max of these is max distance!
*/


class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        int prefixZeroes=-1,suffixZeroes=-1,maxZeroes=-1,countZeroes=0;
        for(int i=0;i<n;i++)
        {
            if(seats[i]==0)
            {
                countZeroes++;
            }
            else
            {
                if(prefixZeroes==-1)
                    prefixZeroes=countZeroes;
                else
                    maxZeroes=max(maxZeroes,countZeroes);
                countZeroes=0;
            }
        }
        suffixZeroes=countZeroes;
        return max(max(prefixZeroes,suffixZeroes),(maxZeroes+1)/2);
       
    }
};
