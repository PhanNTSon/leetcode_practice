/*
Problem:https://leetcode.com/problems/subsets/description/
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
        We use Backtrack to generate all subsets from given array.

        We go through all possible size of subset from 1 to nums.size()
        For each size, we use backtrack to explore all possibles
        combinations of that length.
        To avoid reusing the same element, we use startIndex to move
        forward.

        The base case is when path.size() == maxSize, means
        we have formed a valid subset.
    */
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> path;
        result.push_back(path);
        for (int i = 1; i <= nums.size(); i++)
        {
            backtrack(nums, result, path, i, 0);
        }
        return result;
    }

    void backtrack(vector<int> nums, vector<vector<int>> &result, vector<int> &path, int maxSize, int startIndex)
    {
        for (int i = startIndex; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            if (path.size() < maxSize)
            {
                backtrack(nums, result, path, maxSize, i + 1);
            }
            else
            {
                result.push_back(path);
            }
            path.pop_back();
        }
    }

    // ==============================================
    /*
    Explain #2 Solution:
        The idea is same as above but we use backtrack to handle 
        the size of all subsets rather than loop through all the 
        sizes like above.

        
    */
    vector<vector<int>> subsets2(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> path;
        backtrack2(nums, 0, path, result);
        return result;
    }

    void backtrack2(vector<int> &nums, int startIndex, vector<int> &path, vector<vector<int>> &result)
    {
        result.push_back(path);
        for (int i = startIndex; i < nums.size(); ++i)
        {
            path.push_back(nums[i]);
            backtrack2(nums, i + 1, path, result);
            path.pop_back();
        }
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
        vector<int> nums(n);
        cout << "Nums: \n";
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        cout << "Answer: \n";
        vector<vector<int>> res = s.subsets2(nums);
        for (int i = 0; i < res.size(); i++)
        {
            for (int j = 0; j < res[i].size(); j++)
            {
                cout << res[i][j] << ", ";
            }
            cout << "\n";
        }
        cout << res.size() << "\n";
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