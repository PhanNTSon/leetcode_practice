/*
Problem:https://leetcode.com/problems/build-array-from-permutation/description/?envType=daily-question&envId=2025-05-06
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
        Follow as instruction in problem. No brain needed.
    */
    vector<int> buildArray(vector<int> &nums)
    {
        vector<int> ans(nums.size());
        int c = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
};
int main()
{
    Solution s;
    while (true)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        cout << "Nums: \n";
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        cout << "Answer: \n";
        vector<int> ans = s.buildArray(nums);
        for (int i : ans)
        {
            cout << i << ", ";
        }
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