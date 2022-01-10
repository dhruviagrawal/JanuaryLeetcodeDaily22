//Ques link- https://leetcode.com/problems/add-binary/


//TC O(N)
class Solution {
public:
    //Two Pointer Approach
    string addBinary(string a, string b) {
        int c1=a.length()-1,c2=b.length()-1;
        string result;
        int carry=0;
        while(c1>=0 || c2>=0)
        {
            int sum=carry;
            if(c1>=0) 
                sum += a[c1--]-'0';
            if(c2>=0)
                sum += b[c2--]-'0';
            if(sum>1) carry=1;
            else carry=0;
            
            int ans = sum % 2;
            result += to_string(ans);
        }
        if(carry)
            result += to_string(carry);
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};
