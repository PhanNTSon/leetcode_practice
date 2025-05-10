/*
Problem:https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/description/?envType=daily-question&envId=2025-05-10
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
        We calculate the minimum sum of each arrays. 
        A:  array 1
        B:  array 2

        if sumA < sumB and countA > 0 means sumA can reach
        to sumB and reverse.

        They can't reach to each other if there is no 0's
        in the array.
        
    */
    long long minSum(vector<int> &nums1, vector<int> &nums2)
    {
        long long sumA, sumB, countA, countB;
        sumA = sumB = countA = countB = 0;
        // for (int i : nums1)
        // {
        //     sumA += i;
        //     countA += (i == 0) ? 1 : 0;
        // }
        // for (int i : nums2)
        // {
        //     sumB += i;
        //     countB += (i == 0) ? 1 : 0;
        // }

        int i = 0;
        while (i < nums1.size() && i < nums2.size())
        {
            sumA += nums1[i];
            sumB += nums2[i];

            countA += (nums1[i] == 0) ? 1 : 0;
            countB += (nums2[i] == 0) ? 1 : 0;
            ++i;
        }

        while (i < nums1.size())
        {
            sumA += nums1[i];
            countA += (nums1[i] == 0) ? 1 : 0;
            ++i;
        }
        while (i < nums2.size())
        {
            sumB += nums2[i];
            countB += (nums2[i] == 0) ? 1 : 0;
            ++i;
        }

        long long x, x1;
        x = sumA + 1 * countA;
        x1 = sumB + 1 * countB;
        if (x == x1)
        {
            return x;
        }
        if (x < x1)
        {
            return (countA > 0) ? x1 : -1;
        }
        else
        {
            return (countB > 0) ? x : -1;
        }
    }
};
int main()
{
    Solution s;
    while (true)
    {
        int n1, n2;
        cout << "Array 1 size: ";
        cin >> n1;
        vector<int> nums1(n1);
        for (int i = 0; i < n1; i++)
        {
            cout << "[" << i << "]: ";
            cin >> nums1[i];
        }
        cout << "Array 2 size: ";
        cin >> n2;
        vector<int> nums2(n2);
        for (int i = 0; i < n2; i++)
        {
            cout << "[" << i << "]: ";
            cin >> nums2[i];
        }

        cout << "Answer: " << s.minSum(nums1, nums2) << "\n";

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