/*
Problem:https://leetcode.com/problems/can-place-flowers/description/
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
        This problem is simple, just imitate the planting. Carefull about the
        edge of the array.
        Treat it seperately.
    */
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        if (n == 0)
        {
            return true;
        }
        else if (flowerbed.size() == 1 && flowerbed[0] == 0)
        {
            if (n > 1)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        for (int i = 0; i < flowerbed.size(); i++)
        {
            if (flowerbed[i] == 0)
            {
                if (i == 0)
                {
                    if (flowerbed[i + 1] == 0)
                    {
                        --n;
                        flowerbed[i] = 1;
                    }
                }
                else if (i == flowerbed.size() - 1)
                {
                    if (flowerbed[i - 1] == 0)
                    {
                        --n;
                        flowerbed[i] = 1;
                    }
                }
                else if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
                {
                    --n;
                    flowerbed[i] = 1;
                }
            }
            if (n == 0)
            {
                return true;
            }
        }
        return false;
    }
};
int main()
{
    Solution s;
    while (true)
    {
        int size, n;
        cout << "Size: ";
        cin >> size;
        cout << "n flowers: ";
        cin >> n;
        vector<int> flowerbed(size);
        cout << "Flowerbed: ";
        for (int i = 0; i < size; i++)
        {
            cin >> flowerbed[i];
        }
        cout << "Answer: " << (s.canPlaceFlowers(flowerbed, n) ? "Yes " : "No ") << "\n";
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