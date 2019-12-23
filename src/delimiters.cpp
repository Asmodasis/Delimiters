//--------------------------------------------------------------------
//
//   delimiters.cpp
//
//--------------------------------------------------------------------


#include "../headers/config.h"


#include <iostream>
#include <string>

#if LAB6_TEST1
#   include "StackLinked.cpp"
#else
#   include "StackArray.cpp"
#endif

//--------------------------------------------------------------------

bool delimitersOk ( const string &expression );
bool isPaired(char open, char close);

//--------------------------------------------------------------------

int main()
{
    string inputLine;            // Input line
    char   ch;                   // Holding pen for input chars

    cout << "This program checks for properly matched delimiters."
         << endl;

    while( cin )
    {
        cout << "Enter delimited expression (<EOF> to quit) : "
             << endl;

        // Read in one line
        inputLine = "";
        cin.get(ch);
        while( cin && ch != '\n' )
        {
            inputLine = inputLine + ch;
            cin.get(ch);
        }

        if( ! cin )              // Reached EOF: stop processing
            break;
    
        if ( delimitersOk (inputLine) )
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
    }

    return 0;
}

//--------------------------------------------------------------------
// delimitersOk: the function that students must implement for 
//    Programming Exercise 3.
// Note: we used the term "braces" to describe '[' and ']'. It would
//    have been better to use the term "brackets". The program can be
//    easily modified to process any set of matching delimiters.
//--------------------------------------------------------------------

// Insert your delimitersOk function below


bool delimitersOk ( const string &expression ){

	StackLinked<char> *delimiterStack = new StackLinked<char>();

	int expLen = expression.length();

	bool isBalanced = true;
	
	int index = 0;

	char nextCharacter = ' ';

	while(isBalanced && (index < expLen)){

		nextCharacter = expression.at(index);

		switch(nextCharacter){

			case '(': case '[': case '{':
			delimiterStack->push(nextCharacter);
			break;

			case ')': case ']': case '}':
				if(delimiterStack->isEmpty())
					isBalanced = false;
				else{
					isBalanced = isPaired(delimiterStack->pop(), nextCharacter);
				}
				break;
			default:
				break;
		}
			index++;
	}
	if(!delimiterStack->isEmpty())
		isBalanced = false;

	delete delimiterStack;
	return isBalanced;
}


bool isPaired(char open, char close){

	return	(open == '(' && close == ')') ||
			(open == '[' && close == ']') ||
			(open == '{' && close == '}');

}