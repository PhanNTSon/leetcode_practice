/*
Problem:https://leetcode.com/problems/sort-colors/description/?envType=daily-question&envId=2025-05-17
*/
/*
Author: Minikie - Phan NT Son
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    /*
    Explain Solution:
        Using Quicksort Algorithm.
        Quicksort Algorithm use an Element in array as a pivot and 
        base on that Pivot element, It will toss out which one is 
        smaller than pivot to the left, larger to the right.

        After that, repeat the same process until the sub-array
        length is 1.
    */
    void sortColors(vector<int> &nums)
    {
        qSort(nums, 0, nums.size() - 1);
    }

    void qSort(vector<int> &arr, int start, int end)
    {
        if (start < end)
        {
            int pivot = start;
            int storeIndex = pivot + 1;
            for (int i = start + 1; i <= end; i++)
            {
                if (arr[i] < arr[pivot])
                {
                    swap(arr[i], arr[storeIndex]);
                    ++storeIndex;
                }
            }

            swap(arr[pivot], arr[storeIndex - 1]);
            qSort(arr, start, storeIndex - 1);
            qSort(arr, storeIndex, end);
        }
    }
    void swap(int &a, int &b)
    {
        if (&a == &b) return;
        a = a + b;
        b = a - b;
        a = a - b;
    }
};
int main()
{
    Solution s;
    while (true)
    {
        int n;
        cout << "Size: ";
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cout << "[" << i << "]: ";
            cin >> nums[i];
        }

        s.sortColors(nums);
        cout << "Answer: ";
        for (int i : nums)
        {
            cout << i << ", ";
        }

        cout << "\n";
        char x;
        cout << "Continue ? Y/N:";
        cin >> x;
        if (x == 'n' || x == 'N')
        {
            break;
        }
    }
    return 0;
}