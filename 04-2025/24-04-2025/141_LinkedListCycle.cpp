/*
Problem:https://leetcode.com/problems/linked-list-cycle/description/?envType=study-plan-v2&envId=top-interview-150
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct LinkedList
{
    ListNode *head;
    ListNode *tail;
    int size;

    LinkedList()
    {
        this->size = 0;
    }

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
        this->size++;
    }

    void createCycle(int index)
    {
        ListNode *cur = this->head;
        for (int i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        this->tail->next = cur;
    }

    void clear()
    {
        ListNode *curr = this->head;
        while (curr != nullptr)
        {
            ListNode *temp = curr;
            curr = curr->next;
            delete temp;
        }
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }
};

class Solution
{
public:
    /*
    Explain #1 Solution:
        Floyd’s Tortoise and Hare algorithm.

        - Use two pointers: slow (p1) and fast (p2).
        - p1 moves one step at a time.
        - p2 moves two steps at a time.
        - If there is a cycle, the fast pointer will eventually meet the slow pointer inside the cycle.
        - If there is no cycle, the fast pointer will reach the end (nullptr).
    */
    bool hasCycle(ListNode *head)
    {
        ListNode *p1 = head;
        ListNode *p2 = head;

        if (head == nullptr || head->next == nullptr)
        {
            return false;
        }
        while (p2 != nullptr && p2->next != nullptr)
        {
            p1 = p1->next;
            p2 = p2->next->next;
            
            if (p2 == p1)
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
        LinkedList list;
        int n;
        cout << "Enter size: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int input;
            cout << "[" << i << "]: ";
            cin >> input;
            ListNode *n = new ListNode(input);
            list.addNew(n);
        }

        int pos;
        cout << "Pos: ";
        cin >> pos;

        if (pos >= 0)
        {
            list.createCycle(pos);
        }

        cout << "Answer: " << s.hasCycle(list.head) ? "Yes" : "No";
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