
/*===============================================================================

FILE:              StackLinked.cpp

DESCRIPTION:        implementation of the Stack ADT using Linked list methods

COMPILER:          g++ 5.4 running the Linux Make System

NOTES:             Put other information here ...

MODIFICATION HISTORY:

Author                  Date               Version
================================================================================
Dr. Kostas Alexis  Retrieved 2018-09-22    Version 1.0
Shawn Ray               2018-09-22         Version 1.0 started Assignment
Shawn Ray               2018-09-23         Version 1.1 added defintions for the functions
================================================================================*/

#include "../headers/StackLinked.h"

/*=============================================================================
FUNCTION:          StackLinked(int maxNumber)
DESCRIPTION:       Overloaded Constructor for StackLinked, initialized with default
					Constructor from the parent class Stack{};
PRECONDITION:	   None
POSTCONDITION:     A location in memory to store a Class Object
===============================================================================*/

template<typename DataType>
StackLinked<DataType>::StackLinked() : top(NULL){}

/*=============================================================================
FUNCTION:          StackLinked(const StackLinked& other)
DESCRIPTION:       Copy Constructor for StackLinked, initialized with the overloaded
                    Constructor
PRECONDITION:	   None
POSTCONDITION:     A location in memory to store a Class Object
===============================================================================*/

template<typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other){

	(*this) = other;
}

/*=============================================================================
FUNCTION:          StackNode(const DataType& nodeData, StackNode* nextPtr)
DESCRIPTION:       Constructor for the StackNode Class which is nested inside 
                    of the StackLinked Class
PRECONDITION:	   None
POSTCONDITION:     A location in memory to store a Class Object
===============================================================================*/

template<typename DataType>
StackLinked<DataType>::StackNode::StackNode(const DataType& nodeData, StackNode* nextPtr){

	
	this->next = nextPtr;

	this->dataItem = (DataType) nodeData;

}


/*=============================================================================
FUNCTION:          operator=
DESCRIPTION:       Overloaded Assignment Operator for the StackLinked Class,
                    assigs one object to another.
PRECONDITION:	   two objects exist and assigned like obj1 = obj2, making
                    obj1 equal to obj2
POSTCONDITION:     A location for obj2 to be stored
===============================================================================*/

template<typename DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked& other){
 
   this->top = (other).top;
  
	return (*this);
}

/*=============================================================================
FUNCTION:          ~StackLinked()
DESCRIPTION:       Destructor for the Class StackLinked, clears memory
PRECONDITION:	   An objects Scope must end.
POSTCONDITION:     None
===============================================================================*/

template<typename DataType>
StackLinked<DataType>::~StackLinked(){
	this->clear();

}


/*=============================================================================
FUNCTION:          push(const DataType& newDataItem)
DESCRIPTION:       Pushes a new item onto the stack
PRECONDITION:      A stack must exist in order to push
POSTCONDITION:     A non full stack must be present, if not an error will be sent
===============================================================================*/

template<typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem){ // throw (logic_error)

	if(this->isFull()) throw logic_error("\n\tThis Stack is full! Can\'t push any more!\n");

	StackNode *tempNode = new StackNode(newDataItem, this->top);

	this->top = tempNode;

	tempNode = NULL;

	//temp->dataItem = (DataType) newDataItem;

}


/*=============================================================================
FUNCTION:          pop()
DESCRIPTION:       Pop the top value from the stack.
PRECONDITION:	   A non empty stack or error will send.
POSTCONDITION:     A location to store the popped value
===============================================================================*/

template<typename DataType>    
DataType StackLinked<DataType>::pop(){ // throw (logic_error)

	if(!this->isEmpty()){

		DataType tempValue = this->top->dataItem; 
		this->top->dataItem = (DataType) 0;

		StackNode * deleteNode = new StackNode(0 ,this->top);

		this->top = this->top->next;

		deleteNode->next = NULL;
		delete deleteNode;

		return tempValue;

	}else throw logic_error("\n\tThis Stack is Empty! Can\'t pop an empty stack!\n");
	

}

/*=============================================================================
FUNCTION:          clear()
DESCRIPTION:       Clears the stack of all elements
PRECONDITION:      A object that calls it
POSTCONDITION:     None
===============================================================================*/

template<typename DataType>
void StackLinked<DataType>::clear(){

	for (StackNode* temp = this->top; temp != 0; temp = temp->next) {
	    temp->dataItem = (DataType) 0; 
	    this->top = NULL;
	}

}

/*=============================================================================
FUNCTION:          isEmpty()
DESCRIPTION:       Checks if the Stack is empty
PRECONDITION:      None
POSTCONDITION:     Boolean location to store flag
===============================================================================*/

template<typename DataType>
bool StackLinked<DataType>::isEmpty() const{

	if(this->top == NULL){
		return true;

	}else return false;
}

/*=============================================================================
FUNCTION:          isFull()
DESCRIPTION:       Checks if the Stack is full
PRECONDITION:      None
POSTCONDITION:     Boolean location to store flag
===============================================================================*/

template<typename DataType>
bool StackLinked<DataType>::isFull() const{

	return false;
}

/*=============================================================================
FUNCTION:          showStructure() const 
DESCRIPTION:       Displays the contents of a Structured Stack
PRECONDITION:      None
POSTCONDITION:     None
CREDIT:			   Dr. Kostas Alexis  Retrieved 2018-09-22    
===============================================================================*/

template <typename DataType>
void StackLinked<DataType>::showStructure() const 

// Linked list implementation. Outputs the data elements in a stack.
// If the stack is empty, outputs "Empty stack". This operation is
// intended for testing and debugging purposes only.

{
    if( isEmpty() )
    {
	cout << "Empty stack" << endl;
    }
    else
    {
        cout << "Top\t";
	for (StackNode* temp = top; temp != 0; temp = temp->next) {
	    if( temp == top ) {
		cout << '[' << temp->dataItem << "]\t";
	    }
	    else {
		cout << temp->dataItem << "\t";
	    }
	}
        cout << "Bottom" << endl;
    }

}

