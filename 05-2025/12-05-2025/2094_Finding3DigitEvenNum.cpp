/*
Problem:https://leetcode.com/problems/finding-3-digit-even-numbers/?envType=daily-question&envId=2025-05-12
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
        We use backtrack to form a group of 3 digits.
    */
    vector<int> findEvenNumbers(vector<int> &digits)
    {
        vector<int> res;
        vector<bool> marked(1000, false);
        bck(res, digits, marked, 100, 0);
        sort(res.begin(), res.end());
        return res;
    }

    void bck(vector<int> &res, vector<int> digits, vector<bool> &marked, int mul, int carry)
    {
        for (int i = 0; i < digits.size(); i++)
        {
            if (digits[i] == 0 & mul == 100)
            {
                continue;
            }
            int temp = digits[i];
            carry += temp * mul;
            digits.erase(digits.begin() + i);
            if (mul == 1)
            {
                if (carry % 2 == 0 && !marked[carry])
                {
                    res.push_back(carry);
                    marked[carry] = true;
                }
            }
            else
            {
                bck(res, digits, marked, mul / 10, carry);
            }
            carry -= temp * mul;
            digits.insert(digits.begin() + i, temp);
        }
    }

    /*
    Explain #2 Solution:
        We use frequency array to mark each digit frequencies in digits.
        After that we start to form number and check is it even or not.
    */
    vector<int> findEvenNumbers2(vector<int> &digits)
    {
        vector<int> res;
        vector<int> freq(10, 0);
        for (int i : digits)
        {
            freq[i]++;
        }
        bck2(res, freq, 100, 0);
        return res;
    }

    void bck2(vector<int> &res, vector<int> &freq, int mul, int carry)
    {
        for (int i = 0; i < 10; i++)
        {
            if (i == 0 && mul == 100)
            {
                continue;
            }
            if (freq[i] > 0)
            {
                freq[i]--;
                carry += i * mul;
                if (mul == 1)
                {
                    if (carry % 2 == 0)
                    {
                        res.push_back(carry);
                    }
                }
                else
                {
                    bck2(res, freq, mul / 10, carry);
                }
                carry -= i * mul;
                freq[i]++;
            }
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
        vector<int> digits(n);
        for (int i = 0; i < n; i++)
        {
            cout << "[" << i << "]: ";
            cin >> digits[i];
        }
        cout << "Answer: \n";
        vector<int> res = s.findEvenNumbers2(digits);
        sort(res.begin(), res.end());
        for (int i : res)
        {
            cout << i << ", ";
        }
        cout << "\n";
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