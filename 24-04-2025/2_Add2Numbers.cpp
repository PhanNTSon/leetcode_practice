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
    /*
    Explain #1 Solution:
        tHead       is a dummy node that helps build the result.
        tCur        is the current node in the result list.
        tail        is used to track the last valid node.
        remain      holds the carry (like the digit overflow when summing).

        Process like normal, if have carry then have to process it.
    */
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int remain = 0;
        ListNode *tHead = new ListNode();
        ListNode *tCur = tHead;
        ListNode *tail = tCur;
        while (l1 != nullptr && l2 != nullptr)
        {
            tCur->val = (l1->val + l2->val + remain) % 10;
            ListNode *newDigit = new ListNode();
            remain = (l1->val + l2->val + remain) / 10;
            tCur->next = newDigit;
            tail = tCur;
            tCur = tCur->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr)
        {
            tCur->val = (l1->val + remain) % 10;
            ListNode *newDigit = new ListNode();
            remain = (l1->val + remain) / 10;
            tCur->next = newDigit;
            tail = tCur;
            tCur = tCur->next;
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            tCur->val = (l2->val + remain) % 10;
            ListNode *newDigit = new ListNode();
            remain = (l2->val + remain) / 10;
            tCur->next = newDigit;
            tail = tCur;
            tCur = tCur->next;
            l2 = l2->next;
        }
        if (remain > 0)
        {
            tCur->val = remain;
            tail = tCur;
        }
        tail->next = nullptr;
        return tHead;
    }

    /*
    Explain #2 Solution:
        Using only 1 loop, ends only when both l1 and l2 are reach 
        the end and no remain carry.
        In each loop, check if list reach it's end or not, it so
        then add to sum to process.
    */
    ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *current = dummy;
        int carry = 0;

        while (l1 || l2 || carry)
        {
            int sum = carry;
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            current->next = new ListNode(sum % 10);
            carry = sum / 10;
            current = current->next;
        }

        return dummy->next;
    }
};

int main()
{
    Solution s;
    LinkedList l1;
    LinkedList l2;
    while (true)
    {
        int n1, n2;
        cout << "Size l1: ";
        cin >> n1;
        cout << "Size l2: ";
        cin >> n2;

        cout << "---- 1 -----" << endl;
        for (int i = 0; i < n1; i++)
        {
            int input;
            cout << "[" << i << "]";
            cin >> input;
            ListNode *newNode = new ListNode(input);
            l1.addNew(newNode);
        }
        cout << "---- 2 -----" << endl;
        for (int i = 0; i < n2; i++)
        {
            int input;
            cout << "[" << i << "]";
            cin >> input;
            ListNode *newNode = new ListNode(input);
            l2.addNew(newNode);
        }

        cout << "Answer: ";
        ListNode *cur = s.addTwoNumbers(l1.head, l2.head);
        while (cur != nullptr)
        {
            cout << cur->val;
            cur = cur->next;
        }
        cout << endl;
        char x;
        cout << "Continue ? Y/N:";
        cin >> x;
        if (x == 'n' || x == 'N')
        {
            break;
        }
        l1.clear();
        l2.clear();
    }
    return 0;
}