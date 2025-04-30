/*
Problem:https://leetcode.com/problems/maximum-subarray/?envType=study-plan-v2&envId=top-interview-150
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
    Explain #1 Solution:
        Using Kadane's algorithm to find the maximum subarray sum.

        The algorithm decides whether to extend the current subarray
        or to start a new subarray at the current index. It starts a
        new subarray if adding the current element makes the sum smaller
        than starting fresh from the current element itself.

        Kadane’s checks:
            maxCur = max(nums[i], maxCur + nums[i]);
        where:
            - maxCur: the maximum sum of subarrays ending at the current index
            - maxSum: the maximum sum found overall

        This works based on the idea that a bad prefix should be dropped
        to maximize the sum.
    */
    int maxSubArray(vector<int> &nums)
    {
        int maxSum = nums[0], maxCur = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            maxCur = max(nums[i], maxCur + nums[i]);

            if (maxCur > maxSum)
            {
                maxSum = maxCur;
            }
        }
        return maxSum;
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
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        cout << "Answer: " << s.maxSubArray(nums) << "\n";
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