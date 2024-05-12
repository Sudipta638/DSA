//Found triplets in DLL
#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int data;
	Node *next;
	Node *prev;
	Node(int x)
	{
		data = x;
		next = nullptr;
		prev = nullptr;
	}
};

class Solution
{
public:
	vector<vector<int>> trippleSumInLinkedList(Node *head, int sumv)
	{
		vector<vector<int>> res;
		Node *s, *m, *e;
		s = head;
		m = head;
		e = head;
		while (e->next != nullptr)
			e = e->next;
		while (s->next->next != nullptr)
		{
			int currSum = sumv - s->data;
			m = s->next;
			Node *ev = e;
			while (m != nullptr && ev != nullptr && m != ev)
			{
				int newSum = m->data + ev->data;
				if (newSum == currSum)
				{
					res.push_back({s->data, m->data, ev->data});
					m = m->next;
				}
				else if (newSum > currSum)
					ev = ev->prev;
				else
					m = m->next;
			}
			s = s->next;
		}
		return res;
	}
};

int main()
{
	Node *head = new Node(1);
	Node *node2 = new Node(2);
	Node *node3 = new Node(4);
	Node *node4 = new Node(5);
	Node *node5 = new Node(6);
	Node *node6 = new Node(8);
	Node *node7 = new Node(9);

	head->next = node2;
	node2->prev = head;
	node2->next = node3;

	node3->prev = node2;
	node3->next = node4;

	node4->next = node5;
	node4->prev = node3;

	node5->prev = node4;
	node5->next = node6;

	node6->prev = node5;
	node6->next = node7;

	node7->prev = node6;

	Solution sol;
	vector<vector<int>> res = sol.trippleSumInLinkedList(head, 15);

	for (int i = 0; i < res.size(); i++)
		cout << res[i][0] << ", " << res[i][1] << ", " << res[i][2] << endl;
	return 0;
}
