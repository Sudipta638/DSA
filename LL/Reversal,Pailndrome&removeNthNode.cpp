#include <bits/stdc++.h>
using namespace std;
// Reverse a LL
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

void printLL(Node *LL)
{
    while (LL != NULL)
    {
        cout << LL->data << "->";
        LL = LL->next;
    }
    cout << "NULL" << endl;
}

Node *reverseLL(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node *recursionreverseLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *newHead = recursionreverseLL(head->next);
    Node *temp = head->next;
    temp->next = head;
    head->next = NULL;
    return newHead;
}
Node *reverseList(Node *head)
{
    Node *current = head;
    Node *prev = NULL;
    Node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
bool isPalindrome(Node *head)
{
    Node *fast = head;
    Node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *rev = reverseList(slow);
    Node *ac = head;
    while (rev != NULL)
    {
        if (rev->data != ac->data)
        {
            return false;
        }
        rev = rev->next;
        ac = ac->next;
    }
    return true;
}

Node *removeNthFromEnd(Node *head, int n)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *first = head;
    Node *second = head;

    for (int i = 0; i < n; ++i)
    {
        first = first->next;
    }
    if (first == NULL)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    while (first->next != nullptr)
    {
        first = first->next;
        second = second->next;
    }

    Node *temp = second->next;
    second->next = second->next->next;
    delete temp;

    return head;
}

Node *deleteMiddle(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *fast = head;
    Node *slow = head;
    Node *prev = NULL;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    // cout<<prev->val<<" "<<slow->val<<" "<<slow->next->val<<endl;

    prev->next = prev->next->next;
    delete slow;
    return head;
}

void detectAndRemoveLoop(Node *head)
{
    // If list is empty or has only one node without loop
    if (head == NULL || head->next == NULL)
        return;

    Node *slow = head, *fast = head;

    // Move slow and fast 1 and 2 steps ahead respectively.
    slow = slow->next;
    fast = fast->next->next;

    // Search for loop using slow and fast pointers
    while (fast && fast->next)
    {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }

    /* If loop exists */
    if (slow == fast)
    {
        slow = head;

        // this check is needed when slow and fast both meet
        // at the head of the LL eg: 1->2->3->4->5 and then
        // 5->next = 1 i.e the head of the LL
        if (slow == fast)
            while (fast->next != slow)
                fast = fast->next;
        else
        {
            while (slow->next != fast->next)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }

        /* since fast->next is the looping point */
        fast->next = NULL; /* remove loop */
    }
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
    Node *newhead = reverseLL(head);
    printLL(newhead);
    Node *newhead1 = recursionreverseLL(newhead);
    printLL(newhead1);
    return 0;
}