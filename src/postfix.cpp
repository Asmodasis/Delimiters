
/*===============================================================================

FILE:              postfix.cpp

DESCRIPTION:        evalutes a mathematical expression using postfix notations

COMPILER:          g++ 5.4 running the Linux Make System

NOTES:             Put other information here ...

MODIFICATION HISTORY:

Author                  Date               Version
================================================================================
Shawn Ray               2018-10-02         Version 1.0 started Assignment
Shawn Ray               2018-10-03         Version 1.1
Shawn Ray               2018-10-04         Version 1.2
================================================================================*/

#include "../headers/config.h"

#if !LAB6_TEST1
#  include "StackArray.cpp"
#else
#  include "StackLinked.cpp"
#endif

#include <cstring>

// function declarations
template<typename dataType> 
void postfix(StackLinked<dataType> &, StackLinked<char>  &, char *);


int main(int argc, char *argv[], char *envp[]){


	StackLinked<float> numStack;		
	StackLinked<char> arrayStack;
	char buffer[256];

	try{

	if(argc > 1){								// command line mode

		for(int i = 1; i < argc ; ++i){
			postfix<float>(numStack, arrayStack, (argv)[i]);
		}

	}else{										// user input mode

		//std::cout << "\n\tWould you like to work with integers or floats?\n\t(i or f): ";


		std::cout << "\n\tHello, please enter the postfix mathematical expression you wish to be evaluated : ";
		std::cin.getline(buffer, 256);
		postfix<float>(numStack, arrayStack, buffer);

	}


	}catch (logic_error err){
		std::cout << "Error message received as : " << err.what() << std::endl;
	}

	



	return 0;
}

template<typename dataType>
void postfix(StackLinked<dataType> &numStack, StackLinked<char> &arrayStack, char * array){

	char temp;															// location for array popping
	int arrayLen = strlen(array);
	dataType operand[2];												// other datatypes
	 

	for(int i = arrayLen - 1; i > -1; --i){								// push the array onto a stack
		arrayStack.push(array[i]);										// easier to work with

	}

	while((!arrayStack.isEmpty())){										// if array is empty, stop
	temp = arrayStack.pop();


		if((((dataType)temp) >= 48) && (((dataType)temp) <= 57)){ 		// it's a number
			numStack.push(((dataType)temp - 48 ));						// pivot to zero

		}else{															// it's a character

			if(temp != '+' && temp != '-' && temp != '*' && temp != '/' ){
				throw logic_error("\n\tYou can not evaluate this expression as it uses operators not accounted for\n");

			}else{
					for(int j = 0; j < 2; ++j) operand[j] = numStack.pop();

					switch(temp){
					case '+':
						numStack.push((operand[1] + operand[0]));
					break;
					case '-':
						numStack.push((operand[1] - operand[0]));
					break; 
					case '*':
						numStack.push((operand[1] * operand[0]));
					break;
					case '/':
						numStack.push((operand[1] / operand[0]));
					break;
					}
				 }	
			
		}

	}
	std::cout << "\n\tThe value of the expression : " << array << " is " << numStack.pop() << std::endl << std::endl;

	numStack.clear();
	arrayStack.clear();													// clean up stack, good practice.

}