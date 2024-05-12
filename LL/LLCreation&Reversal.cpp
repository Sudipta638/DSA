// Creating linklist from array

#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

public:
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

Node *converttedLL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *temp;
    Node *mover = head;
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
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

Node *revreseLL(Node *head)
{
    Node *prev = NULL;
    Node *current = head;
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

Node* recursiverevreseLL(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* newHead = recursiverevreseLL(head->next);
    Node* temp = head->next;
    temp->next = head;
    head->next = NULL;
    return newHead;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node *LL = converttedLL(arr);
    printLL(LL);
    Node *reversedLL = revreseLL(LL);
    printLL(reversedLL);
    return 0;
}