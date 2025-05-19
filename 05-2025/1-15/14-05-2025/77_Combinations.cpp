/*
Problem:https://leetcode.com/problems/combinations/description/
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
        We use backtrack to form the path.
        When the path size is max then we add to res.
    */
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> res;
        vector<int> store;
        for (int i = 1; i <= n; i++)
        {
            store.push_back(i);
        }
        vector<int> path;
        backtrack(res, store, path, k, 0);
        return res;
    }

    void backtrack(vector<vector<int>> &res, vector<int> &store, vector<int> path, int maxSize, int startD)
    {
        for (int i = startD; i < store.size(); i++)
        {
            int temp = store[i];
            store.erase(store.begin() + i);
            path.push_back(temp);
            if (path.size() == maxSize)
            {
                res.push_back(path);
            }
            else
            {
                backtrack(res, store, path, maxSize, i);
            }
            path.pop_back();
            store.insert(store.begin() + i, temp);
        }
    }

    /*
    Explain #2 Solution:
        Same Idea above but instead of using a vector to store values 
        to add to path, we simplify by using a simple loop.

        At each recursion, we start at the next index instead of loop
        through all away from 1.
    */
    vector<vector<int>> combine2(int n, int k)
    {
        vector<vector<int>> res;
        vector<int> path;
        backtrack2(res, path, n, k, 1);
        return res;
    }

    void backtrack2(vector<vector<int>> &res, vector<int> &path, int n, int k, int ind)
    {
        if (path.size() == k)
        {
            res.push_back(path);
        }
        else
        {
            for (int i = ind; i <= n; i++)
            {
                path.push_back(i);
                backtrack2(res, path, n, k, i + 1);
                path.pop_back();
            }
        }
    }
};
int main()
{
    Solution s;
    while (true)
    {
        int n, k;
        cout << "n: ";
        cin >> n;
        cout << "k: ";
        cin >> k;

        cout << "Answer: \n";
        vector<vector<int>> res = s.combine2(n, k);
        for (vector<int> i : res)
        {
            cout << "[";
            for (int j : i)
            {
                cout << j << ", ";
            }
            cout << "]\n";
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