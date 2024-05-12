//RotateLL
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;   
    Node* next;      
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};
Node* rotateRight(Node* head, int k) {
        if(head==NULL ||head->next ==NULL ||k==0)
         return head;
        int len =1;
        Node* last = head;
        while(last->next!=NULL){
            len++;
            last = last->next;
        }
        k = k%len;
        if(k==0)
         return head;
        int midpoint = len-k-1;
        Node*font = head;
        Node*mid = head;
        while (mid != NULL & midpoint > 0) {
            mid = mid->next;
            midpoint--;
        }
       
        Node*ans = mid->next;
        last->next = font;
        mid->next =NULL;
        return ans;
    }

    int main(){
         Node* head = new Node(5);
    head->next = new Node(4);
    head->next->next = new Node(3);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next = new Node(1);
    Node *head = rotateRight(head,3);
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
        return 0;
    }