
/*===============================================================================

FILE:              Stack.h

DESCRIPTION:       the virtual class definition for a generic Stack type

COMPILER:          g++ 5.4 running the Linux Make System

NOTES:             Put other information here ...

MODIFICATION HISTORY:

Author                  Date               Version
================================================================================
Dr. Kostas Alexis  Retrieved 2018-09-22    Version 1.0
Shawn Ray       	    2018-09-22         Version 1.0 started Assignment
Shawn Ray       	    2018-09-23         Version 1.1 changed the logic_error class
                                                  application, and added a constructor
                                                  to inherit from so all derived contructors
                                                  will think every object generated is a "Stack"
================================================================================*/

#ifndef STACK_H
#define STACK_H

#include <stdexcept>
#include <iostream>

using namespace std;

template <typename DataType>
class Stack {
  public:
    static const int MAX_STACK_SIZE = 8;

    Stack(){};

    virtual ~Stack();

    virtual void push(const DataType& newDataItem) = 0; // throw (logic_error)
    virtual DataType pop() = 0; // throw (logic_error) 

    virtual void clear() = 0;

    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;

    virtual void showStructure() const = 0;
};

template <typename DataType>
Stack<DataType>::~Stack() 
// Not worth having a separate class implementation file for the destuctor
{}

#endif		// #ifndef STACK_H
