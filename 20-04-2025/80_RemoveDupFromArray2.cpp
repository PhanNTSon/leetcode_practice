/*
Problem:https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/?envType=study-plan-v2&envId=top-interview-150
Explain Solution:
    k: Index where the next valid element will be inserted.
    c: Counter to keep track of how many times the current element has appeared.

    If an element has appeared less than 3 times (c < 3), then it's still considered valid. 
    Therefore, we insert it at index k, and then increment k.
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
    int removeDuplicates(vector<int> &nums)
    {
        int k = 1;
        int c = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                c++;
            }
            else
            {
                c = 1;
            }
            if (c < 3)
            {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};
int main()
{
    Solution s;
    while (true)
    {
        int n;
        cout << "Enter size: ";
        cin >> n;
        vector<int> nums(n);

        for (int i = 0; i < nums.size(); i++)
        {
            cin >> nums[i];
        }
        s.removeDuplicates(nums);
        for (int i : nums)
        {
            cout << i << " ";
        }
        char x;
        cout << endl
             << "Continue ? Y/N:";
        cin >> x;
        if (x == 'n' || x == 'N')
        {
            break;
        }
    }
    return 0;
}