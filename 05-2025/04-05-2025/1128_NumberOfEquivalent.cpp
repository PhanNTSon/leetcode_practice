/*
Problem:https://leetcode.com/problems/number-of-equivalent-domino-pairs/description/?envType=daily-question&envId=2025-05-04
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
        Idea:
        - Two dominoes [a, b] and [b, a] are considered equivalent.
        - So, we normalize each domino to always be (min, max).

        Steps:
        1. Create a 2D matrix map[10][10] to count each normalized pair.
        2. For each domino:
            - Sort its values (min, max) and increment the count at map[min][max].
        3. For each pair in the map with count > 1:
            - Count the number of valid combinations using the formula:
            totalPairs += count * (count - 1) / 2
            - You implemented it using a loop instead.
    */
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        int count = 0;
        vector<vector<int>> map(10, vector<int>(10, 0));
        for (vector<int> i : dominoes)
        {
            if (i[0] > i[1])
            {
                map[i[1]][i[0]]++;
            }
            else
            {
                map[i[0]][i[1]]++;
            }
        }
        for (int i = 0; i < map.size(); i++)
        {
            for (int j = i; j < map[0].size(); j++)
            {
                if (map[i][j] > 1)
                {
                    for (int k = 1; k < map[i][j]; k++)
                    {
                        count += k;
                    }
                }
            }
        }
        return count;
    }

    /*
    Explain #2 Solution:
        Idea:
        - Same logic as the first solution, but we use a 1D array instead of a 2D map.
        - Normalize each domino to (max, min) so [a, b] and [b, a] are considered the same.

        Steps:
        1. For each domino, calculate a unique index using: max * 10 + min.
        2. Increment a counter at that index.
        3. After counting, for any count > 1, use the formula:
        totalPairs += count * (count - 1) / 2
    */
    int numEquivDominoPairs2(vector<vector<int>> &dominoes)
    {
        int count;
        vector<int> counter(100, 0);
        for (auto &domino : dominoes)
        {
            int value = (domino[0] > domino[1]) ? domino[0] * 10 + domino[1]
                                                : domino[1] * 10 + domino[0];
            counter[value]++;
        }
        for (int i : counter)
        {
            if (i > 1)
            {
                count += (i) * (i - 1) / 2;
            }
        }
        return count;
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
        vector<vector<int>> dominoes;

        int n1, n2;
        for (int i = 0; i < n; i++)
        {
            cout << "--- " << i << " ---\n";
            cin >> n1;
            cin >> n2;
            vector<int> temp = {n1, n2};
            dominoes.push_back(temp);
        }

        cout << "Answer: " << s.numEquivDominoPairs2(dominoes) << "\n";

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