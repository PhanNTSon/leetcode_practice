/*
Problem:https://leetcode.com/problems/three-consecutive-odds/description/?envType=daily-question&envId=2025-05-11
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
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        int i = 0;
        int count = 0;
        while (i < arr.size())
        {
            if (arr[i] % 2 != 0)
            {
                ++count;
            }
            else
            {
                count = 0;
            }
            if (count == 3)
            {
                return true;
            }
            ++i;
        }
        return false;
    }
};
int main()
{
    Solution s;
    while (true)
    {
        int n;
        cout << "Array size: ";
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cout << "[" << i << "]: ";
            cin >> arr[i];
        }

        cout << "Answer: " << s.threeConsecutiveOdds(arr) << "\n";

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