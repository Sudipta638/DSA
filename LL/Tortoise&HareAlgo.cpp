#include <bits/stdc++.h>
using namespace std;
// Slow and Fast Pointer Problems
class Node
{
public:
    int data;
    Node *next;
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    };
    Node(int data1)
    {
        data = data1;
        next = NULL;
    }
};

Node *middleNode(Node *head)
{
    Node *fast = head;
    Node *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

bool hasCycle(Node *head)
{
    Node *first = head;
    Node *second = head;
    while (first != NULL && first->next != NULL)
    {
        first = first->next->next;
        second = second->next;
        if (first == second)
            return true;
    }
    return false;
}

Node *detectCycle(Node *head)
{
    Node *first = head;
    Node *second = head;
    while (first != NULL && first->next != NULL)
    {
        first = first->next->next;
        second = second->next;
        if (first == second)
        {
            second = head;
            while (second != first)
            {
                first = first->next;
                second = second->next;
            }
            return second;
        }
    }

    return NULL;
}

int countNodesinLoop( Node *head)
{
    Node* fast = head;
    Node* slow = head;
    while(fast!= NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(slow== fast){
            Node* temp = slow;
            slow =slow->next;
            int cnt = 1;
            while(temp!=slow ){
                slow= slow->next;
                cnt++;
            }
            return cnt;
        }
    }
    return 0;
    
    // Code here
}


void printLL(Node *LL)
{
    while (LL != NULL)
    {
        cout << LL->data << "->";
        LL = LL->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next->next->next = new Node(9);
    head->next->next->next->next->next->next->next->next->next = new Node(10);
    printLL(head);
    Node *mid = middleNode(head);
    cout << mid->data << endl;
    return 0;
}