//Ques link- https://leetcode.com/problems/string-to-integer-atoi/
//String

class Solution {
public:
    //TC O(N) SC O(1)
    int myAtoi(string s) {
        if(s.length()==0) return 0;
        
        int i=0;
        while(i<s.length())
        {
            if(s[i]==' ')
                i++;
            else 
                break;
        }
        s=s.substr(i);//substring from index i to end of string
        int sign=+1;
        long ans=0;
        if(s[0]=='-')sign=-1;//sign is multiplied to ans at last
        
        if(s[0]=='+' || s[0]=='-')
            i=1;//if sign present, proceed from next element for no.
        else
            i=0;//sign not present, first element is no. 
        
        int MAX=INT_MAX, MIN=INT_MIN;
        
        while(i<s.length())
        {
            if(!isdigit(s[i]))
                break;
            
                ans=ans*10+(s[i]-'0');
                if(sign==1 && ans>MAX) return MAX;
                if(sign==-1 && -1*ans<MIN) return MIN;
            
            i++;
        }
        return (int)sign*ans;
    }
};
