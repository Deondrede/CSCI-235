/*Author: Deondre De Freitas
Date of creation: 3/14/2020
Course: CSCI 235
Header file for a node to be used in a doubly linked list*/

#ifndef DOUBLE_NODE
#define DOUBLE_NODE

template<class ItemType>
class DoubleNode{
private:
    ItemType item;  // Data item
    DoubleNode<ItemType>* next; // Pointer to next node
    DoubleNode<ItemType>* prev; // Pointer to prev node
public:
    // Constructors
    DoubleNode();
    DoubleNode(const ItemType& anItem);
    DoubleNode(const ItemType& anItem, DoubleNode<ItemType>* nextNodePtr);
    DoubleNode(const ItemType& anItem, DoubleNode<ItemType>* nextNodePtr, DoubleNode<ItemType>* prevNodePtr);
    // Modifiers
    void setItem(const ItemType& anItem);
    void setNext(DoubleNode<ItemType>* nextNodePtr);
    void setPrev(DoubleNode<ItemType>* prevNodePtr);
    // Accessors
    ItemType getItem() const;
    DoubleNode<ItemType>* getNext() const;
    DoubleNode<ItemType>* getPrev() const;
};   // End DoubleNode
#endif