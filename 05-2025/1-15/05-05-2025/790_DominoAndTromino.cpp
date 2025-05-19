/*
Problem:https://leetcode.com/problems/domino-and-tromino-tiling/description/?envType=daily-question&envId=2025-05-05
*/
/*
Author: Minikie - Phan NT Son
*/
#include <iostream>

using namespace std;
class Solution
{
public:
    /*
    Explain Solution:
        Key item of this problem is to find the pattern first then 
        implement in here. 
        
        The pattern found in here is:
        A[n] = A[n-1] + A[n-2] + 2*Sum(A[i] | i:0->n-3)

        We simplify it by subtraction: 
        A[n] - A[n-1] = A[n-1] + A[n-3]
        => A[n] = 2*A[n-1] + A[n-3]
    */
    int numTilings(int n)
    {
        const int MOD = 1e9 + 7;
        if (n <= 2)
        {
            return n;
        }
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++)
        {
            dp[i] = ((2 * (dp[i - 1] % MOD)) % MOD + dp[i - 3] % MOD) % MOD;
        }
        return dp[n];
    }
};
int main()
{
    Solution s;
    while (true)
    {
        int n;
        cin >> n;
        cout << "Answer: " << s.numTilings(n) << "\n";
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