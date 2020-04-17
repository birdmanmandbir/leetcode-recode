class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        traversal(root);
        int result=-1;
        for(int i=0;i<k-1;i++){
            pq.pop();
        }
        return pq.top();
    }
    void traversal(TreeNode* root){
        if(root==NULL)return;
        pq.push(root->val);
        traversal(root->left);
        traversal(root->right);
    }
private:
    priority_queue<int> pq; //默认大顶堆
};