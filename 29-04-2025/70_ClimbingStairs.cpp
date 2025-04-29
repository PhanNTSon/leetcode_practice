/*
Problem:https://leetcode.com/problems/climbing-stairs/?envType=study-plan-v2&envId=top-interview-150
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
        This is another version of Fibonacci problem.
    */
    int climbStairs(int n)
    {
        int mem[n + 1];
        mem[0] = 1;
        mem[1] = 1;
        for (int i = 2; i < n + 1; i++)
        {
            mem[i] = mem[i - 1] + mem[i - 2];
        }
        return mem[n];
    }
};

int main()
{
    Solution s;
    while (true)
    {
        int n;
        cin >> n;
        cout << "Answer: " << s.climbStairs(n) << "\n";
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