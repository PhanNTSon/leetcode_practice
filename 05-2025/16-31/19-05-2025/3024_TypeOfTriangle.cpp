/*
Problem:https://leetcode.com/problems/type-of-triangle/description/?envType=daily-question&envId=2025-05-19
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
    string triangleType(vector<int> &nums)
    {
        int a, b, c;
        a = nums[0];
        b = nums[1];
        c = nums[2];
        if (a + b <= c || a + c <= b || b + c <= a)
        {
            return "none";
        }
        if (a == b && b == c)
        {
            return "equilateral";
        }
        if (a == b || b == c || a == c)
        {
            return "isosceles";
        }
        else
        {
            return "scalene";
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
        for (int i = 0; i < n; i++)
        {
            cout << "[" << i << "]: ";
            cin >> nums[i];
        }
        cout << "Answer: " << s.triangleType(nums) << "\n";
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