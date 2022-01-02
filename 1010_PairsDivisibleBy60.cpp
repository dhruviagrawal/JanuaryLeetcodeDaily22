//ques link- https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

//Topic- Hashmap, Arrays

/*
brute was n^2 -TLE

O(n) TC-
for x+y to be divisible by z
x%z-r1 remainder
y%z-r2 remainder 

0 <= r1+r2 < z

so make remainder array
remainder, freq map

if present, product of freq

corner cases- 
0 and 30 means self pair, n*(n-1)/2 pairs, n is freq
to avoid duplicate pairs, take only first half of remainder array
*/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        //O(n) TC
        
        int p=0,n=time.size();
        int a[n];
        unordered_map<int,int>mpp; //remainder-frequency
        for(int i=0;i<n;i++)
        {
            a[i]=time[i]%60; //remainder array
            mpp[a[i]]++; 
        }
        
        for(auto it:mpp)
        {
            //special case
            if(it.first==0 || it.first==30)
            {
                int s=(it.second*(it.second-1))/2;
                p+=s;
            }
            else
            {
                if(it.first<30 && mpp.count(60-it.first))
                {
                    int s=mpp[it.first]*mpp[60-it.first]; //product of frequency
                    p+=s;
                }
            }
        }
        return p;
    }
};

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        //O(n) TC
        
        //checks how near no. is if its not divisible by 60
        int ans=0,n=time.size();
        vector<int> v(60,0);
        
        for(int i=0;i<n;i++)
        {
            int x=time[i]%60;
            if(x==0) ans+=v[x];
            else
                ans+=v[60-x];
            v[x]++;
        }
        return ans;
    }
};
