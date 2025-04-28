/*
Problem:https://leetcode.com/problems/valid-parentheses/description/?envType=study-plan-v2&envId=top-interview-150
*/
/*
Author: Minikie - Phan NT Son
*/
#include <iostream>
#include <stack>

using namespace std;
class Solution
{
public:
    /*
    Explain #1 Solution:
        Use a stack to store open brackets. 
        
        When encountering a closing bracket, check if the stack is 
        empty (invalid if so) or if it matches the top bracket. 
        
        After processing the entire string, if the stack is empty, 
        all brackets are properly closed.
    */
    bool isValid(string s)
    {
        stack<char> charStack;
        charStack.push(s[0]);
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == 41 || s[i] == 93 || s[i] == 125)
            {
                if (charStack.empty())
                {
                    return false;
                }
                if (s[i] - charStack.top() == 1 || s[i] - charStack.top() == 2)
                {
                    charStack.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                charStack.push(s[i]);
            }
        }
        if (!charStack.empty())
        {
            return false;
        }
        return true;
    }
};
int main()
{
    // for (int i = 0; i < 225; i++)
    // {
    //     cout << i << ": " << (char)i << "\n";
    // }
    Solution s;
    while (true)
    {
        string sIn;
        cout << "Enter here: ";
        cin >> sIn;
        cout << s.isValid(sIn) << "\n";
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