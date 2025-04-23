/*
Problem:https://leetcode.com/problems/jump-game-ii/description/?envType=study-plan-v2&envId=top-interview-150
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
        i – current index in the `dp` array (represents current position in the input array)
        j – previous index we check for a valid jump to i

        Using Dynamic Programming approach.
        We're using a dynamic programming approach to compute the minimum number of jumps
        needed to reach each position in the array.

        At every index `i`, we look back at all previous indices `j` (from 0 to i-1)
        and check whether it's possible to jump from index `j` to index `i`.
        The condition for a valid jump is: j + nums[j] >= i

        If the condition is met, we update dp[i] to be the minimum of its current value
        or dp[j] + 1 (which means one more jump from index j).

        In the end, dp[n - 1] will store the minimum number of jumps required to reach
        the last index. If dp[n - 1] is still INT_MAX, it means the end is unreachable.
    */
    int jump(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return 0;
        }
        vector<int> dp(nums.size(), INT_MAX);
        dp[0] = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (j + nums[j] >= i)
                {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp.back() == INT_MAX ? 0 : dp.back();
    }

    /*
    Explain #2 Solution:
        Greedy approach.

        jumps:              total jumps we made.
        rightBound:         bound of the window.
        farthestPossible:   the farthest index we can reach with indices
                            inside the window.

        Window: the range of indices we can reach at the moment.

        Key concept: don't need to know exactly where to jump to. Only
            need to know when to make a jump.
        
        At each index `i`, calculate the farthest position we can reach so far:
            max(farthestPossible, i + nums[i]).
        When we reach the end of the current jump window (i == rightBound), 
        we must make a jump, so we increment the jump count and move the 
        window's end to farthestPossible.
        
    */
    int jump2(vector<int> &nums)
    {
        if (nums.size() == 1){
            return 0;
        }
        int jumps = 0;
        int rightBound = 0;
        int farthestPossible = 0;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            farthestPossible = max(farthestPossible, i + nums[i]);

            if (i == rightBound)
            {
                jumps++;
                rightBound = farthestPossible;
            }
        }

        return jumps;
    }
};

int main()
{
    Solution s;
    while (true)
    {
        int n;
        cout << "Enter size: ";
        cin >> n;
        vector<int> nums(n);

        for (int i = 0; i < nums.size(); i++)
        {
            cout << "[" << i << "]: ";
            cin >> nums[i];
        }

        cout << "Answer: " << s.jump2(nums) << endl;

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