class Solution {
public:
    // 二叉搜索树左节点小于根， 右节点大于根
    // 二叉搜索树先遍历右节点的中序遍历为从大到小, 反而反之.
    int kthLargest(TreeNode* root, int k) {
        myK = k;
        traversal(root);
        return result;
    }
    void traversal(TreeNode* root){
        if(root==NULL||result!=NULL)return;
        traversal(root->right);
        sk.push(root->val);
        if(sk.size()==myK){
            result=sk.top();
            return;
        }
        traversal(root->left);
    }
private:
    stack<int> sk;
    // 下面两个量帮助两个方法进行信息交换
    int myK; // 记录输入的k
    int result; // 记录结果
};