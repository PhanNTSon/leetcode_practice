/*
Problem:
https://leetcode.com/problems/remove-element/description/?envType=study-plan-v2&envId=top-interview-150
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
    int removeElement(vector<int> &nums, int val)
    {
        for (auto it = nums.begin(); it != nums.end();){
            if (*it == val){
                nums.erase(it);
            } else {
                ++it;
            }
        }
        return nums.size();
    }
};

int main()
{
    Solution s;
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    int k = s.removeElement(nums,val);
    
    for (int i : nums){
        cout << i << " ";
    }
    cout << endl << k;
    return 0;
}
