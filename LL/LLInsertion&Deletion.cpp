// Insertion and Deletion in LL
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

void printLL(Node *LL)
{
    while (LL != NULL)
    {
        cout << LL->data << "->";
        LL = LL->next;
    }
    cout << "NULL" << endl;
}

Node *insertAtBegining(Node *head, int x)
{
    Node *temp = new Node(x);
    temp->next = head;
    return temp;
   
}


Node *insertAtEnd(Node *head, int x)
{
    if (head == NULL)
    {
        Node *temp = new Node(x);
        head = temp;
        return head;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new Node(x);
    return head;

}
Node *insertAtMiddle(Node *head, int x ,int pos)
{
    if (head == NULL)
    {
        Node *temp = new Node(x);
        head = temp;
        return head;
    }

    Node *temp = head;
    while (temp->next != NULL && pos>1)
    {
        temp = temp->next;
        pos--;
    }
    Node* New= new Node(x);
    Node* next = temp->next;
    New->next = next;
    temp->next = New;

    return head;
    // Your code here
}
Node* deleteAtBegining(Node*head){
    if(head ==NULL)
     return head;
     head = head->next;
     return head;
}
Node* deleteAtEnd(Node* head){
    if(head == NULL)
     return head;
         Node *temp = head;
     while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    return head;

}
Node *deleteAtMiddle(Node *head,int pos)
{
    if (head == NULL)
    {
      
        return head;
    }

    Node *temp = head;
    while (temp->next->next != NULL && pos>1)
    {
        temp = temp->next;
        pos--;
    }
   
    temp->next = temp->next->next;
    return head;
    // Your code here
}

    bool searchKey(int n, struct Node* head, int key) {
        Node* temp =head;
        for(int i =0 ;i<n;i++){
            if(temp->data == key){
                return true;
            }
            temp = temp->next;
        }
        return false;
        // Code here
    }
    
int main()
{
    Node *LL = NULL;
    LL = insertAtBegining(LL,8);
    LL = insertAtBegining(LL,0);
    LL = insertAtBegining(LL,65);
    LL = insertAtBegining(LL,64);
    LL = insertAtEnd(LL,9);
    LL = insertAtMiddle(LL,4,2);
    printLL(LL);
    LL = deleteAtBegining(LL);
    printLL(LL);
    LL = deleteAtEnd(LL);
    printLL(LL);
    LL = deleteAtMiddle(LL,2);
    printLL(LL);
}