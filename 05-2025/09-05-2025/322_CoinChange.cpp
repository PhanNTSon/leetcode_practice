/*
Problem:https://leetcode.com/problems/coin-change/description/
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
    Explain Solution:
        Use DP to solve this problem.

        At each value of amount, it can formed by the current coin
        and the previous value, therefore we will have:
        dp[val]:            as the current value
        dp[val - coin]:     as the previous value
        
        The dp array now store the numbers of coins that formed
        up the current value, therefore:
        dp[val] = dp[val - coin] + 1;

        Because we have many coins with different values, thus,
        at first we will set the value to MAX (INT_MAX).
        
        Then, at each coin we calculate we compare the current value 
        with the new value to take out the minimum value.
    */
    int coinChange(vector<int> &bag, int amount)
    {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i < amount + 1; i++)
        {
            for (int coin : bag)
            {
                if (i - coin >= 0 && dp[i - coin] != INT_MAX)
                {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
int main()
{
    Solution s;
    while (true)
    {
        int amount, n;
        cout << "Array size: ";
        cin >> n;
        cout << "Amount: ";
        cin >> amount;
        vector<int> coins(n);
        for (int i = 0; i < n; i++)
        {
            cout << "[" << i << "]: ";
            cin >> coins[i];
        }
        int temp;
        sort(coins.begin(), coins.end());
        // for (int i = 0; i < n; i++)
        // {
        //     int j = 0;
        //     while (amount - coins[i] * j > 0)
        //     {
        //         cout << amount - coins[i] * j << ", ";
        //         j++;
        //     }
        //     cout << "\n";
        // }
        cout << "Answer: " << s.coinChange(coins, amount) << "\n";

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
// int main(){
//     cout << 1 % 2;
//     return 0;
// }