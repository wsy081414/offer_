//判断一棵二叉树是不是另外一颗树的子树

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:

    bool IsSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        //记住首先来判断pRoot2
        if (pRoot2 == NULL) return true;
        if (pRoot1 == NULL) return false;
        
        if (pRoot2->val == pRoot1->val) {
            return IsSubtree(pRoot1->left, pRoot2->left)&&IsSubtree(pRoot1->right, pRoot2->right);
        } 
        return false;
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot2 == NULL || pRoot1 == NULL)
            return false;
        //判断子树是否相同，并且是否为本树的子树
        return IsSubtree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }
};