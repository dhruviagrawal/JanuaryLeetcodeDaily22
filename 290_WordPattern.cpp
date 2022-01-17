//Ques link- https://leetcode.com/problems/word-pattern/

/*
TC O(N)
SC O(N)

separate out words and put in vector
if size of words and pattern different, false

map mein character of pattern and corresponding word is inserted
if char is found in map, check word 
else
check word doesnt correspond to other char using set
if so false

otherwise finally true!

*/

class Solution {
public:
    bool wordPattern(string p, string s) {
        //forming words vector from string s
        vector<string>words;
        int i=0;
        string temp="";
        while(i<s.size())
        {
            if(s[i]==' ')
            {
                words.push_back(temp);
                temp="";
            }
            else
            {
                temp+=s[i];
            }
            i++;
        }
        words.push_back(temp);
        
        int n=p.size();
        int m=words.size();
        if(n!=m) return false; //if they are not same size, doesnt follow pattern
        
        unordered_map<char,string>mpp;
        set<string>st;
        
        for(int i=0;i<n;i++)
        {
            //char found in map
            if(mpp.find(p[i])!=mpp.end())
            {
                if(mpp[p[i]]!=words[i])
                    return false;
            }
            else 
            {
                if(st.count(words[i])>0) //if word is in map but char isnot 
                    return false;
                mpp[p[i]]=words[i];
                st.insert(words[i]);
            }
        }
        
        return true;
        
    }
};
