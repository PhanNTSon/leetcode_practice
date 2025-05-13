/*
Problem:https://leetcode.com/problems/total-characters-in-string-after-transformations-i/description/?envType=daily-question&envId=2025-05-13
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
    Explain #1 Solution:
        Simulate t steps of character transformations:
        - Each 'z' turns into two characters: 'a' and 'b'.
        - All other characters shift forward by one letter.
        Use two frequency arrays (p1 and p2) to alternate between current and next states.
        After t steps, return the total number of characters modulo 1e9 + 7.
    */
    int lengthAfterTransformations(string s, int t)
    {
        const long MOD = 1e9 + 7;
        int a[26], b[26];
        int *p1 = a;
        int *p2 = b;

        for (int i = 'a'; i <= 'z'; i++)
        {
            a[i - 'a'] = 0;
            b[i - 'a'] = 0;
        }

        for (int i : s)
        {
            a[i - 'a'] += 1;
        }

        for (int j = 0; j < t; j++)
        {
            for (int i = 'a'; i <= 'z'; i++)
            {
                if (i == 'z')
                {
                    *(p2 + 0) += *(p1 + i - 'a') % MOD;
                    *(p2 + 1) += *(p1 + i - 'a') % MOD;
                    *(p1 + i - 'a') = 0;
                }
                else
                {
                    *(p2 + i + 1 - 'a') = *(p1 + i - 'a');
                    *(p1 + i - 'a') = 0;
                }
            }
            int *temp = p1;
            p1 = p2;
            p2 = temp;
        }

        int res = 0;
        for (int i = 'a'; i <= 'z'; i++)
        {
            res = (res + (a[i - 'a'] % MOD + b[i - 'a'] % MOD) % MOD) % MOD;
        }
        return res;
    }
};
int main()
{
    Solution sol;
    while (true)
    {
        int t;
        cout << "t: ";
        cin >> t;
        string s;
        cout << "String: ";
        cin >> s;

        cout << "Answer: " << sol.lengthAfterTransformations(s, t) << "\n";

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