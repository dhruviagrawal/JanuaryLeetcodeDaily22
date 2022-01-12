//Ques Link- https://leetcode.com/problems/insert-into-a-binary-search-tree/
//Trees

//trick is to not complicate the question and just add the node to any of the leaf node possible. 

class Solution {
public:
    //height balanced BST TC O(log N)
    TreeNode* insertIntoBST(TreeNode* root, int value) {
        if(!root) 
        {
            return new TreeNode(value);
        }
        
        TreeNode* temp=root;
        while(true)
        {
            if(temp->val < value)
            {
                if(temp->right) temp=temp->right;
                else
                {
                    temp->right=new TreeNode(value);
                    break;
                }
            }
            else
            {
                if(temp->left) temp=temp->left;
                else
                {
                    temp->left=new TreeNode(value);
                    break;
                }
            }
        }
        return root;
    }
};
