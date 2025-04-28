/*
Problem:https://leetcode.com/problems/valid-sudoku/description/?envType=study-plan-v2&envId=top-interview-150
*/
/*
Author: Minikie - Phan NT Son
*/
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
class Solution
{
public:
    /*
    Explain #1 Solution:
        Valid as usual, if duplicate in row/ column/ sub-matrix then
        return false.

        During check row and column, combine both row and column at
        the same time instead of separate it.

        To valid current value, check it inside an array/ vector.
        If later on a value at that index duplicate then return false.
    */
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int existed1[9] = {0};
        int existed2[9] = {0};

        char cur1, cur2;

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board.size(); j++)
            {
                cur1 = board[i][j];
                cur2 = board[j][i];
                if (cur1 != '.')
                {
                    if (existed1[cur1 - '1'] != 0)
                    {
                        return false;
                    }
                    else
                        ++existed1[cur1 - '1'];
                }

                if (cur2 != '.')
                {
                    if (existed2[cur2 - '1'] != 0)
                    {
                        return false;
                    }
                    else
                        ++existed2[cur2 - '1'];
                }
            }
            for (int i = 0; i < 9; i++)
            {
                existed1[i] = 0;
                existed2[i] = 0;
            }
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (!validSubmatrix(board, i, j))
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool validSubmatrix(vector<vector<char>> &board, int i, int j)
    {
        i = 3 * i + 2;
        j = 3 * j + 2;
        int count = 0;
        char cur;
        vector<int> existed(10, 0);
        for (int i_ = i - 2; i_ <= i; i_++)
        {
            for (int j_ = j - 2; j_ <= j; j_++)
            {
                cur = board[i_][j_];
                if (cur != '.')
                {
                    if (existed[cur - '0'] != 0)
                    {
                        return false;
                    }
                    else
                    {
                        ++existed[cur - '0'];
                    }
                }
            }
        }
        return true;
    }

    // ===================================================
    /*
    Explain #2 Solution:
        Create 3 matrix for each fields we want to check.
        If already visited it in a row/ col/ box then it's duplicated.
    */
    bool isValidSudoku2(vector<vector<char>> &board)
    {
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> box(9, vector<bool>(9, false));

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '1';
                    int boxIdx = (i / 3) * 3 + (j / 3);

                    if (row[i][num] || col[j][num] || box[boxIdx][num])
                        return false;

                    row[i][num] = col[j][num] = box[boxIdx][num] = true;
                }
            }
        }
        return true;
    }
};
int main()
{
    ifstream inputFile("matrix.txt");
    Solution s;
    vector<vector<char>> board;
    char cIn;
    while (!inputFile.eof())
    {
        vector<char> row;
        for (int i = 0; i < 9; i++)
        {
            if (inputFile >> cIn)
            {
                row.push_back(cIn);
            }
        }
        if (!row.empty())
        {
            board.push_back(row);
        }
    }
    cout << "Answer: " << s.isValidSudoku2(board) << "\n";
    return 0;
}