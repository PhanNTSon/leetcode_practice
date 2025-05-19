/*
Problem:https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/description/?envType=daily-question&envId=2025-05-15
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
        Follow exactly to the instruction of Problem
    */
    vector<string> getLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        vector<string> res;
        res.push_back(words[0]);
        int prev = groups[0];
        for (int i = 1; i < words.size(); i++)
        {
            if (groups[i] != prev)
            {
                res.push_back(words[i]);
                prev = groups[i];
            }
        }
        return res;
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

        vector<string> res = s.getLongestSubsequence(words, groups);
        cout << "Answer: \n";
        for (string i : res)
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