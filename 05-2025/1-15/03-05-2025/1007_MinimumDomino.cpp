/*
Problem:https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/description/?envType=daily-question&envId=2025-05-03
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
        We treat tops and bottoms as location in a 2D matrix.

        We iterate through both tops and bottoms to mark all values in
        matrix.

        Variables:
            rowSum:     total numbers in a row
            colSum:     total numbers in a col
            totalRowSum:
            totalColSum:

        Visually, if we flip the matrix diagonaly and all marked
        numbers are on same row/col means we can switch.

        Which means, totalRowNum == totalColNum == n (size)
        After that, the minimum steps to switch is just simple
        the minimum blank of a row/ col.
    */
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        vector<vector<int>> map(7, vector<int>(7, 0));
        int rowSum, colSum, totalRowSum, totalColSum;
        for (int i = 0; i < tops.size(); i++)
        {
            map[tops[i]][bottoms[i]] += 1;
        }

        int res = 0;
        for (int i = 1; i <= 6; i++)
        {
            rowSum = colSum = totalColSum = totalRowSum = 0;
            for (int j = 1; j <= 6; j++)
            {
                rowSum += map[j][i];
                colSum += map[i][j];

                totalRowSum += map[i][j];

                totalColSum += map[j][i];
                if (i != j)
                {
                    totalRowSum += map[j][i];
                    totalColSum += map[i][j];
                }
            }
            if (totalColSum == totalRowSum)
            {
                if (totalRowSum != 0)
                {
                    if (totalRowSum == tops.size())
                    {
                        res = min(totalRowSum - colSum, totalRowSum - rowSum);
                        return res;
                    }
                }
            }
        }
        return -1;
    }

    /*
    Explain #2 Solution:
        This is Greedy approach.

        The idea is we determine from 1-6, is there any number can
        be the final for tops or bottoms. We set it as target.
        
        First, we determine a domino can be flip by checking its
        top and bottom is containing target at the same time.

        If it's not containing target on both side, then we mark 
        that we can't use the current target as the final number.

        Second is we count the number of dominoes don't have the 
        target on desired side so need to flip them.
        -> topRot, bottomRot

        Finally, if a case that fit then we return the minimum 
        between topRot and bottomRot.
        Or else return -1.
    */
    int minDominoRotations2(vector<int> &tops, vector<int> &bottoms)
    {
        for (int target = 1; target <= 6; target++)
        {
            int topRot = 0, bottomRot = 0;
            bool canMake = true;
            for (int i = 0; i < tops.size(); i++)
            {
                if (tops[i] != target && bottoms[i] != target)
                {
                    canMake = false;
                    break;
                }
                if (tops[i] != target)
                    topRot++;
                if (bottoms[i] != target)
                    bottomRot++;
            }
            if (canMake)
                return min(topRot, bottomRot);
        }
        return -1;
    }
};
int main()
{
    Solution s;
    while (true)
    {
        cout << "Size: ";
        int n;
        cin >> n;

        vector<int> tops(n);
        vector<int> bottoms(n);
        cout << "Tops: ";
        for (int i = 0; i < n; i++)
        {
            cin >> tops[i];
        }
        cout << "Bottoms: ";
        for (int i = 0; i < n; i++)
        {
            cin >> bottoms[i];
        }

        cout << "Answer: " << s.minDominoRotations(tops, bottoms) << "\n";

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