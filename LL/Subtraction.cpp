#include<bits/stdc++.h>
using namespace std;


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
class Solution {
public:
    Node*Rev(Node* head){
        if(head==NULL||head->next==NULL)
          return head;
        Node * newhead = Rev(head->next);
        Node*temp = head->next;
        temp->next = head;
        head->next=NULL;
        return newhead;
    }
    Node* subLinkedList(Node* head1, Node* head2) {
        
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        while(head1!=NULL&&head1->data==0)
           head1= head1->next;
         while(head2!=NULL&&head2->data==0)
           head2= head2->next;
        if(head1==NULL&& head2== NULL)
            return new Node(0);
        if(head1==NULL)
          return head2;
        if(head2 == NULL)
           return head1;
        //cout<<head1->data<<endl;
        Node*temp1 = head1;
        int len1 = 0;
        while(temp1!=NULL){
            temp1= temp1->next;
            len1++;
        }
        Node*temp2 = head2;
        int len2 = 0;
        while(temp2!=NULL){
            temp2= temp2->next;
            len2++;
        }
        if(len2>len1){
            Node*temp3 = head1;
            head1= head2;
            head2 = temp3;
        }
      // cout<<head1->data<<endl;
       temp2 = head2;
            temp1 = head1;
        if(len2 == len1){
            
            while(temp1!=NULL&& temp2!=NULL)
            {
                if(temp1->data>temp2->data){
                    
                     break;
                }else if(temp1->data<temp2->data){
                    Node*temp3 = head1;
                     head1= head2;
                     head2 = temp3;
                     break;
                }
                temp1 = temp1->next;
                temp2 =temp2->next;
            }
        }
        
        //cout<<head1->next->data<<endl;
        Node*revhead1 =Rev(head1);
        Node*revhead2 = Rev(head2);
        Node*ans = new Node(0);
        Node*temp = ans;
        int borrow =0;
        while(revhead1!=NULL&& revhead2!=NULL){
            int data = revhead1->data - revhead2->data -borrow;
            borrow =0;
            if(data<0){
                data+=10;
                borrow =1;
            }
            revhead1= revhead1->next;
             revhead2= revhead2->next;
            if(data ==0 &&!revhead1&& !revhead2)
              continue;
            Node* newnode = new Node(data);
            temp->next = newnode;
            temp= temp->next; 
             
            
        }
        while(revhead1!=NULL){
             int data = revhead1->data  -borrow;
             borrow =0;
            if(data<0){
                data+=10;
                borrow =1;
            }
            revhead1= revhead1->next;
             if(data ==0 &&!revhead1)
              continue;
            Node* newnode = new Node(data);
            temp->next = newnode;
            temp= temp->next;
            
        }
         while(revhead2!=NULL){
             int data = revhead2->data  -borrow;
            if(data<0){
                data+=10;
                borrow =1;
            }
            revhead2= revhead2->next;
             if(data ==0 &&!revhead2)
              continue;
            Node* newnode = new Node(data);
            temp->next = newnode;
            temp= temp->next; 
            
        }
        
        ans = Rev(ans->next);
        while(ans!=NULL&&ans->data==0)
           ans= ans->next;
        return ans!=NULL?ans:new Node(0);
    }
};