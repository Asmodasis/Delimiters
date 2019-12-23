
/*===============================================================================

FILE:              StackArray.cpp

DESCRIPTION:        implementation of the Stack ADT using array methods

COMPILER:          g++ 5.4 running the Linux Make System

NOTES:             Put other information here ...

MODIFICATION HISTORY:

Author                  Date               Version
================================================================================
Dr. Kostas Alexis  Retrieved 2018-09-22    Version 1.0
Shawn Ray               2018-09-22         Version 1.0 started Assignment
Shawn Ray               2018-09-23         Version 1.1 added defintions for the functions
Shawn Ray               2018-09-30         Version 1.2 bug fixes 
================================================================================*/

#include "../headers/StackArray.h"
 
/*=============================================================================
FUNCTION:          StackArray(int maxNumber)
DESCRIPTION:       Overloaded Constructor for StackArray, initialized with default
					Constructor from the parent class Stack{};
PRECONDITION:	   None
POSTCONDITION:     A location in memory to store a Class Object
===============================================================================*/

template <typename DataType>
StackArray<DataType>::StackArray(int maxNumber) : Stack<DataType>::Stack(){
	


	this->maxSize = maxNumber;
	this->top = -1;

	this->dataItems = new DataType[this->maxSize];

	for(int i = 0; i < this->maxSize; ++i){
		this->dataItems[i] = 0;				// assign every element in the array a value of zero
	}

}
 
/*=============================================================================
FUNCTION:          StackArray(const StackArray& other)
DESCRIPTION:       Copy Constructor for StackArray, initialized with the overloaded
                    Constructor
PRECONDITION:	   None
POSTCONDITION:     A location in memory to store a Class Object
===============================================================================*/ 

template <typename DataType>
StackArray<DataType>::StackArray(const StackArray& other) : StackArray(other.maxSize){

    
	(*this) = other;

}
 

/*=============================================================================
FUNCTION:          operator=
DESCRIPTION:       Overloaded Assignment Operator for the Stackarray Class,
                    assigs one object to another.
PRECONDITION:	   two objects exist and assigned like obj1 = obj2, making
                    obj1 equal to obj2
POSTCONDITION:     A location for obj2 to be stored
===============================================================================*/

template <typename DataType>
StackArray<DataType>& StackArray<DataType>::operator=(const StackArray& other){

    this->top = other.top;
	this->maxSize = other.maxSize;
    
	for(int i = 0; i < this->maxSize; ++i){
		this->dataItems[i] = other.dataItems[i];
	}
	

	return (*this);
}
 
/*=============================================================================
FUNCTION:          ~StackArray()
DESCRIPTION:       Destructor for the Class StackArray, clears memory
PRECONDITION:	   An objects Scope must end.
POSTCONDITION:     None
===============================================================================*/

template <typename DataType>
StackArray<DataType>::~StackArray(){

	this->clear();
	maxSize = 0;
	delete dataItems;					// remove the allocated memory location.
	

}


/*=============================================================================
FUNCTION:          push(const DataType& newDataItem)
DESCRIPTION:       Pushes a new item onto the stack
PRECONDITION:      A stack must exist in order to push
POSTCONDITION:     A non full stack must be present, if not an error will be sent
===============================================================================*/

template <typename DataType>   
void StackArray<DataType>::push(const DataType& newDataItem){ //throw (logic_error)

	
	if (this->top == this->maxSize - 1){
		throw logic_error("This stack is full, can not push anymore\n");
	}else{
		
		this->top++;
		
		this->dataItems[this->top] = newDataItem;
		
	}
	

}
    
/*=============================================================================
FUNCTION:          pop()
DESCRIPTION:       Pop the top value from the stack.
PRECONDITION:	   A non empty stack or error will send.
POSTCONDITION:     A location to store the popped value
===============================================================================*/

template <typename DataType>
DataType StackArray<DataType>::pop(){ //throw (logic_error)

	
    if(!isEmpty()){
        DataType temp = this->dataItems[this->top];				// store the top of the stack
        this->dataItems[this->top] = (DataType) 0;


        this->top--;
        
        return temp;
    }else throw logic_error("This stack is Empty, can not pop anymore\n");
    

}


/*=============================================================================
FUNCTION:          clear()
DESCRIPTION:       Clears the stack of all elements
PRECONDITION:      A object that calls it
POSTCONDITION:     None
===============================================================================*/

template <typename DataType>
void StackArray<DataType>::clear(){

	this->top = 0;
	for(int i = 0; i < this->maxSize; ++i){
		this->dataItems[i] = 0;				// remove every element inside of the array
	}

}


/*=============================================================================
FUNCTION:          isEmpty()
DESCRIPTION:       Checks if the Stack is empty
PRECONDITION:      None
POSTCONDITION:     Boolean location to store flag
===============================================================================*/

template <typename DataType>
bool StackArray<DataType>::isEmpty() const{

	if(this->top == -1){
		return true;
	}else{
		return false;
	}

}
  

/*=============================================================================
FUNCTION:          isFull()
DESCRIPTION:       Checks if the Stack is full
PRECONDITION:      None
POSTCONDITION:     Boolean location to store flag
===============================================================================*/

template <typename DataType>
bool StackArray<DataType>::isFull() const{

	if(this->top == this->maxSize - 1){
		return true;
	}else{
		return false;
	}

}

/*=============================================================================
FUNCTION:          showStructure() const 
DESCRIPTION:       Displays the contents of a Structured Stack
PRECONDITION:      None
POSTCONDITION:     None
CREDIT:			   Dr. Kostas Alexis  Retrieved 2018-09-22    
===============================================================================*/


template <typename DataType>
void StackArray<DataType>::showStructure() const 

// Array implementation. Outputs the data items in a stack. If the
// stack is empty, outputs "Empty stack". This operation is intended
// for testing and debugging purposes only.

{
    if( isEmpty() ) {
	cout << "Empty stack." << endl;
    }
    else {
	int j;
	cout << "Top = " << top << endl;
	for ( j = 0 ; j < maxSize ; j++ )
	    cout << j << "\t";
	cout << endl;
	for ( j = 0 ; j <= top  ; j++ )
	{
	    if( j == top )
	    {
	        cout << '[' << dataItems[j] << ']'<< "\t"; // Identify top
	    }
	    else
	    {
		cout << dataItems[j] << "\t";
	    }
	}
	cout << endl;
    }
    cout << endl;
}
