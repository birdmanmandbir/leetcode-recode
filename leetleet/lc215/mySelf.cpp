#include "../lib/general.h"
void buildHeap(vector<int>&);
void printHeap(vector<int>&);
int findKthLargest(vector<int>& nums, int k)
{
    buildHeap(nums);
    printHeap(nums);
    return nums[k - 1];
}
void heapify(vector<int>&, int);
void buildHeap(vector<int>& arr)
{
    // 根据二叉树的性质，n/2 是最后一个非叶节点, n/2-1 是最后一个非叶节点的index
    int n = arr.size();
    int finalNonLeafIndex = n / 2 - 1;
    for (int i = finalNonLeafIndex; i >= 0; i--) {
        heapify(arr, i);
    }
}
void heapify(vector<int>& arr, int i)
{
    // est: largest or smallest
    int est = i;
    int n = arr.size();
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[est]) {
        est = left;
    }
    if (right < n && arr[right] > arr[est]) {
        est = right;
    }
    if (est != i) {
        // need swap
        swap(arr[est], arr[i]);
        // need heapify previous node i because maybe not final position
        heapify(arr, est);
    }
}
void printHeap(vector<int>& arr)
{
    cout << "Array representation of Heap is:\n";
    for (int x : arr)
        cout << x << " ";
    cout << "\n";
}

int main()
{
    vector<int> arr = { 3, 2, 3, 1, 2, 4, 5, 5, 6 };
    findKthLargest(arr, 4);
}