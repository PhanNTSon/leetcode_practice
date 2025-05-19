/*
Problem:https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-ii/description/?envType=daily-question&envId=2025-05-16
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
    Explain  Solution:
        We solve this problem using Dynamic Programming.

        1. Let dp[i] represent the length of the longest valid subsequence
           that ends at words[i].

        2. Let prev[i] store the index of the previous word in the subsequence
           leading to words[i], allowing us to reconstruct the full path later.

        3. For each word[i], we check all previous words[j] (where j < i):
            - If groups[i] != groups[j]
            - And words[i] and words[j] are the same length
            - And words[i] and words[j] differ by exactly one character (Hamming distance == 1)

           Then we can extend the subsequence ending at j to i.

           If dp[j] + 1 > dp[i], update:
               - dp[i] = dp[j] + 1
               - prev[i] = j

        4. After filling the dp and prev arrays, we find the index maxInd
           where dp[maxInd] is the maximum value (i.e., the end of the longest subsequence).

        5. Reconstruct the result by walking backward using the prev[] array.

        6. The isHam() helper checks whether two strings differ by exactly one character.
    */
    vector<string> getWordsInLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        int n = words.size();
        if (n == 1)
            return words;

        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        int maxLen = 1, maxInd = 0;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (groups[i] != groups[j] && words[i].size() == words[j].size() && isHam(words[i], words[j]))
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if (dp[i] > maxLen)
            {
                maxLen = dp[i];
                maxInd = i;
            }
        }

        vector<string> res;
        for (int i = maxInd; i != -1; i = prev[i])
        {
            res.push_back(words[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
    bool isHam(string &a, string &b)
    {
        int c = 0;
        for (int i = 0; i < a.size(); i++)
        {
            c += (a[i] != b[i]) ? 1 : 0;
            if (c > 1)
            {
                return false;
            }
        }
        return c == 1;
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
        vector<string> words(n);
        vector<int> groups(n);
        cout << "Words: \n";
        for (int i = 0; i < n; i++)
        {
            cout << "[" << i << "]: ";
            cin >> words[i];
        }
        cout << "Groups: \n";
        for (int i = 0; i < n; i++)
        {
            cout << "[" << i << "]: ";
            cin >> groups[i];
        }

        vector<string> res = s.getWordsInLongestSubsequence(words, groups);
        cout << "Answer: \n";
        for (string i : res)
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