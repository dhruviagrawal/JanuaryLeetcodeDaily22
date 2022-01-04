//Ques Link- https://leetcode.com/problems/complement-of-base-10-integer/
//Bit Manipulation

/*
we xor 
starting from LSB
001
010
100
these are actually powers of 2!

so we xor with powers of two to get complement

32 bits hote hai so O(32) TC so TC O(1)
*/

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1; //corner case
        for(long i=1;i<=n;i*=2) //long to avoid integer overflow
            n^=i;
        return n;
    }
};
