bool isSymmetric(TreeNode *root)
{
    queue<TreeNode *> q;
    if (root == NULL)
        return true;
    q.push(root->left);
    q.push(root->right);
    while (!q.empty())
    {
        TreeNode *A = q.front();
        if (!q.empty())
            q.pop();
        TreeNode *B = q.front();
        if (!q.empty())
            q.pop();
        if ((A == NULL && B != NULL) || (A != NULL) && (B == NULL)){
            return false;
        }
        if (A!= NULL){
            if(A->val != B->val){
                return false;
            }
        }
        if (A!= NULL)
        {
            q.push(A->left);
            q.push(B->right);
            q.push(A->right);
            q.push(B->left);
        }
    }
    return true;
}
