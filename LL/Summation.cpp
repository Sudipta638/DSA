//Summation
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    };
    Node(int data1){
        data = data1;
        next = NULL;
    }
};

Node* reverseLL(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
 Node* addOne(Node *head) 
    {
        Node* rev = reverseLL(head);
        Node* t= rev;
        int x = rev->data +1;
        int c =x/10;
        Node*ans =new Node(x%10) ;
        //Node* mod = ans;
        rev= rev->next;
        while(rev!=NULL){
            int x = rev->data +c;
            c = x/10;
            Node*temp =new Node(x%10) ;
            temp->next = ans;
            ans = temp;
            rev= rev->next;
        }
        if(c!=0){
           Node*temp =new Node(c) ;
          temp->next = ans;
            ans = temp; 
        }
        return ans;
        // Your Code here
        // return head of list after adding one
    }

    Node * addTwoNumbers(Node * l1, Node * l2) {

        Node *p =l1;
        Node *r  =l2;
        int s =(p->data +r->data)%10;
        Node *ans =new Node(s);
        Node *sum = ans;
        int c =(p->data +r->data)/10 ;
        p= p->next;
        r= r->next;
        
        while(p!=NULL&&r!=NULL){
            int x = c+p->data+r->data;
            s = x%10;
            c=x/10;
            Node*temp =new Node(s);
            sum->next= temp;
            sum = sum->next;
            p= p->next;
            r= r->next;
        }
        while(p!=NULL){
            int x = c+p->data;
            s = x%10;
            c=x/10;
            Node*temp =new Node(s);
            sum->next= temp;
            sum = sum->next;
            p= p->next;
           // r= r->next;
        }
         while(r!=NULL){
            int x = c+r->data;
            s = x%10;
            c=x/10;
            Node*temp =new Node(s);
            sum->next= temp;
            sum = sum->next;
           // p= p->next;
            r= r->next;
        }
        if(c!=0){
            Node*temp =new Node(c);
            sum->next = temp;
        }
        return ans;
    }

    int main(){
        Node*  head = new Node(1);
        head->next = new Node(2);
        head->next->next = new Node(9);
        Node* head2 = new Node(1);
        head2->next = new Node(2);
        head2->next->next = new Node(9);
        Node* ans = addTwoNumbers(head,head2);
        while(ans!=NULL){
            cout<<ans->data<<" ";
            ans = ans->next;
        }
        return 0;
    }