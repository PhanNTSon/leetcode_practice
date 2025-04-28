/*
Problem:https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/?envType=study-plan-v2&envId=top-interview-150
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
        Backtracking is a strategy where we use recursion to explore 
        all possible paths, and "turn back" (undo a move) once a path
        is either finished or invalid, allowing exploration of other possibilities.
    */
    vector<string> letterCombinations(string digits)
    {

        vector<string> res;
        if (digits.empty())
            return res;
        vector<char> index(10);
        string mem;
        char x = 'a';
        for (int i = 2; i < 10; i++)
        {
            index[i] = x;
            i == 7 ? x += 4 : x += 3;
        }
        combine(res, mem, digits, index, 0);
        return res;
    }

    void combine(vector<string> &res, string &mem, string digits, vector<char> index, int start)
    {
        int curNum = digits[start] - '0';
        char startChar = index[curNum];
        int endChar;
        (curNum == 9 || curNum == 7) ? endChar = 4 : endChar = 3;
        for (int i = 0; i < endChar; i++)
        {
            mem.push_back((char)(index[curNum] + i));
            if (start < digits.size() - 1)
            {
                combine(res, mem, digits, index, start + 1);
            }
            else
            {
                res.push_back(mem);
            }
            mem.pop_back();
        }
    }
};
int main()
{
    Solution s;
    while (true)
    {
        string digits;
        cout << "Enter here: ";
        cin >> digits;

        vector<string> result = s.letterCombinations(digits);
        for (string x : result)
        {
            cout << x + "\n";
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