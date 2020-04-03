#include <stack>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
/**
 * TODO List
 * nonRecurPostOrderV2
**/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void nonRecurPreorder(TreeNode *root)
{
    if (root == NULL)
        return;
    cout << root->val << "->";
    stack<TreeNode *> s;
    s.push(root->right);
    s.push(root->left);
    while (!s.empty())
    {
        TreeNode *root = s.top();
        if (root == NULL)
        {
            s.pop();
            continue;
        }
        cout << root->val << "->";
        s.pop();
        s.push(root->right);
        s.push(root->left);
    }
    cout << endl;
}
void nonRecurInorderUgly(TreeNode *root)
{
    if (root == NULL)
        return;
    unordered_map<int, bool> visitedMap;
    stack<TreeNode *> s;
    s.push(root->right);
    s.push(root);
    s.push(root->left);
    while (!s.empty())
    {
        TreeNode *root = s.top();
        if (root == NULL)
        {
            s.pop();
            continue;
        }
        if ((root->left == NULL || visitedMap.find(root->left->val) != visitedMap.end()) && visitedMap.find(root->val) == visitedMap.end())
        {
            cout << root->val << "->";
            visitedMap[root->val] = true;
            s.pop();
            if (root->right != NULL && visitedMap.find(root->right->val) == visitedMap.end())
                s.push(root->right);
            continue;
        }

        s.pop();
        if (root->right != NULL && visitedMap.find(root->right->val) == visitedMap.end())
            s.push(root->right);
        if (root != NULL && visitedMap.find(root->val) == visitedMap.end())
            s.push(root);
        if (root->left != NULL && visitedMap.find(root->left->val) == visitedMap.end())
            s.push(root->left);
    }
    cout << endl;
}

void nonRecursiveInorderUgly2(TreeNode *root)
{
    TreeNode *cur = root;
    stack<TreeNode *> s;
    s.push(cur);
    while (!s.empty())
    {
        cur = s.top();
        if (cur == NULL)
        {
            s.pop();
            if (s.empty())
                break;
            cur = s.top();
            if (cur != NULL)
            {
                cout << cur->val << "->";
                s.pop();
                s.push(cur->right);
            }
        }
        else
        {
            s.push(cur->left);
        }
    }
}

void nonRecursiveInorder(TreeNode *root)
{
    // https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
    TreeNode *cur = root;
    stack<TreeNode *> s;
    while (cur != NULL || !s.empty())
    {
        while (cur != NULL)
        {
            s.push(cur);
            cur = cur->left;
        }
        // cur must be null
        cur = s.top();
        cout << cur->val << "->";
        s.pop();
        // s.push(cur->right); //仅push非NULL的节点
        cur = cur->right;
    }
}

void nonRecursivePostOrderV1(TreeNode *root)
{
    // https://www.geeksforgeeks.org/iterative-postorder-traversal/
    TreeNode *cur = root;
    stack<TreeNode *> s1;
    s1.push(root);
    stack<TreeNode *> s2;
    while (!s1.empty())
    {
        TreeNode *cur = s1.top();
        s1.pop();
        if (cur == NULL)
            continue;
        s2.push(cur);
        s1.push(cur->left);
        s1.push(cur->right);
        // in s1: right->left
        // in s2: left->right->root
    }
    // get reverse order postorderTraverse in stack 2
    while(!s2.empty()){
        cout<<s2.top()->val<<"->";
        s2.pop();
    }
    cout << endl;
}

void preorderTraverse(TreeNode *root)
{
    if (root == NULL)
        return;
    cout << root->val << "->";
    preorderTraverse(root->left);
    preorderTraverse(root->right);
}
void inorderTraverse(TreeNode *root)
{
    if (root == NULL)
        return;
    inorderTraverse(root->left);
    cout << root->val << "->";
    inorderTraverse(root->right);
}
void postOrderTraverse(TreeNode *root)
{
    if (root == NULL)
        return;
    postOrderTraverse(root->left);
    postOrderTraverse(root->right);
    cout << root->val << "->";
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right = new TreeNode(4);
    root->right->right = new TreeNode(5);
    root->right->right->left = new TreeNode(6);
    // preorder 1, 2, 3, 4, 5, 6
    // preorderTraverse(root);
    cout << endl;
    // inorder 3, 2, 1, 4, 6, 5
    // inorderTraverse(root);
    cout << endl;
    // nonRecurPreorder(root);
    // nonRecurInorder(root);
    // nonRecursiveInorder(root);
    // 3->2->6->5->4->1->
    postOrderTraverse(root);
    cout << endl;
    nonRecursivePostOrder(root);
}