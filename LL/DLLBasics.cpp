#include<bits/stdc++.h>
using namespace std;
//DLL Basic Operations

class Node
{
public:
    int data;
    Node *next;
    Node *back;
    Node(int data1, Node *next1 ,Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    };
    Node(int data1)
    {
        data = data1;
        next = NULL;
        back = NULL;
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

Node *constructfromArray(vector<int>arr){
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for(int i =1;i<arr.size();i++){
        temp->next = new Node(arr[i]);
        temp->next->back = temp;
        temp = temp->next;
    }
    return head;
}
Node* insertAtBegining(Node *head,int x){
    Node *temp = new Node(x);
    temp->next = head;
    head->back = temp;
    return temp;
}
Node* insertAtEnd(Node *head,int x){
    Node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = new Node(x);
    temp->next->back = temp;
    return head;
}
Node* insertAtMiddle(Node *head,int x,int pos){
    Node *temp = head;
    while(pos--){
        temp = temp->next;
    }
    Node *newNode = new Node(x);
    newNode->next = temp->next;
    temp->next->back = newNode;
    temp->next = newNode;
    newNode->back = temp;
    return head;
}
Node* deleteAtBegining(Node *head){
    Node *temp = head;
    head = head->next;
    head->back = NULL;
    delete temp;
    return head;
}
Node* deleteAtEnd(Node *head){
    Node *temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    Node *temp1 = temp->next;
    temp->next = NULL;
    delete temp1;
    return head;
}
Node* deleteAtMiddle(Node *head,int pos){
    Node *temp = head;
    while(pos--){
        temp = temp->next;
    }
    Node *temp1 = temp->next;
    temp->next = temp->next->next;
    temp->next->back = temp;
    delete temp1;
    return head;
}
Node*reverseDLl(Node*head){
    Node* next = NULL;
    Node* prev = NULL;
    Node*current = head;
     while(current!=NULL){
        next = current->next;
        current->next = prev;
        current->back = next;
        prev = current;
        current = next;
     }
    return prev;
}


int main(){
    vector<int>arr = {1,2,3,4,5};
    Node *head = constructfromArray(arr);
    printLL(head);
   head = reverseDLl(head);
    printLL(head);
    return 0;
}