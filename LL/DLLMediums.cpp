// DLL Problems
void deleteAllOccurOfX(struct Node **head_ref, int x)
{
    if (*head_ref == NULL)
        return;
    Node *head = *head_ref;
    while (head != NULL && head->data == x)
        head = head->next;
    if (head != NULL)
        head->prev = NULL;
    *head_ref = head;
    Node *prev = head;
    while (head != NULL)
    {
        while (head->next != NULL && head->next->data == x)
        {
            head->next = head->next->next;
            if (head->next != NULL)
                head->next->prev = prev;
        }
        prev = head;
        head = head->next;
    }
}
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    {
        Node *font = head;
        Node *back = head;
        while (back->next != NULL && back->data < target)
        {
            back = back->next;
        }

        vector<pair<int, int>> ans;
        while (back->data > font->data)
        {
            if (back->data + font->data == target)
            {
                ans.push_back({font->data, back->data});
                font = font->next;
                back = back->prev;
            }
            while (back->data > font->data && back->data + font->data < target)
            {
                font = font->next;
            }
            while (back->data > font->data && back->data + font->data > target)
            {
                back = back->prev;
            }
        }
        return ans;
        // code here
    }
    // code here
}

 Node * removeDuplicates(struct Node *head)
    {
       Node* curr{ head };
    while ( curr->next )
        if ( curr->data == curr->next->data ) {
            Node* temp{ curr->next }; 
            if ( curr->next = temp->next )
                curr->next->prev = curr;
            delete temp; 
        } else curr = curr->next;
    return head;
        // Your code here
    }