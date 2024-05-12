 //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
         Node* node0 = new Node(-1);
         Node* node1 = new Node(-1);
         Node* node2 = new Node(-1);
         Node*zero = node0;
         Node*one = node1;
         Node*two  = node2;
         Node* temp = head;
         while(temp!=NULL){
             Node*next = temp->next;
             temp->next= NULL;
             if(temp->data ==0){
                 zero->next = temp;
                 zero = zero->next;
             }
             else if(temp->data == 1){
                 one->next = temp;
                 one = one->next;
             }
             else{
                 two->next = temp;
                 two = two->next;
             }
             temp =next;
         }
         one->next = node2->next;
         zero->next = node1->next;
         return node0->next;
        // Add code here
        
    }