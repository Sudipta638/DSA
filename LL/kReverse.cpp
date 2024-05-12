#include <iostream>
#include <bits/stdc++.h>

using namespace std;
//Reverse in a group of K
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

Node* reverseLinkedList(Node *head)
{
   Node* temp = head;  
   
   Node* prev = NULL;  


   while(temp != NULL){  

       Node* front = temp->next;  

       temp->next = prev;  
       

       prev = temp;  

       temp = front; 
   }
   

   return prev;  
}
Node* getKthNode(Node* temp, int k){

    k -= 1; 

  
    while(temp != NULL && k > 0){

        k--; 
        
        temp = temp -> next; 
    }

    return temp; 
}

Node* kReverse(Node* head, int k){
    
    Node* temp = head; 

    Node* prevLast = NULL; 
    

    while(temp != NULL){
        Node* kThNode = getKthNode(temp, k); 

        
        if(kThNode == NULL){
            if(prevLast){
                prevLast -> next = temp; 
            }
            break; 
        }
        
        Node* nextNode = kThNode -> next; 

        kThNode -> next = NULL; 

        reverseLinkedList(temp); 
        
        
        if(temp == head){
            head = kThNode;
        }else{
        
            prevLast -> next = kThNode; 
        }

    
        prevLast = temp; 


        temp = nextNode; 
    }
  
    return head; 
}


void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

//From me
 Node* reverseKGroup(Node* head, int k) {
        Node* current = head;
        Node* prev = NULL;
        Node* next = NULL;
        int i = 0;
        int s = k;
        Node* ans = NULL;
        while (current != NULL) {
            Node* subcurrent = current;
            Node* subprev = NULL;
            Node* subnext = NULL;
            i++;
            while (subcurrent != NULL && s > 0) {
                subnext = subcurrent->next;
                subcurrent->next = subprev;
                subprev = subcurrent;
                subcurrent = subnext;
                s--;
            }
            if (i == 1) {
                ans = subprev;
            }

            if (s > 0) {
                Node* lastcur = subprev;
                Node* lastprev = NULL;
                Node* lastnext = NULL;
                while (lastcur != NULL) {
                    lastnext = lastcur->next;
                    lastcur->next = lastprev;
                    lastprev = lastcur;
                    lastcur = lastnext;
                }
                break;
            }
            next = subcurrent;
            if (prev != NULL)
                prev->next = subprev;
            current->next = next;
            prev = current;
            current = next;
            s = k;
        }
        // cout<<prev->data;
        return ans;
    }
int main() {
   
    Node* head = new Node(5);
    head->next = new Node(4);
    head->next->next = new Node(3);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(2);


    cout << "Original Linked List: ";
    printLinkedList(head);

    head = kReverse(head, 4);

    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}