#include <iostream>

using namespace std;


vector<list<int> > test(TreeNode *root) {
    vector<list<int> > v;
    queue<TreeNode *> t1;

    t1.push(root);
    t1.push(NULL);
    list<int > tmp_list;
    while(!t1.empty() ) {
        
        TreeNode * tmp = t1.front();
        t1.pop();
        if(tmp == NULL) {
            v.push_back(tmp_list);
            t1.push(NULL);
            tmp_list.clear();
            continue;
        }
        
        tmp_list.push_back(tmp->val);
        if(tmp->left != NULL)
            t1.push(tmp->left);
        if(tmp->right != NULL)
            t1.push(tmp->right); 
    }
    
    return v;
}