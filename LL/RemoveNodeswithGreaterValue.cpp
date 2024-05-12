#include<bits/stdc++.h>
using namespace std;
//Remove Nodes greater than right side
//Remove Nodes greater than right side
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

 Node* removeNodes(Node* head) {
        Node* prev = NULL;

        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        // cout<<prev->val;

        Node* ans = prev;

        prev = prev->next;
        ans->next = NULL;
        while (prev != NULL) {

            if (ans->data > prev->data) {
                prev = prev->next;
                continue;
            }

            current = ans;
            ans = prev;
            cout << ans->data;

            prev = prev->next;
            ans->next = current;
        }
        return ans;
    }