/*
Problem:https://leetcode.com/problems/find-numbers-with-even-number-of-digits/description/?envType=daily-question&envId=2025-04-30
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
    Explain #1 Solution:
        Each number we divided by 10 and each time we divided by 10
        we calculate the total digits of the current number.
    */
    int findNumbers(vector<int> &nums)
    {
        int factor = 10;
        int countDigit, countNum = 0;
        for (int i : nums)
        {
            countDigit = 0;
            while (i > 0)
            {
                i = i / factor;
                ++countDigit;
            }
            if (countDigit % 2 == 0)
            {
                ++countNum;
            }
        }
        return countNum;
    }

    /*
    Explain #2 Solution:
        Each number we change to string and check if size of string
        if even or odd.
    */
    int findNumbers2(vector<int> &nums)
    {
        int countNum = 0;
        for (int i : nums)
        {
            if (to_string(i).size() % 2 == 0)
                countNum++;
        }
        return countNum;
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
        cout << "Numbers: " << "\n";
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        cout << "Answer: " << s.findNumbers(nums) << "\n";
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