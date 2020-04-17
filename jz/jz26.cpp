#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
    {
    }
};
// use to find the matched root in A
bool isSubStructure(TreeNode* A, TreeNode* B)
{
    if (!A || !B)
        return false;
    // first find out whether A, B match,
    // then use isSubstructure to find out whether left or right could match
    return recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
}
// match based on A, B
bool recur(TreeNode* A, TreeNode* B)
{
    // B is done, match
    if (!B)
        return true;
    // A is done, B is not done
    // A not equal to B
    if (!A || A->val != B->val)
        return false;
    return recur(A->left, B->left) && recur(A->right, B->right);
}