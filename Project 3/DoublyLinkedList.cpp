/*Author: Deondre De Freitas
Date of creation: 4/5/2020
Course: CSCI 235
Implementation file for a doubly linked list*/

#include "DoublyLinkedList.hpp"
#include <iostream>
#include <string>
#include <cstddef>
using namespace std;

// Instantiate a doubly linked list
template<class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(){
    headPtr = nullptr;
    itemCount = 0;
}  // End default constructor

// Create a copy of a Doubly Linked List
template<class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(const DoublyLinkedList<ItemType>& list){ // Copy constructor
   itemCount = list.itemCount;
   DoubleNode<ItemType>* firstPtr = list.getHeadPtr();  // Points to nodes in original chain
   
   if (firstPtr == nullptr){ // If the copied list is empty
      headPtr = nullptr;  

   } else { // Copy the first node
      headPtr = new DoubleNode<ItemType>();
      headPtr->setItem(firstPtr->getItem());
      
      // Then copy remaining nodes
      DoubleNode<ItemType>* newChainPtr = headPtr;
      DoubleNode<ItemType>* tailPtr = headPtr;
      firstPtr = firstPtr->getNext();
      while (firstPtr != nullptr) { 
        ItemType nextItem = firstPtr->getItem(); // Get next item from original chain
        DoubleNode<ItemType>* newNodePtr = new DoubleNode<ItemType>(nextItem); // New node with next item
        newChainPtr->setNext(newNodePtr);         
        newChainPtr = newChainPtr->getNext();
        newChainPtr->setPrev(tailPtr);
        tailPtr = tailPtr->getNext();
        firstPtr = firstPtr->getNext();
      }
      
      newChainPtr->setNext(nullptr); // End of chain
   }
}  // End copy constructor

// Clears the list of all nodes
template<class ItemType>
DoublyLinkedList<ItemType>::~DoublyLinkedList(){
   clear(); // Call the clear command as the destructor
}  // End destructor

// Insert a new node with a given item and position
template<class ItemType>
bool DoublyLinkedList<ItemType>::insert(const ItemType& item, const int& position){
    DoubleNode<ItemType>* currentPtr = headPtr;
    DoubleNode<ItemType>* beforeCurrentPtr = headPtr;
    DoubleNode<ItemType>* newNodePtr = new DoubleNode<ItemType>();
    newNodePtr->setItem(item);
    int currentPos = 2; // Track the location of the pointers
    
    if (position == 1 && headPtr == nullptr) { // If list is empty
        headPtr = newNodePtr;
        itemCount++;
    } else if (position == 1 && headPtr != nullptr) { // If not empty
        newNodePtr->setNext(currentPtr);
        currentPtr->setPrev(newNodePtr);
        currentPtr = currentPtr->getPrev();
        headPtr = currentPtr;
        itemCount++;
    } else {
        currentPtr = currentPtr->getNext();
        while (currentPos != position) {
            beforeCurrentPtr = beforeCurrentPtr->getNext();
            currentPtr = currentPtr->getNext();
            currentPos++;
        }
        if (currentPtr == nullptr) {    // If inserting at end of list
            beforeCurrentPtr->setNext(newNodePtr);
            newNodePtr->setPrev(beforeCurrentPtr);
        } else {    // Anywhere but the end of the list
            currentPtr->setPrev(newNodePtr);
            newNodePtr->setNext(currentPtr);
            beforeCurrentPtr->setNext(newNodePtr);
            newNodePtr->setPrev(beforeCurrentPtr);
        }
        itemCount++;
    }
    return true;
}  // End insert

// Remove a node from a preexisting doubly linked list
template<class ItemType>
bool DoublyLinkedList<ItemType>:: remove(const int& position) {
    if (position > itemCount || position < 1) { // If attempting to remove outside of the bounds of the list
        return false;
    }

    DoubleNode<ItemType>* currentPtr = headPtr->getNext();
    DoubleNode<ItemType>* beforeCurrentPtr = headPtr;
    int currentPos = 2;

    if (position == 1) {    // Removes the first node and sets the the second node to be the first
        currentPtr->setPrev(nullptr);
        delete headPtr;
        headPtr = currentPtr;
        itemCount--;
        return true;

    } else {
        while (currentPos != position) {   // Get to the given position
            currentPtr = currentPtr->getNext();
            beforeCurrentPtr = beforeCurrentPtr->getNext();
            currentPos++;
        }
        if (currentPtr->getNext() == nullptr) { // If removing from the end of the list
            currentPtr->setPrev(nullptr);
            beforeCurrentPtr->setNext(nullptr);
            delete currentPtr;
            itemCount--;
            return true;

        } else if (currentPtr->getNext() != nullptr) {  // If removing from somewhere in the middle of the list
            DoubleNode<ItemType>* leadingPtr = currentPtr->getNext();
            currentPtr->setNext(nullptr);
            currentPtr->setPrev(nullptr);
            leadingPtr->setPrev(beforeCurrentPtr);
            beforeCurrentPtr->setNext(leadingPtr);
            delete currentPtr;
            itemCount--;
            return true;
        }
    }
}

