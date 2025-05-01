/*
Problem:https://leetcode.com/problems/house-robber/description/
*/
/*
Author: Minikie - Phan NT Son
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    /*
    Explain #1 Solution:
        This solution uses dynamic programming to keep track of the
        maximum total money we can rob at each house.

        The main idea is that we can only rob house `i` if we skipped
        house `i - 1`, so from any house `i`, we can consider jumping
        to house `i + 2` or even `i + 3` to avoid robbing adjacent houses.

        Instead of tracking how we reached a house, we care about:
            - What is the maximum amount we can collect *if* we rob that
            house under the jump conditions.

        For each house, we check and update the future possible positions it can jump to.
        After scanning all possibilities, we return the maximum collected value at any house.
    */
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        int maxSum = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i + 2 < nums.size())
            {
                dp[i + 2] = max(dp[i + 2], dp[i] + nums[i + 2]);
            }
            if (i + 3 < nums.size())
            {
                dp[i + 3] = max(dp[i + 3], dp[i] + nums[i + 3]);
            }
            maxSum = max(maxSum, dp[i]);
        }
        return maxSum;
    }

    /*
    Explain #2 Solution:
        This is from ChatGPT suggestion.
        The core idea is still using DP approach.

        Constraint: You cannot rob two adjacent houses.
        So, for each house `i`, we have two choices:
            - Skip it → the best result up to `i-1` → dp[i - 1]
            - Rob it → take nums[i] + the best result up to `i-2` → nums[i] + dp[i - 2]

        Therefore, the recurrence relation is:
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2])

        This means:
            - If dp[i] == dp[i - 1], we skipped this house.
            - If dp[i] == nums[i] + dp[i - 2], we robbed it.

        This gives us the maximum amount of money we can rob without alerting the police.
    */
    int rob2(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[n - 1];
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
        cout << "Nums:\n";
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        cout << s.rob(nums) << "\n";

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