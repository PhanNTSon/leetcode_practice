/*
Problem:https://leetcode.com/problems/push-dominoes/description/?envType=daily-question&envId=2025-05-02
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
        We iterate through the string and react when find a 'L' or 'R'.
        - If it's a 'R', we simulate the falling by replace all '.' -> 'R'
        - If it's a 'L', we have 2 cases:
            If there was a previous 'R', we balances the forces. The middle 
            domino stay upright if the distance is odd. (step % 2 != 0)
            
            Otherwise, let it fall until it's blocked or reach the edge.

        Variables:
        step    :keeps track how far dominoes have been pushed right, after
                we use it to decide how many dominose to push left when
                we approaching a 'L'.
        
    */
    string pushDominoes(string dominoes)
    {
        int step = 0;
        int i = 0;
        while (i < dominoes.size())
        {
            if (dominoes[i] == 'L')
            {
                fallLeft(dominoes, i, step);
            }
            else if (dominoes[i] == 'R')
            {
                fallRight(dominoes, i, step);
            }
            if (step > 0)
            {
                i += step + 1;
            }
            else
            {
                i += 1;
            }
        }
        return dominoes;
    }

    void fallLeft(string &str, int ind, int &step)
    {
        if (step > 0)
        {
            for (int j = 1; j <= step / 2; j++)
            {
                str[ind - j] = 'L';
            }
            if (step % 2 != 0)
            {
                str[ind - step / 2 - 1] = '.';
            }
        }
        else
        {
            while (ind - 1 >= 0 && str[ind - 1] == '.' && !isStuck(str, ind - 1))
            {
                str[ind - 1] = 'L';
                ind -= 1;
            }
        }
        step = 0;
    }

    void fallRight(string &str, int ind, int &step)
    {
        step = 0;
        if (isStuck(str, ind + 1))
        {
            return;
        }
        while (str[ind + 1] == '.')
        {
            str[ind + 1] = 'R';
            step++;
            ind++;
        }
    }

    bool isStuck(string &str, int ind)
    {
        if (ind - 1 < 0 || ind + 1 >= str.size())
        {
            return false;
        }
        if (str[ind - 1] == 'R' && str[ind + 1] == 'L' ||
            str[ind - 1] == 'L' && str[ind + 1] == 'R')
        {
            return true;
        }
        return false;
    }
};
int main()
{
    Solution s;
    while (true)
    {
        string dominose;
        cin >> dominose;
        cout << "Answer: " << s.pushDominoes(dominose) << "\n";
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