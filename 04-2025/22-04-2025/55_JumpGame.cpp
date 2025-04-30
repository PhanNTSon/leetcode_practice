/*
Problem:https://leetcode.com/problems/jump-game/description/?envType=study-plan-v2&envId=top-interview-150
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
        temp: Current position (starting from the end).
        i: Number of steps we're testing to move backward.

        We use backward approach:
            At each step, we check if it's possible to jump to our current
            postion (temp) from any previous index (temp - i).
            If nums[temp - i] >= i; then it's a valid jumps
            -> So we move our temp back to temp - i, and reset i to 1.

        The goal is to reach index 0.
            If we reach index 0 then return True.
            If i exceeds temp, it means no previous position can jump here.
            -> Return False
    */
    bool canJump(vector<int> &nums)
    {
        int temp = nums.size() - 1;
        int i = 1;
        while (temp >= 0)
        {
            if (nums.size() == 1)
            {
                return true;
            }
            if (i <= nums[temp - i])
            {
                temp -= i;
                i = 1;
            }
            else
            {
                ++i;
            }
            if (temp == 0)
            {
                return true;
            }
            if (i > temp)
            {
                return false;
            }
        }
        return false;
    }

    /*
    Explain #2 Solution:
        goal: Index we trying to reach (starting from the last index).

        We loop backward, at each position i, we check if we can jump
        from index i to the goal.
        If i + nums[i] >= goal, it means we can reach the current goal
        from position i.
        -> Therefore, we update goal = i, move goal closer.
        
        If we eventually move the goal all the way to the beginning 
        (goal == 0), it means the start can reach the end
        -> return True

        If we finish the loop but goal != 0, it means we cant reach the
        end
        -> return False
    */
    bool canJump2(vector<int> &nums)
    {
        int goal = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (i + nums[i] >= goal)
            {
                goal = i;
            }
        }
        return goal == 0;
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
        vector<int> nums(n);

        for (int i = 0; i < nums.size(); i++)
        {
            cout << "[" << i << "]: ";
            cin >> nums[i];
        }

        cout << "Answer: " << s.canJump2(nums) << endl;

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