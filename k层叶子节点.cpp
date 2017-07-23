

//计算第K层的叶子节点的个数
int GetkLeafNodesTotal( BTreeNode *pRoot, int k){  
    if( pRoot == NULL || kthLevel <= 0 )  
        return 0;  
  
    if( pRoot != NULL && k == 1 ){  
        if( pRoot->_left == NULL && pRoot->_right == NULL )  
            return 1;  
        else  
            return 0;  
    }  
  
    return ( GetkLeafNodesTotal(  pRoot->_left,  k - 1) + GetkLeafNodesTotal( pRoot->_right, k -1) );  
}  


