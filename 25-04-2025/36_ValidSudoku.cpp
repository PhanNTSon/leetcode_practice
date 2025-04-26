/*
Problem:https://leetcode.com/problems/valid-sudoku/description/?envType=study-plan-v2&envId=top-interview-150
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
    bool isValidSudoku(vector<vector<char>> &board)
    {
        return true;
    }
};
int main()
{
    Solution s;
    while (true)
    {
        int t = 0;
        for (int i = 0; i < 10; i++)
        {
            t += i;
        }
        cout << t;
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