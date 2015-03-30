/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* RemoveDuplicates(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
    Node* curr = head;
    int prev = -1;
    while (curr->next != NULL)
    {
        Node* n = curr->next;
        if (curr->data == n->data)
        {
            curr->next = n->next;    
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}
