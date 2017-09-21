/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//递归重建二叉树

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if ((pre.size() != vin.size()) || (pre.size() == 0 )) {
            return NULL;
        }
        int size = pre.size();
        int tmp = pre[0];      
        TreeNode *root = new TreeNode(tmp);
        int i = 0;
        for (i = 0; i < size && vin[i] != tmp; ++i)
            ;
        if (i == size)
            return NULL;
        vector<int> leftpre, rightpre, leftvin, rightvin;

        for (int j = 0; j < size; ++j) {
            if (j < i) {
                leftvin.push_back(vin[j]);
                leftpre.push_back(pre[j+1]);
            } else if (j > i) {
                rightvin.push_back(vin[j]);
                rightpre.push_back(pre[j]);
            }
        }
        root->left = reConstructBinaryTree(leftpre, leftvin);
        root->right = reConstructBinaryTree(rightpre, rightvin);
        return root;
    }
};




Node* _RebuildBinaryTree (T* preorder, T* infixorder , int lengh)
     {
          if ( lengh == 0 || preorder == NULL || infixorder == NULL)
          {
              return NULL ;
          }
          T tmp = preorder[0 ];
          Node * root = new Node(tmp );
          int i = 0;
          for ( i = 0; i < lengh &&infixorder[ i] != tmp ; i ++)
              ;
          int leftlen = i;
          int rightlen = lengh - i - 1 ;
          if ( leftlen>0 )
              root->_left = _RebuildBinaryTree (preorder+ 1, infixorder, leftlen);
          if ( rightlen > 0)
              root->_right = _RebuildBinaryTree (preorder+ leftlen + 1, infixorder +leftlen + 1 , rightlen );

          return root ;
     }
