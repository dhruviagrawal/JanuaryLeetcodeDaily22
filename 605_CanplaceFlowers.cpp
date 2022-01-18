//Ques link-

/*
TC O(N)

checking f[i-1] f[i] and f[i+1] =0 can place at f[i] and mark it 1 now!
*/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int k) {
        int n=flowerbed.size();
        int prev,next,total=0;
        for(int i=0;i<n && total<k;i++)
        {
            if(flowerbed[i]==1)
                continue;
            else
            {
                if(i==(n-1))
                    next=0;
                else
                    next=flowerbed[i+1];
                
                if(i==0)
                    prev=0;
                else
                    prev=flowerbed[i-1];
                
                if(prev==0 && next==0)
                {
                   total++;
                   flowerbed[i]=1;
                }
                    
            }
        }
        if(total==k)
            return true;
        else
            return false;
    }
};
