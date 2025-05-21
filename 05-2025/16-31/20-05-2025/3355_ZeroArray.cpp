/*
Problem:https://leetcode.com/problems/zero-array-transformation-i/description/?envType=daily-question&envId=2025-05-20
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
        Each query represents a range operation that will decrease values
        in nums over a certain interval. Instead of applying each query one by one,
        we use a difference array to encode how many times each index will be affected.

        For each query [l, r], we do:
            diff[l] += 1
            diff[r + 1] -= 1
        This marks the start and end+1 of a decrement operation.

        Then we use a prefix sum to calculate how many times each index
        is affected by all queries.

        If any value in nums is greater than the number of allowed decrements
        at that index, we return false. Otherwise, all values can be reduced
        to zero or below, so return true.
    */
    bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        vector<int> diff(nums.size() + 1, 0);
        vector<int> prefix(nums.size());
        for (vector<int> q : queries)
        {
            diff[q[0]] += 1;
            diff[q[1] + 1] -= 1;
        }

        int t = 0;
        for (int i = 0; i < prefix.size(); i++)
        {
            t += diff[i];
            prefix[i] = t;
            if (nums[i] > prefix[i])
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    Solution s;
    while (true)
    {
        int numsSize, queriesSize;
        cout << "Nums Size: ";
        cin >> numsSize;
        vector<int> nums(numsSize);
        for (int i = 0; i < numsSize; i++)
        {
            cout << "[" << i << "]: ";
            cin >> nums[i];
        }

        cout << "Queries Size: ";
        cin >> queriesSize;
        vector<vector<int>> queries;
        for (int i = 0; i < queriesSize; i++)
        {
            vector<int> q(2);
            cout << "[" << i << "][0]: ";
            cin >> q[0];
            cout << "[" << i << "][1]: ";
            cin >> q[1];
            queries.push_back(q);
        }

        cout << "Answer: " << ((s.isZeroArray(nums, queries) == true) ? "True" : "False") << "\n";

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