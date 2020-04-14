/*Author: Deondre De Freitas
Date of creation: 3/29/2020
Course: CSCI 235
Header file for a doubly linked list*/

#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST
#include "DoubleNode.cpp"

template <class ItemType>
class  DoublyLinkedList {
    private:
        DoubleNode<ItemType>* headPtr;  // Pointer to the first node
        int itemCount;  // Number of items in the list
    
    public:
        DoublyLinkedList(); // Constructor
        DoublyLinkedList(const DoublyLinkedList<ItemType>& list);   // Copy Constructor
        virtual ~DoublyLinkedList();    // Destructor
        bool insert(const ItemType& item, const int& position); // Add an item to a specific position in the list 
        bool remove(const int& position);   // Removes the node at the given position
        int getSize() const;    // Returns the number of nodes in the list
        DoubleNode<ItemType> *getHeadPtr() const;   // Return a copy of the head pointer
        DoubleNode<ItemType> *getAtPos(const int& pos) const;   // Return a pointer to the node at the located position
        bool isEmpty() const;   // Returns whether the list is empty or not
        void clear(); // Clears the list
        void display() const; // Prints the contents of the list in order
        void displayBackwards() const; // Prints the contents of the list backwards
        DoublyLinkedList<ItemType> interleave(const DoublyLinkedList<ItemType>& a_list); // Alters the calling list to be the interleaved list of the original and parameter lists
};
#include "DoublyLinkedList.cpp"
#endif
