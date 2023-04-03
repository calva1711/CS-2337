// Template class Stack based on a singly linked list
template <class Type>
class StackListClass {
private:

  // The structure describing the node
  template <class Type>
  struct NodeStackStruct {
    Type data;
    NodeStackStruct<Type>* nextNodePtr;
  };

  NodeStackStruct<Type>* stackTopNodePtr = nullptr;        // stack top pointer
   unsigned               stackNodeCount = 0;               // stack node count

   /*
Name: AllocateNodeSafeMemory(void)
Function Purpose : add item to the queue
Function Design:   allocates new memory for in a dynamic memory
                   if not sucessful memory allocation, states the reason and exits
Inputs:            void
Outputs:           NodeStackStruct<Type>*
*/
  NodeStackStruct<Type>* allocateNodeSafeMemory(void) {
    NodeStackStruct<Type>* newMemoryPtr;
      return newMemoryPtr;  //dummy return
  }

  /*
Name: CopyToStackFrom
Function Purpose : Copy to a newly formed queue 
Function Design:   allocates new memory for a new array to contain a copy of the queue
                   if not sucessful memroy allocation entry, states the reason and exits
Inputs:            const StackListClass& srcStackListRef  -source stack
Outputs:           void
                   const StackListClass& srcStackListRef  - target stack
*/
  void copyToStackFrom(const StackListClass& srcStackListRef) {
  //$$
  }

public:
  // default constructor
  StackListClass() { stackTopNodePtr = nullptr; }

  // copy constructor
  StackListClass(const StackListClass& stackListRef) {
    //$
  }

/*
Name: Push
Function Purpose : add passed item to the stack top
Function Design:   allocates new memory for new stack top
                   use AllocateNodeSafeMemory()
                   adjust stack node count
Inputs:            Type data- the item to put on the stack top 
Outputs:           void
*/
  void Push(Type data) {
  //$$
  }

/*
Name: Pop()
Function Purpose : take item out of stack top
Function Design:   deallocates old sstack top
Inputs:            none
Outputs:           TYPE - the removed item from the top of the stack
*/
  Type Pop() {
  //$$
      return 0;

  }

  // Get number nodes in the stack
  unsigned getstackNodeCount() {
    return stackNodeCount;
  }

/*
Name: Clear
Function Purpose : Clears the stack  - removes all elements from the stack
Function Design:   if the stack is not empty, it deallocates the stack
Inputs:            called by the object that invokes it
Outputs:           void
                   clears the stack that invokes it
*/
  void Clear() {
//$$
  }

  // = operator
  StackListClass<Type>& operator=(const StackListClass<Type>& stackListRef) {
    // is target stack not empty, then clear it
    //$$
    return *this;
  }

  // Display the stack
  void Display(const char* objName) {
    cout << "Object: " << objName << endl;

    if (stackTopNodePtr != nullptr) {
      NodeStackStruct<Type>* transverseStackPtr;
      cout << "top:" << endl;
      transverseStackPtr = stackTopNodePtr;

      while (transverseStackPtr != nullptr) {
        cout << transverseStackPtr->data << endl;
        transverseStackPtr = transverseStackPtr->nextNodePtr;
      }
    }//if
    else
      cout << "stack is empty." << endl;

    cout << "stack node count : " << getstackNodeCount() << endl;
    cout << endl << endl;
  }

  // destructor
  ~StackListClass() { Clear(); }

};
