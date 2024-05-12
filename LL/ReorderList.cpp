#include<bits/stdc++.h>
using namespace std;

//Reorder a LL
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

 Node* MiddleNode(Node * head){
        if(head == NULL|| head->next == NULL)
          return head;
        Node* slow = head;
        Node* fast = head;
        while(fast->next!=NULL&& fast->next->next!=NULL){
            fast = fast->next->next;
            slow= slow->next;
        }
        return slow;
     }
     Node* Rev(Node*head){
        Node* cur = head;
        Node *prev =NULL;
        Node* next = NULL;
        while(cur!=NULL){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
     }
    void reorderList(Node* head) {
        Node* mid= MiddleNode(head);
        Node* rev = Rev(mid->next);
        mid->next = NULL;
        Node* temp = head;
        Node* revtemp = rev;
        while(temp!=NULL&& revtemp!=NULL){
            Node* next = temp->next;
            Node* revnext = revtemp->next;
            temp->next = revtemp;
            revtemp->next = next;
            temp = next;
            revtemp = revnext;
        }
       
    }


int main(){
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);
    reorderList(head);
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL";
    return 0;
}