//@return: Size of the list
template<class ItemType>
int DoublyLinkedList<ItemType>::getSize() const {
    return itemCount;
}

//@return: Copy of the head pointer
template<class ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getHeadPtr() const {
    DoubleNode<ItemType>* copyPtr = headPtr;
    return copyPtr;
}

// Return a node from a given position in a preexisting doubly linked list
template<class ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getAtPos(const int& pos) const {
    DoubleNode<ItemType>* currentPtr = headPtr;
    int currentPos = 1;

    while (currentPos != pos) {
        currentPtr = currentPtr->getNext();
        currentPos++;
    }
    return currentPtr;
}

// Returns the current status of the list, whether empty or not
template<class ItemType>
bool DoublyLinkedList<ItemType>::isEmpty() const
{
    if (itemCount == 0) {
        return true;
    } else {
        return false;
    }
}

// Clears the list of any nodes, used in the destructor
template<class ItemType>
void DoublyLinkedList<ItemType>::clear() {
    DoubleNode<ItemType>* nodeToDeletePtr = headPtr;
    while (headPtr != nullptr) // Delete each node from the list starting from the first one
    {
        headPtr = headPtr->getNext();

        // Return node to the system
        nodeToDeletePtr->setNext(nullptr);
        nodeToDeletePtr->setPrev(nullptr);

        delete nodeToDeletePtr;

        nodeToDeletePtr = headPtr;
    }  // end while

    itemCount = 0;
}

// Displays the contents of the list 
template<class ItemType>
void DoublyLinkedList<ItemType>::display() const
{
    DoubleNode<ItemType>* currentPtr = headPtr;

    while (currentPtr != nullptr) { // Loop through and print each item in the list
        cout<<currentPtr->getItem();
        currentPtr = currentPtr->getNext();
        if (currentPtr == nullptr) {
            cout<<'\n';
        } else {
            cout<<' ';
        }
    }

}

// Displays the contents of the list backwards
template<class ItemType>
void DoublyLinkedList<ItemType>::displayBackwards() const
{
    DoubleNode<ItemType>* currentPtr = headPtr;

    while (currentPtr->getNext() != nullptr) {  // Loop until last node in list
        currentPtr = currentPtr->getNext();
    }

    while (currentPtr != nullptr) { // Print from the last node backwards
        cout<<currentPtr->getItem();
        currentPtr = currentPtr->getPrev();
        if (currentPtr == nullptr) {
            cout<<'\n';
        } else {
            cout<<' ';
        }
    }

}

template<class ItemType>
DoublyLinkedList<ItemType> DoublyLinkedList<ItemType>::interleave(const DoublyLinkedList<ItemType>& a_list){
    int minIter = min(a_list.getSize(), itemCount); // Compares the two lists and returns the smaller of the two
    DoubleNode<ItemType>* a_listCurrentPtr = a_list.getHeadPtr();
    DoubleNode<ItemType>* originalListCurrentPtr = headPtr;

    DoublyLinkedList<ItemType> tempList; //An empty temporary list is created in order to hold the combined interwoven indices of the two lists provided
    
    for (int i = 1; i <= minIter; i++) { 

        tempList.insert(originalListCurrentPtr->getItem(), i*2 - 1); // Insert at every odd index
        tempList.insert(a_listCurrentPtr->getItem(), i*2); // Insert at every even index
        originalListCurrentPtr = originalListCurrentPtr->getNext();
        a_listCurrentPtr = a_listCurrentPtr->getNext();

    }
    int continueIndex = tempList.getSize() + 1; // From where the previous index ended

    if (originalListCurrentPtr != nullptr) {
        while (originalListCurrentPtr != nullptr) {
            tempList.insert(originalListCurrentPtr->getItem(), continueIndex);
            originalListCurrentPtr = originalListCurrentPtr->getNext();
            continueIndex++;
        }        
    } else if (a_listCurrentPtr != nullptr) {
        while (a_listCurrentPtr != nullptr) {
            tempList.insert(a_listCurrentPtr->getItem(), continueIndex);
            a_listCurrentPtr = a_listCurrentPtr->getNext();
            continueIndex++;
        }        
    }
    return tempList; // Return the interleaved list
}