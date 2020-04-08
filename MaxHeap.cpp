#include "lib/general.h"
void heapify(vector<int>&, int);
void printHeap(vector<int>& arr)
{
    cout << "Array representation of Heap is:\n";
    for (int x : arr)
        cout << x << " ";
    cout << "\n";
}
void buildHeap(vector<int>& arr)
{
    // 根据二叉树的性质，n/2 是最后一个非叶节点, n/2-1 是最后一个非叶节点的index
    int n = arr.size();
    int finalNonLeafIndex = n / 2 - 1;
    for (int i = finalNonLeafIndex; i >= 0; i--) {
        heapify(arr, i);
    }
}
void heapify(vector<int>& arr, int i){
    int largest = i;
    int n = arr.size();
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]){
        largest = right;
    }
    if (largest != i){
        // need swap
        swap(arr[largest], arr[i]);
        // need heapify previous node i because maybe not final position
        heapify(arr, largest);
    }
}
// Driver Code
int main()
{
    // Binary Tree Representation
    // of input array
    // 1
    //           /     \
    // 3         5
    //      /    \     /  \
    // 4      6   13  10
    //    / \    / \
    // 9   8  15 17
    vector<int> arr= { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
    buildHeap(arr);
    printHeap(arr);
    // Final Heap:
    // 17
    //           /      \
    // 15         13
    //       /    \      /  \
    // 9      6    5   10
    //     / \    /  \
    // 4   8  3    1

    return 0;
}