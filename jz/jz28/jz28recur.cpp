bool isSymmetric(TreeNode *root)
{
    if (root == NULL)
        return true;
    return recurJudge(root->left, root->right);
}

bool recurJudge(TreeNode *A, TreeNode *B)
{
    // first: terminal condition
    if (A == NULL && B == NULL)
        return true;
    if (A == NULL || B == NULL)
        return false;
    if (A->val != B->val)
        return false;
    // 目前相等， 无法判断， 需要继续判断子节点
    return recurJudge(A->left, B->right) && recurJudge(A->right, B->left);
}
