// C++ implementation to reverse a doubly linked list
// in groups of given size without recursion
// Iterative Method

#include <iostream>
using namespace std;

// Represents a node of doubly linked list
struct Node {
	int data;
	Node *next, *prev;
};

// function to get a new node
Node* getNode(int data)
{
	// allocating node
	Node* new_node = new Node();
	new_node->data = data;
	new_node->next = new_node->prev = NULL;

	return new_node;
}

// function to insert a node at the beginning
// of the Doubly Linked List
Node* push(Node* head, Node* new_node)
{
	// since we are adding at the beginning,
	// prev is always NULL
	new_node->prev = NULL;

	// link the old list of the new node
	new_node->next = head;
	// change prev of head node to new node
	if (head != NULL)
		head->prev = new_node;

	// move the head to point to the new node
	head = new_node;
	return head;
}

// function to reverse a doubly linked list
// in groups of given size
Node* revListInGroupOfGivenSize(Node* head, int k)
{
	if (!head)
		return head;

	Node* st = head;
	Node* globprev = NULL;
	Node* ans = NULL;
	while (st) {
		int count = 1; // to count k nodes
		Node* curr = st;
		Node* prev = NULL;
		Node* next = NULL;
		while (curr && count <= k) { // reversing k nodes
			next = curr->next;
			curr->prev = next;
			curr->next = prev;
			prev = curr;
			curr = next;
			count++;
		}

		if (!ans) {
			ans = prev; // to store ans i.e the new head
			ans->prev = NULL;
		}

		if (!globprev)
			globprev = st; // assigning the last node of the
						// reversed k nodes
		else {
			globprev->next = prev;
			prev->prev
				= globprev; // connecting last node of last
							// k group to the first node of
							// present k group
			globprev = st;
		}

		st = curr; // advancing the pointer for the next k
				// group
	}
	return ans;
}

// Function to print nodes in a
// given doubly linked list
void printList(Node* head)
{
	while (head) {
		cout << head->data << " ";
		head = head->next;
	}
}

// Driver code
int main()
{
	// Start with the empty list
	Node* head = NULL;

	// Create doubly linked: 10<->8<->4<->2
	head = push(head, getNode(2));
	head = push(head, getNode(4));
	head = push(head, getNode(8));
	head = push(head, getNode(10));

	int k = 2;

	cout << "Original list: ";
	printList(head);

	// Reverse doubly linked list in groups of
	// size 'k'
	head = revListInGroupOfGivenSize(head, k);

	cout << "\nModified list: ";
	printList(head);
	return 0;
}

// This code is contributed by Tapesh (tapeshdua420)
