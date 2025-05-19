/*
Problem:https://leetcode.com/problems/permutations/description/
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
        Using Backtrack to solve problem.

        res:    store results.
        mem:    store number statement that has been used or not.
        path:   to add elements

        We iterate through nums array, during the process we check
        if the current value is available.
        If available then we added to path, else we continue the loop.
    */
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<bool> mem(nums.size(), false);
        vector<int> path;
        btrack(res, nums, path, mem);
        return res;
    }

    void btrack(vector<vector<int>> &res, vector<int> nums, vector<int> path, vector<bool> &mem)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (!mem[i])
            {
                path.push_back(nums[i]);
                mem[i] = true;
            }
            else
            {
                continue;
            }
            if (path.size() != nums.size())
            {
                btrack(res, nums, path, mem);
            }
            else
            {
                res.push_back(path);
            }
            path.pop_back();
            mem[i] = false;
        }
    }

    /*
    Explain #2 Solution:
        Same as above but instead of iterative through all elements,
        when we take an element we remove it from the temp array (res_nums).

        We will only loop inside res_nums array, which size is decrease after 
        each backtrack -> reduce cost time.
    */
    vector<vector<int>> permute2(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> res_nums = nums;
        vector<int> path;
        btrack2(res, path, res_nums);
        return res;
    }

    void btrack2(vector<vector<int>> &res, vector<int> path, vector<int> &res_nums)
    {
        for (int i = 0; i < res_nums.size(); i++)
        {
            int val = res_nums[i];
            // Temporary erase
            res_nums.erase(res_nums.begin() + i);

            path.push_back(val);
            if (!res_nums.empty())
            {
                btrack2(res, path, res_nums);
            }
            else
            {
                res.push_back(path);
            }
            path.pop_back();
            res_nums.insert(res_nums.begin() + i, val);
        }
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
        cout << "Nums: \n";
        for (int i = 0; i < n; i++)
        {
            cout << "[" << i << "]: ";
            cin >> nums[i];
        }

        vector<vector<int>> res = s.permute2(nums);

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