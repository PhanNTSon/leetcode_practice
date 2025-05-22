/*
Problem:https://leetcode.com/problems/set-matrix-zeroes/description/?envType=daily-question&envId=2025-05-21
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
        We use first row and colum to mark whether a column or row 
        will be fill by 0.
        First, we examine whether first column and row does contains
        0 or not and store it into:
            isRowContainZero and isColContainZero
        We will start iterate through the matrix at [1,1]
        After marking, we will iterate through first column and row 
        and fill out all row and column that being marked.
        
        If first row or column does contain 0 then we will fill first
        column or row for the last.
    */
    void setZeroes(vector<vector<int>> &matrix)
    {
        bool isRowContainZero = false, isColContainZero = false;

        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i][0] == 0)
            {
                isRowContainZero = true;
                break;
            }
        }
        for (int i = 0; i < matrix[0].size(); i++)
        {
            if (matrix[0][i] == 0)
            {
                isColContainZero = true;
                break;
            }
        }
        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < matrix[0].size(); i++)
        {
            if (matrix[0][i] == 0)
            {
                for (int j = 1; j < matrix.size(); j++)
                {
                    matrix[j][i] = 0;
                }
            }
        }

        for (int i = 1; i < matrix.size(); i++)
        {
            if (matrix[i][0] == 0)
            {
                for (int j = 1; j < matrix[0].size(); j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if (isRowContainZero)
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                matrix[i][0] = 0;
            }
        }
        if (isColContainZero)
        {
            for (int i = 0; i < matrix[0].size(); i++)
            {
                matrix[0][i] = 0;
            }
        }
    }
};
int main()
{
    Solution s;
    while (true)
    {
        int n, m;
        cout << "n:= ";
        cin >> n;
        cout << "m:= ";
        cin >> m;

        cout << "Matrix: \n";
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << "[" << i << "][" << j << "]: ";
                cin >> matrix[i][j];
            }
        }

        s.setZeroes(matrix);
        cout << "Answer: \n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << matrix[i][j] << ", ";
            }
            cout << "\n";
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