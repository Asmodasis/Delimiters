/*===============================================================================

FILE:              StackLinked.h

DESCRIPTION:       Class declaration for the Linked implementation of the Stack ADT

COMPILER:          g++ 5.4 running the Linux Make System

NOTES:             Put other information here ...

MODIFICATION HISTORY:

Author                  Date               Version
================================================================================
Dr. Kostas Alexis  Retrieved 2018-09-22    Version 1.0
Shawn Ray               2018-09-22         Version 1.0 started Assignment
Shawn Ray               2018-09-23         Version 1.1 changed the logic_error class
                                                       implementations 
================================================================================*/


#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <stdexcept>
#include <iostream>

using namespace std;

#include "Stack.h"

template <typename DataType>
class StackLinked : public Stack<DataType> {

  public:

    StackLinked();                          // removed max size, not needed for linked list
    StackLinked(const StackLinked& other);
    StackLinked& operator=(const StackLinked& other);
    ~StackLinked();

    void push(const DataType& newDataItem); // throw (logic_error)
    DataType pop(); //throw (logic_error)
    
    void clear();

    bool isEmpty() const;
    bool isFull() const;

    void showStructure() const;

  private:

    class StackNode {
      public:
	     StackNode(const DataType& nodeData, StackNode* nextPtr);

	     DataType dataItem;
	     StackNode* next;
    };

    StackNode* top;
};

#endif		//#ifndef STACKARRAY_H

