//Header File Binary Search Tree

#ifndef H_binarySearchTree
#define H_binarySearchTree

#include <iostream> 
#include "binaryTree.h"

using namespace std;

template <class elemType>
class bSearchTreeType: public binaryTreeType<elemType> {

public:
  // Determine if searchItem is in the BST
  // Returns true if searchItem is found; with refernce to where found
  // otherwise, returns false.

    bool search(const elemType& searchItem) const;

  // Insert insertItem in the BST
  // If there is no node in the BST that has the same info as insertItem,
  // a node with the info insertItem is created and inserted in BST.

    void insert(const elemType& insertItem);

  // Delete deleteItem from the BST
  // Searches for a node with the same info as pqrqmetr deleteItem
  // If found, it is deleted uses deleteFromTree to delete node and adjust tree
  // If the binary tree is empty or deleteItem is not found, appropriate message is displayed

    void deleteNode(const elemType& deleteItem);

private:
  // Performs the 4 case analysis to delete the node and adjust the BST correctly

    void deleteFromTree(nodeType<elemType>* &p);

};//class bSearchTreeType



template <class elemType>
bool bSearchTreeType<elemType>::
search(const elemType& searchItem) const {

    nodeType<elemType> *current;
    bool found = false;

    if     (binaryTreeType<elemType>::root == nullptr)
        cout << "Cannot search an empty tree." << endl;
    else { //not empty
        current = binaryTreeType<elemType>::root;
        while (current != nullptr && !found) {
            if (current->info == searchItem) {
                found = true;
            } else if (current->info > searchItem) {
                current = current->lLink;
            } else {
                current = current->rLink;
            }
        }
    }//end else

    return found;

}//bool bSearchTreeType

template <class elemType>
void bSearchTreeType<elemType>
::insert(const elemType& insertItem) {
    nodeType<elemType> *current;                    //pointer to traverse the tree
    nodeType<elemType> *trailCurrent = nullptr;     //pointer trailing behind current
    nodeType<elemType> *newNode;                    //pointer to create the node

    newNode        = new nodeType<elemType>;
    newNode->info  = insertItem;
    newNode->lLink = nullptr;
    newNode->rLink = nullptr;

  // tree empty?
    if        (binaryTreeType<elemType>::root == nullptr)
        binaryTreeType<elemType>::root = newNode;
    else { // (root != nullptr)
        current = binaryTreeType<elemType>::root;
        while (current != nullptr) {
            trailCurrent = current;
            if (current->info == insertItem) {
                cout << "The item to be inserted is already in the tree." << endl;
                return;
            } else if (current->info > insertItem) {
                current = current->lLink;
            } else {
                current = current->rLink;
            }
        }
        if (trailCurrent->info > insertItem) {
            trailCurrent->lLink = newNode;
        } else {
            trailCurrent->rLink = newNode;
        }
    }

}//end insert

template <class elemType>
void bSearchTreeType<elemType>
::deleteNode (const elemType& deleteItem) {
    nodeType<elemType> *current;          //pointer to traverse the tree
    nodeType<elemType> *trailCurrent;     //pointer trailing behind current
    bool                found = false;

    if (binaryTreeType<elemType>::root == nullptr)
        cout << "Cannot delete from an empty tree." << endl;
    else {
        current = binaryTreeType<elemType>::root;
        trailCurrent = binaryTreeType<elemType>::root;
        while (current != nullptr && !found) {
            if (current->info == deleteItem) {
                found = true;
            } else {
                trailCurrent = current;
                if (current->info > deleteItem) {
                    current = current->lLink;
                } else {
                    current = current->rLink;
                }
            }
        }
        if (current == nullptr) {
            cout << "The item to be deleted is not in the tree." << endl;
        } else if (found) {
            if (current == binaryTreeType<elemType>::root) {
                deleteFromTree(binaryTreeType<elemType>::root);
            } else if (trailCurrent->info > deleteItem) {
                deleteFromTree(trailCurrent->lLink);
            } else {
                deleteFromTree(trailCurrent->rLink);
            }
        } else {
            cout << "The item to be deleted is not in the tree." << endl;
        }
    }

} //end deleteNode

template <class elemType>
void bSearchTreeType<elemType>::
deleteFromTree(nodeType<elemType>* &p) {

    nodeType<elemType> *current;       //pointer to traverse the tree
    nodeType<elemType> *trailCurrent;  //pointer behind current
    nodeType<elemType> *temp;          //pointer to the node to delete

    if (p == nullptr) {
        cout << "Error: The node to be deleted does not exist." << endl;
    } else if (p->lLink == nullptr && p->rLink == nullptr) {
        temp = p;
        p = nullptr;
        delete temp;
    } else if (p->lLink == nullptr) {
        temp = p;
        p = temp->rLink;
        delete temp;
    } else if (p->rLink == nullptr) {
        temp = p;
        p = temp->lLink;
        delete temp;
    } else {
        current = p->lLink;
        trailCurrent = nullptr;
        while (current->rLink != nullptr) {
            trailCurrent = current;
            current = current->rLink;
        }
        p->info = current->info;
        if (trailCurrent == nullptr) {
            p->lLink = current->lLink;
        } else {
            trailCurrent->rLink = current->lLink;
            delete current;
        }
    }

} //deleteFromTree

#endif
