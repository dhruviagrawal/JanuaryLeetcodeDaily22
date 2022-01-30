//Ques link- https://leetcode.com/problems/rotate-array/submissions/

/*
brute-
place last k elements at first and then rest as it is using a new array
TC O(N) and SC O(N)

optimal-
reverse whole array
first k elements reverse
reverse rest elements
that will be ans
eg- 1 2 3 4 5 6 7
rev arr- 7 6 5 4 3 2 1
k=3
reverse first 3 elements- 5 6 7 4 3 2 1
reverse rest elements- 5 6 7 1 2 3 4 this is our ans !

TC O(N) SC O(1)

Also if n=7 and k=10
rotated array will be equivalent to actually, 10%7=3 times!
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};
