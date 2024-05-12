// Sorting
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int val1, Node *next1)
    {
        val = val1;
        next = next1;
    };
    Node(int val1)
    {
        val = val1;
        next = NULL;
    }
};

Node *findMiddle(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *slow = head;
    Node *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
Node *merge(Node *left, Node *right)
{
    Node *dummy = new Node(-1);
    Node *temp = dummy;
    while (left != NULL && right != NULL)
    {
        if (left->val < right->val)
        {
            temp->next = left;
            left = left->next;
            temp = temp->next;
        }
        else
        {
            temp->next = right;
            right = right->next;
            temp = temp->next;
        }
    }
    if (left)
        temp->next = left;
    else
        temp->next = right;
    return dummy->next;
}
Node *mergesort(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *middle = findMiddle(head);
    Node *lefthead = head;
    Node *righthead = middle->next;
    middle->next = NULL;
    Node *left = mergesort(lefthead);
    Node *right = mergesort(righthead);
    return merge(left, right);
}

Node *sortList(Node *head)
{

    return mergesort(head);
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(10);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(70);
    head->next->next->next->next->next->next->next = new Node(8);
    Node *temp = sortList(head);
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}