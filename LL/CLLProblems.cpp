Circluar list Problems


void splitList(Node *head, Node **head1_ref,
                           Node **head2_ref) 
{ 
    Node *slow_ptr = head; 
    Node *fast_ptr = head; 
     
    if(head == NULL) 
        return; 
     
    /* If there are odd nodes in the circular list then 
       fast_ptr->next becomes head and for even nodes 
       fast_ptr->next->next becomes head */
    while(fast_ptr->next != head && 
          fast_ptr->next->next != head) 
    { 
        fast_ptr = fast_ptr->next->next; 
        slow_ptr = slow_ptr->next; 
    } 
     
    /* If there are even elements in list
       then move fast_ptr */
    if(fast_ptr->next->next == head) 
        fast_ptr = fast_ptr->next; 
         
    /* Set the head pointer of first half */
    *head1_ref = head; 
         
    /* Set the head pointer of second half */
    if(head->next != head) 
        *head2_ref = slow_ptr->next; 
         
    /* Make second half circular */
    fast_ptr->next = slow_ptr->next; 
         
    /* Make first half circular */
    slow_ptr->next = head; 
} 


void deleteNode(struct Node **head, int key) {
    
    if ((*head)->data == key) {
        struct Node *temp=*head;
        struct Node *cur = *head;
        while(cur->next!=*head)
        {
            cur=cur->next;
        }
        cur->next=(*head)->next;
        (*head)=(*head)->next;
        
        delete temp;
    }
    else 
    {
        struct Node *cur = *head;
        struct Node *prev = NULL;
        while (cur->next != *head) 
        {
            if (cur->data == key) 
            {
                prev->next = cur->next;
                delete cur;
                return;
            }
            prev = cur;
            cur = cur->next;
        }
        if (cur->data == key) 
        {
            prev->next = cur->next;
            delete cur;
            return;
        }
    }
}

void reverse(struct Node **head_ref) {
    struct Node *cur = *head_ref;
    struct Node *prev = NULL;
    struct Node *forw = NULL;
    do {
        forw = cur->next;
        cur->next = prev;
        prev = cur;
        cur = forw;
    } while (cur != *head_ref);
    (*head_ref)->next = prev;
    *head_ref = prev;
}

.