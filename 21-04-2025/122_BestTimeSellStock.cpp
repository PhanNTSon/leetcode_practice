/*
Problem:https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/?envType=study-plan-v2&envId=top-interview-150
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
        isHold: A flag to track whether we're currently holding a stock.
        We iterative through the price list. Each day:
            If tomorrow's price is higher, we buy today if we're not holding.
            If tomorrow's price is lower, we sell today if we're holding.
            If today is the last day, we sell if we're still holding.
        We use "isHold" to decide when buying or selling to avoid invalid
        operations like buying 2 times in a row or selling without holding.
    */
    int maxProfit(vector<int> &prices)
    {
        int total = 0;
        bool isHold = false;
        for (int i = 0; i < prices.size(); i++)
        {
            if (i == prices.size() - 1)
            {
                if (isHold)
                {
                    isHold = false;
                    total += prices[i];
                }
            }
            else
            {
                if (prices[i] > prices[i + 1])
                {
                    if (isHold)
                    {
                        isHold = false;
                        total += prices[i];
                    }
                }
                else
                {
                    if (!isHold)
                    {
                        isHold = true;
                        total -= prices[i];
                    }
                }
            }
        }
        return total;
    }

    /*
    Explain #2 Solution:
        Instead of simulating buy/sell, simplified with Greedy approach:
            Every time prices[i] > prices[i-1] then collect the profit - no
            need to simulate holding.
    */
    int maxProfit2(vector<int> &prices)
    {
        int total = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] > prices[i - 1])
            {
                total += prices[i] - prices[i - 1];
            }
        }
        return total;
    }
};

int main()
{
    Solution s;
    while (true)
    {
        int n;
        cout << "Enter size: ";
        cin >> n;
        vector<int> prices(n);

        for (int i = 0; i < prices.size(); i++)
        {
            cout << "[" << i << "]: ";
            cin >> prices[i];
        }

        cout << "Max profit: " << s.maxProfit2(prices) << endl;

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