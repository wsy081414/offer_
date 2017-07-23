class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<int > q;
        vector<int > data;
        TreeNode* cur = root;
        if(cur == NULL)
            return data;
        q.push(root);
        while(!q.empty()) {
            cur = q.top();
            data.push_back(cur->val);
            if(NULL != cur->left) {
                q.push(cur->left);
            }
            if(NULL != cur->right) {
                q.push(cur->right);
            }
        }
        return data;
    }
};