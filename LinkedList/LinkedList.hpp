
struct Node
{
   int Data;
   Node* NextNode;

    Node()
    {
        Data = 0;
        NextNode = nullptr;
    }
   Node(int value)
   {
        Data = value;
        NextNode = nullptr;
   }
};

class LinkedList
{
    Node* Head;

public:
    LinkedList()
    {
        Head = nullptr;
    }
    
    // Function to insert a 
    // node at the end of the 
    // linked list. 
    void insertNode(int); 
  
    // Function to print the 
    // linked list. 
    void printList(); 
  
    // Function to delete the 
    // node at given position 
    void deleteNode(int); 
};

