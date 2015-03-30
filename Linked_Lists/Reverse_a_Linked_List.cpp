/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

void PrintMe(Node* head);
void PrintMe(Node* head)
{
	while(head != NULL)
	{
		cout<<head->data;
		head=head->next;
	}
}

Node* Reverse(Node *head)
{
  // Complete this method
    Node* prev_node = NULL;
    Node* curr_node = head;
    Node* next_node = head->next;
    
    /*cout << "BEFORE:";
    PrintMe(head);
    cout << endl; */
    
    while (curr_node)
    {
        next_node = curr_node->next;
        curr_node->next = prev_node;
        
        /*cout << "prev:";
        if (prev_node)
            cout << prev_node->data;
        else
            cout << "NULL";
        cout << " curr:" << curr_node->data << " next:";
        if (next_node)
            cout << next_node->data;
        else 
            cout << "NULL";
        cout << endl;*/
        
        if (next_node)
        {
            Node* temp = curr_node;
            curr_node = next_node;
            prev_node = temp;
        }
        else
        {
            break;    
        }
    }
    
    /*cout << "AFTER:";
    PrintMe(curr_node);
    cout << endl; */
    
    return curr_node;
}
