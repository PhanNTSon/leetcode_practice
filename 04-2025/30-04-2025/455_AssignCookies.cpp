/*
Problem:https://leetcode.com/problems/assign-cookies/description/
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
        We sort 2 vector first.
        
        After sorting, we try to assign cookie from smallest to largest
        to each children from the least greedy factor. 

        If a cookie can satisfy the children then we move on the next child.
    */
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int count = 0;
        int i = 0, j = 0;
        while (j < s.size() && i < g.size())
        {
            if (s[j] >= g[i])
            {
                ++count;
                ++i;
            }
            ++j;
        }
        return count;
    }
};
int main()
{
    Solution sol;
    while (true)
    {
        int gSize, sSize;
        cout << "g: ";
        cin >> gSize;

        cout << "s: ";
        cin >> sSize;

        vector<int> g, s;
        cout << "Input g: " << "\n";
        int input = 0;
        for (int i = 0; i < gSize; i++)
        {
            cin >> input;
            g.push_back(input);
        }
        cout << "Input s: " << "\n";
        for (int i = 0; i < sSize; i++)
        {
            cin >> input;
            s.push_back(input);
        }

        cout << "Answer: " << sol.findContentChildren(g, s) << "\n";

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