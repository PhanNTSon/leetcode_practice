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
    p
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