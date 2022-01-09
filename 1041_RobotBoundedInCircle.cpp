//Ques link- https://leetcode.com/problems/robot-bounded-in-circle/

class Solution {
public:
    bool isRobotBounded(string instructions) {
        //TC O(N)
        //SC O(1)
        int x=0,y=0;
        char curr='N';
        
        int n=instructions.size();
        for(int i=0;i<n;i++)
        {
            char ins=instructions[i];
            
            if(ins=='G')
            {
                if(curr=='N') y+=1;
                else if(curr=='S') y+=-1;
                else if(curr=='E') x+=1;
                else x+=-1;
            }
            
            else
            {
                if(curr=='N') curr= (ins=='L' ? 'W':'E');
                else if(curr=='S') curr= (ins=='L' ? 'E':'W');
                else if(curr=='E') curr= (ins=='L' ? 'N':'S');
                else curr= (ins=='L' ? 'S':'N');
            }
        }
        
        if(x==0 && y==0 || curr!='N')
            return true;
        else return false;
    }
};
