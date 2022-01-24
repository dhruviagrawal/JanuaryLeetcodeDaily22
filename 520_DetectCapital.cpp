//Ques link- https://leetcode.com/problems/detect-capital/

//Just count no. of upper case letters in the word !

class Solution {
public:
    bool isUpper(char c)
    {
        return (c>='A' && c<='Z');
    }    
    
    bool detectCapitalUse(string word) {
        int n=word.size();
        int countUpper=0;
        //counting no. of uppercase letters
        for (int i=0;i<n;i++)
        {
            char c=word[i];
            if(isUpper(c))
                countUpper++;
        }
        if(countUpper==n)return true; //all characters uppercase
        else if(countUpper==0)return true; //all characters lowercase
        else if(countUpper==1 && isUpper(word[0]))return true; //first character uppercase
        else return false; //all wrong capitals
    }
};
