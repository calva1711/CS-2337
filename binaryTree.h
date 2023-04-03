//Header File Binary Search Tree
#ifndef H_binaryTree
#define H_binaryTree

#include <iostream>

using namespace std;

//Definition of the Node

template <class elemType>
struct nodeType {
    elemType             info;
    nodeType<elemType> *lLink;
    nodeType<elemType> *rLink;
};

//Definition of the class

template <class elemType>
class binaryTreeType {

public:

  //Overload the assignment operator

    const binaryTreeType<elemType>& operator=(const binaryTreeType<elemType>&);

  // Determine whether the binary tree is empty.

    bool isEmpty() const;

  // Do traversals of the binary tree.
  // Nodes are printed in transversal order sequence.

    void   inorderTraversal() const;
    void  preorderTraversal() const;
    void postorderTraversal() const;

  // Determines returns the height of a binary tree

    int treeHeight() const;

  // Determines returns the number of nodes in a binary tree

    int treeNodeCount() const;

  // Determines returns the number of leaves in a binary tree

    int treeLeavesCount() const;

  // Destroys the binary tree, memory space occupied by each node is deallocated.
  // root is set to nullptr

    void destroyTree();

  // Determines returns boolean to indicate if searchItem is in the binary tree
  //Postcondition: Returns true if searchItem is found in 

    virtual bool search(const elemType& searchItem) const = 0;

  // Inserts insertItem in the binary tree.
  // Checks to make sure there is not any that has the same info as insertItem
  // If not, a node with the info insertItem is created and inserted in the binary search tree.

    virtual void insert(const elemType& insertItem) = 0;

  // Deletes deleteItem from the binary tree
  // If a node with the same info as deleteItem is found, it is deleted from the binary tree.
  // If the binary tree is empty or deleteItem is not in the binary tree,
  // an appropriate message is displayed.

    virtual void deleteNode(const elemType& deleteItem) = 0;

  //Copy constructor

    binaryTreeType(const binaryTreeType<elemType>& otherTree);

  //Default constructor

    binaryTreeType();

  //Destructor
    virtual ~binaryTreeType();

protected:
    nodeType<elemType>  *root;

private:

  // Makes a copy of the binary tree to which otherTreeRoot points. 
  // The pointer copiedTreeRoot points to the root of the copied binary tree.

    void copyTree(nodeType<elemType>* &copiedTreeRoot, nodeType<elemType>* otherTreeRoot);

  // Destroys the binary tree to which p points. 
  // Memory space occupied by each node, in the binary tree to which p points, is deallocated.
  // p is set to  nullptr;

    void destroy(nodeType<elemType>* &p);

  // Transaversals starting at p
  // Nodes of the binary tree, to which points, are displayed in transversal order sequence

    void inorder(nodeType<elemType> *p) const;
    void preorder(nodeType<elemType> *p) const;
    void postorder(nodeType<elemType> *p) const;

  // Determines returns the height of the binary tree to which p points.
    int height(nodeType<elemType> *p) const;

  // Determine returns the larger of x and y

    int max(int x, int y) const;

  // Determines returns the number of nodes in the binary tree to which p points. 

    unsigned nodeCount(nodeType<elemType> *p) const;

  // Determines retruns the number of leaves in  the binary tree to which p points 

    unsigned leavesCount(nodeType<elemType> *p) const;

};//class binaryTreeType

	//Definition of member functions

template <class elemType>
binaryTreeType<elemType>::binaryTreeType() {
    root = nullptr;
}

template <class elemType>
bool binaryTreeType<elemType>::isEmpty() const {
    return (root == nullptr);
}

template <class elemType>
void binaryTreeType<elemType>::inorderTraversal() const  {
    inorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::preorderTraversal() const {
    preorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::postorderTraversal() const {
    postorder(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeHeight() const {
    return height(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeNodeCount() const {
    return nodeCount(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeLeavesCount() const {
    return leavesCount(root);
}

template <class elemType>
void  binaryTreeType<elemType>::
copyTree(nodeType<elemType>* &copiedTreeRoot, nodeType<elemType>* otherTreeRoot) {
    if (otherTreeRoot == nullptr)
        copiedTreeRoot = nullptr;
    else {
        copiedTreeRoot = new nodeType<elemType>;
        copiedTreeRoot->info = otherTreeRoot->info;
        copyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);
        copyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
    }
} //end copyTree

template <class elemType>
void binaryTreeType<elemType>::
inorder(nodeType<elemType> *p) const {
    if (p != nullptr) {
        inorder(p->lLink);
        cout << p->info << " ";
        inorder(p->rLink);
    }
}

template <class elemType>
void binaryTreeType<elemType>::
preorder(nodeType<elemType> *p) const {
    if (p != nullptr) {
        cout << p->info << " ";
        preorder(p->lLink);
        preorder(p->rLink);
    }
}

template <class elemType>
void binaryTreeType<elemType>::
postorder(nodeType<elemType> *p) const {
    if (p != nullptr) {
        postorder(p->lLink);
        postorder(p->rLink);
        cout << p->info << " ";
    }
}

//Overload the assignment operator

template <class elemType>
const binaryTreeType<elemType>& binaryTreeType<elemType>::
operator=(const binaryTreeType<elemType>& otherTree) { 

    if (this != &otherTree) {                   //avoid self-copy
        if (root != nullptr) {
            destroy(root);
        }
        if (otherTree.root == nullptr) {
            root = nullptr;
        }
    } else {
        copyTree(root, otherTree.root);
    }

    return *this;

}

template <class elemType>
void  binaryTreeType<elemType>::
destroy(nodeType<elemType>* &p) {
    if (p != nullptr) {
        destroy(p->lLink);
        destroy(p->rLink);
        delete p;
        p = nullptr;
    }
}

template <class elemType>
void  binaryTreeType<elemType>::
destroyTree() {
    destroy(root);
}

//copy constructor
template <class elemType>
binaryTreeType<elemType>::
binaryTreeType(const binaryTreeType<elemType>& otherTree) {
    if (otherTree.root == nullptr) //otherTree is empty
        root = nullptr;
    else {
        copyTree(root, otherTree.root);
    }
}

//Destructor
template <class elemType>
binaryTreeType<elemType>::
~binaryTreeType() {
    destroy(root);
}

template<class elemType>
int binaryTreeType<elemType>::
height(nodeType<elemType> *p) const {
    if (p == nullptr) {
        return 0;
    } else {
        return 1 + max(height(p->lLink), height(p->rLink));
    }
}

template <class elemType>
int binaryTreeType<elemType>::
max(int x, int y) const {
    if (x >= y) {
        return x;
    } else {
        return y;
    }
}

template <class elemType>
unsigned binaryTreeType<elemType>::
nodeCount(nodeType<elemType> *p) const {
    if (p == nullptr) {
        return 0;
    } else {
        return 1 + nodeCount(p->lLink) + nodeCount(p->rLink);
    }
}

template <class elemType>
unsigned binaryTreeType<elemType>::
leavesCount(nodeType<elemType> *p) const  {
    if (p == nullptr) {
        return 0;
    } else if (p->lLink == nullptr && p-> rLink == nullptr) {
        return 1;
    } else {
        return leavesCount(p->lLink) + leavesCount(p->rLink);
    }
}

#endif
