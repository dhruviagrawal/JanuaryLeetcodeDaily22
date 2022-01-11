//Ques link- https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

/*
*2 to left shift
root->val to add value at ones position
1
10- 1 is left shifted+0 added
100- 10 is left shifted+0 is added
*/

//TC O(N)
//SC O(N)- recursion stack space



class Solution {
public:
    int sumRootToLeaf(TreeNode* root, int value=0) {
        if(!root) return 0;
        value=value*2+root->val;
        if(root->left==root->right) 
            return value;
        else
           return sumRootToLeaf(root->left,value)+sumRootToLeaf(root->right,value);
    }
};
