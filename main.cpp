// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "binarySearchTree.h"

using namespace std;

int main() {

  bSearchTreeType<int>  treeRoot, otherTreeRoot;

  for (auto number : {1,2,3,4,5,6,7,8,9})
    treeRoot.insert(number);

  cout << "Tree nodes in preorder: " << endl;;
  treeRoot.preorderTraversal();
  cout << endl;
  cout << "Tree nodes in inorder: "   << endl;
  treeRoot.inorderTraversal();
  cout << endl;
  cout << "Tree nodes in postorder: " << endl;
  treeRoot.postorderTraversal();
  cout << endl;

  cout << "Tree Height:      " << treeRoot.treeHeight()      << endl;
  cout << "Number of Nodes:  " << treeRoot.treeNodeCount()   << endl;
  cout << "Number or Leaves: " << treeRoot.treeLeavesCount() << endl;
  cout << endl;

  (treeRoot.search(11)) ? cout << "Item found in the tree." : cout << "Search item not in the tree.";
  cout << endl;
  (treeRoot.search( 5)) ? cout << "Item found in the tree." : cout << "Search item not in the tree.";
  cout << endl;

  
  treeRoot.deleteNode(5);

  cout << "After the delete operation: " << endl;
  cout << "Tree nodes in preorder: " << endl;
  treeRoot.preorderTraversal();
  cout<< endl;
  cout << "Tree nodes in inorder:  "  << endl;
  treeRoot.inorderTraversal();
  cout<<endl;
  cout << "Tree nodes in postorder: " << endl;
  treeRoot.postorderTraversal();
  cout << endl;

  otherTreeRoot = treeRoot;

  cout << "Tree nodes in inorder: " << endl;
  treeRoot.inorderTraversal();

  cout << "Other Tree nodes in inorder: " << endl;
  otherTreeRoot.inorderTraversal();
  cout << endl;

  otherTreeRoot.destroyTree();

  cout << endl << "Other Tree nodes in inorder: ";
  otherTreeRoot.inorderTraversal();
  cout << endl;

  return 0;

}
