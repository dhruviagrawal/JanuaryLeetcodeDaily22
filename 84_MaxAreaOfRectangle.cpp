//Ques link- https://leetcode.com/problems/largest-rectangle-in-histogram/

/*
BRUTE-
O(n^2)
at every point, find next small to left n right
so width=next small right - next small left + 1 
so dist=height at point * width
*/

/*

BETTER-
O(N)+O(N)
SC O(3N)
left arr same size
stack stores indices
https://www.youtube.com/watch?v=X0X6G-eWgQ8 video is good
basically we maintain linearly inc fashion in stack and keep storing ind+1 if stack element is greater than height, else just pop the element (for clarity watch video)

Can do same for right smaller, just traverse through right of arr and store ind-1

Now for each index we have NSR and NSL and we can find area for each for max area.
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //Better Aprroach Code
        int n=heights.size();
        int left[n],right[n];
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            if(st.empty()) left[i]=0;
            else left[i]=st.top()+1;
            st.push(i);
        }
        //clear stack tp re-use
        while(!st.empty())
            st.pop();
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            if(st.empty()) right[i]=n-1;
            else right[i]=st.top()-1;
            st.push(i);
        }
        
        int maxArea=0,area;
        for(int i=0;i<n;i++)
        {
            int w=right[i]-left[i]+1;
            area=w*heights[i];
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};

/*
OPTIMAL- TC O(N), SC O(N)
using only one pass instead of two
https://www.youtube.com/watch?v=jC_cWLy7jSI&t=593s
since stack has linearly inc, every element in stack can tell which element will be left n right smaller accordingly.
I prefer watching video for this solution.
*/

//optimal
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) { 
        stack<int> st; 
        int maxA = 0; 
        int n = heights.size(); 
        for(int i = 0;i<=n;i++) {
            while(!st.empty() && (i==n || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop(); 
                int width; 
                if(st.empty()) width = i; 
                else width = i - st.top() - 1; 
                
                // cout << i << " " << width << " " << height << endl; 
                maxA = max(maxA, width * height); 
            }
            st.push(i); 
        }
        return maxA;
    }
};

