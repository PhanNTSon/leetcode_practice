/*
Problem:https://leetcode.com/problems/ransom-note/description/?envType=study-plan-v2&envId=top-interview-150
*/
/*
Author: Minikie - Phan NT Son
*/
#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    /*
    Explain #1 Solution:
        Hash Map approach.
        
        - Count how many times each character appears in 'magazine' using a hash map.
        - Then, iterate through each character in 'ransomNote':
        - Decrease the count in the map.
        - If the count becomes negative, it means 'magazine' doesn't have enough of that character.
        - Return false in that case.
        - If all characters in 'ransomNote' are available in sufficient amount, return true.
    */
    bool canConstruct(string ransomNote, string magazine)
    {
        map<char, int> maga;
        for (char x : magazine)
        {
            maga[x] += 1;
        }
        for (char x : ransomNote)
        {
            maga[x] -= 1;
            if (maga[x] < 0)
            {
                return false;
            }
        }
        return true;
    }

    /*
    Explain #2 Solution:
        Same logic as above but use unordered_map because this map 
        is not sort anything, therefore, speed up the time access 
        element.`
    */
    bool canConstruct2(string ransomNote, string magazine)
    {
        if (ransomNote.length() > magazine.length())
        {
            return false;
        }

        unordered_map<char, int> maga;
        for (char c : magazine)
        {
            ++maga[c];
        }

        for (char c : ransomNote)
        {
            if (--maga[c] < 0)
                return false;
        }

        return true;
    }
};

int main()
{
    Solution s;
    while (true)
    {
        string in1, in2;
        cout << "Enter ransomNote: ";
        cin >> in1;
        cout << "Enter magazine: ";
        cin >> in2;
        cout << "Answer: " << s.canConstruct2(in1, in2) << endl;
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