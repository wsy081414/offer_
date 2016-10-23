//树的高度
	size_t _Height(Node *root)
	{
		if (root == NULL)
			return 0;
		size_t lheight = _Height(root->_left) + 1;
		size_t rheight = _Height(root->_right) + 1;

		return lheight > rheight ? lheight : rheight;
	}
	//判断二叉树是否为平衡二叉树
	bool _IsAVLBinaryTree(Node *root)
	{
		if (root==NULL)
		{
			return true;
		}

		int heightorder = abs((int)(_Height(root->_right) - _Height(root->_left)));

		return ((heightorder<2)
			&&(_IsAVLBinaryTree(root->_left))
			&& (_IsAVLBinaryTree(root->_right)));
	}
	//判断二叉树是否为平衡二叉树，优化版本
	bool _IsAVLBinaryTree(Node *root,  int & depth)
	{
		//如果为空，往父节点返
		if (root == NULL)
		{
			depth = 0;
			return true;
		}
		//记录左节点和右节点深度
		int left = 0;
		int right = 0;
		//采取传引用的方式，下层递归进行对深度修改以后会影响上一层
		if (_IsAVLBinaryTree(root->_left, left) && _IsAVLBinaryTree(root->_right, right))
		{
			//计算平衡因子
			int pf = right - left;
			//判断平衡因子是否合法
			if (pfIsInvaild(pf))
			{
	//合法就让自身加上子树的深度，然后因为是传引用，所以当递归回到上一层的时候，上层中的right和left就是左右子树的深度
				depth = 1 + (right > left ? right : left);
				return true;
			}
		}
		return false;
	}
	//判断平衡因子是否合法
	bool pfIsInvaild(const int& pf)
	{
		return abs(pf) < 2;
	}