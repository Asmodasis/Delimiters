
/*===============================================================================

FILE:              StackArray.h

DESCRIPTION:       class declaration for the Array implementation of the Stack ADT

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
class StackArray : public Stack<DataType> {
  public:
    StackArray(int maxNumber = Stack<DataType>::MAX_STACK_SIZE);
    StackArray(const StackArray& other);
    StackArray& operator=(const StackArray& other);
    ~StackArray();

    void push(const DataType& newDataItem); // throw (logic_error)
    DataType pop(); //throw (logic_error)

    void clear();

    bool isEmpty() const;
    bool isFull() const;

    void showStructure() const;

  private:
    int maxSize;
    int top;
    DataType* dataItems;
};

#endif		//#ifndef STACKARRAY_H
