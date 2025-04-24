/*
Problem:https://leetcode.com/problems/add-two-numbers/description/?envType=study-plan-v2&envId=top-interview-150
*/
/*
Author: Minikie - Phan NT Son
*/
#include <iostream>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct LinkedList
{
    ListNode *head;
    ListNode *tail;

    void addNew(ListNode *newNode)
    {
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void clear()
    {
        ListNode *cur = head;
        while (cur != nullptr)
        {
            ListNode *temp = cur;
            cur = cur->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int remain = 0;
        int mul = 1;
        int total = 0;
        while (l1 != nullptr && l2 != nullptr)
        {
            total += ((l1->val + l2->val) % 10 + remain) * mul;
            remain = (l1->val + l2->val) / 10;

            mul *= 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1->next != nullptr)
        {
            total += l1->val * mul;
            mul *= 10;
        }
        while (l2->next != nullptr)
        {
            total += l2->val * mul;
            mul *= 10;
        }
        return total;
    }
};

int main()
{
    Solution s;
    while (true)
    {

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