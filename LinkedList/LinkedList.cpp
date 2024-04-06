#include "LinkedList.hpp"
#include <iostream>

using namespace std;

void LinkedList::insertNode(int value)
{
    Node* pNewNode = new Node(value);
    if(Head == nullptr)
    {
        Head = pNewNode;
        return;
    }

    Node* temp = Head;
    while(temp ->NextNode != nullptr)
    {
        temp = temp ->NextNode;
    }

    temp->NextNode = pNewNode;

}

void LinkedList::printList()
{
    Node*  temp = Head;

    if(Head == nullptr)
    {
        cout << "list is empty "<< endl;
    }

    while(temp != nullptr)
    {
        cout << temp->Data << " ";
        temp = temp->NextNode;
    }
}

void LinkedList::deleteNode(int offset)
{
    Node* temp = Head;
    Node* PreNode = nullptr;
    Node* AfterNode = nullptr;

    if(Head == nullptr)
    {
        return;
    }

    // delete the Head node
    if(offset == 0)
    {
        Head = Head->NextNode;
        delete temp;
        return;
    }

    PreNode = temp;
// find node previous to the deleted node
    for(int i =0; PreNode != nullptr && i < offset-1;i++)
    {
        PreNode = PreNode->NextNode;
    }
    // node to be deleted
    temp = PreNode->NextNode;
    AfterNode = PreNode->NextNode->NextNode;

    PreNode->NextNode = AfterNode;
    delete temp;
}


// Driver Code 
int main() 
{ 
    LinkedList list; 
  
    // Inserting nodes 
    list.insertNode(1); 
    list.insertNode(2); 
    list.insertNode(3); 
    list.insertNode(4); 
  
    cout << "Elements of the list are: "; 
  
    // Print the list 
    list.printList(); 
    cout << endl; 

        // Delete node at position 2. 
    list.deleteNode(3); 
  
    cout << "Elements of the list are: "; 
    list.printList(); 
    cout << endl; 

    return 0; 
}