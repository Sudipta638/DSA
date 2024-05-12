//Odd-Even Separation
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

 Node* oddEvenList(Node* head) {
        if (head ==NULL||head->next == NULL ||head->next->next == NULL)
            return head;
        Node* odd = head;
        Node* hn = head->next;
        Node* even = head->next;
        Node* temp = head;
        temp = temp->next->next;
        int i = 1;
        while (temp->next != NULL) {
            Node* cur = temp->next;
            if (i % 2 != 0) {
                odd->next = temp;
                temp->next = hn;
                odd = odd->next;
            } else {
                even->next = temp;
                even = temp;
            }
            temp = cur;
            i++;
        }
       // cout<<temp->data;
        
         if (i % 2 != 0) {
            Node* New = new Node(temp->data ,hn);
                odd->next = New;
                even->next= NULL;
            } else {
                even->next = temp;
            }
        return head;
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
    head = oddEvenList(head);
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
    return 0;

}