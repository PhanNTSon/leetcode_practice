/*
Problem:https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/?envType=study-plan-v2&envId=top-interview-150
*/
/*
Author: Minikie - Phan NT Son
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    /*
        Explain #1 Solution:
            This is the implementation of AVL tree.
            This solution if false to problem in Leetcode but it's a good
            implementation of AVL with good logic in rotate node.
    */
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        // TreeNode *root = new TreeNode(nums[nums.size() / 2 - 1]);
        // for (int i = 0; i < nums.size() / 2; i++)
        // {
        //     root = addToTree(nums[i], root);
        //     root = addToTree(nums[nums.size() - i - 1], root);
        // }
        TreeNode *root = new TreeNode(0);
        for (int i = 0; i < nums.size(); i++)
        {
            root = addToTree(nums[i], root);
        }
        return root;
    }

    TreeNode *addToTree(int value, TreeNode *head)
    {
        if (head == nullptr)
        {
            head = new TreeNode(value);
            return head;
        }
        else if (value > head->val)
        {
            head->right = addToTree(value, head->right);
        }
        else if (value < head->val)
        {
            head->left = addToTree(value, head->left);
        }
        else if (value == head->val)
        {
            return head;
        }

        if (head->left != nullptr && head->left->left != nullptr)
        {
            head = rotateRight(head);
        }
        else if (head->right != nullptr && head->right->right != nullptr)
        {
            head = rotateLeft(head);
        }
        else if (head->left != nullptr && head->left->right != nullptr)
        {
            head->left = rotateLeft(head->left);
            head = rotateRight(head);
        }
        else if (head->right != nullptr && head->right->left != nullptr)
        {
            head->right = rotateRight(head->right);
            head = rotateLeft(head);
        }
        return head;
    }

    TreeNode *rotateLeft(TreeNode *head)
    {
        if (head == nullptr || head->right == nullptr)
        {
            return head;
        }
        TreeNode *rightChild = head->right;
        head->right = rightChild->left;
        rightChild->left = head;
        return rightChild;
    }

    TreeNode *rotateRight(TreeNode *head)
    {
        if (head == nullptr || head->left == nullptr)
        {
            return head;
        }
        TreeNode *leftChild = head->left;
        head->left = leftChild->right;
        leftChild->right = head;
        return leftChild;
    }

    // ===============================================================
    /*
    Explain #2 Solution:
        Becasue this is a sorted array, therefore, we only need to 
        pick up the middle element and then repeat the process
        to 2 sides of the array.
        The mechanism work absolutely similar to Binary Search.
    */
    TreeNode *sortedArrayToBST2(vector<int> &nums)
    {
        TreeNode *root = add(nums, 0, nums.size() - 1);
        return root;
    }

    TreeNode *add(vector<int> &nums, int i, int j)
    {
        if (i > j)
            return nullptr;
        int mid = i + (j - i) / 2;
        TreeNode *n = new TreeNode(nums[mid]);
        n->left = add(nums, i, mid - 1);
        n->right = add(nums, mid + 1, j);
        return n;
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

        TreeNode *root = s.sortedArrayToBST2(nums);

        queue<TreeNode *> q;
        q.push(root);
        TreeNode *cur;
        while (!q.empty())
        {
            cur = q.front();
            q.pop();

            if (cur != nullptr)
            {
                cout << cur->val << ", ";
                q.push(cur->left);
                q.push(cur->right);
            }
            else
            {
                cout << "null, ";
            }
        }
        cout << endl;

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