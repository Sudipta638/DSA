#include <bits/stdc++.h>
using namespace std;
// copy the list with random pointer
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        Node *copynode = new Node(temp->val);
        copynode->next = temp->next;
        temp->next = copynode;
        temp = temp->next->next;
    }
    temp = head;
    while (temp != NULL)
    {
        Node *copynode = temp->next;
        temp->random ? copynode->random = temp->random->next : copynode->random = NULL;
        temp = temp->next->next;
    }
    Node *dummy = new Node(-1);
    temp = head;
    Node *res = dummy;
    while (temp != NULL)
    {
        res->next = temp->next;
        temp->next = temp->next->next;
        res = res->next;
        temp = temp->next;
    }
    return dummy->next;
}
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->random = head->next->next;
    head->next->random = head->next->next->next->next;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next->next->next;
    head->next->next->next->next->random = head->next;
    head->next->next->next->next->next->random = head->next->next;
    Node *res = copyRandomList(head);
    while (res != NULL)
    {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}