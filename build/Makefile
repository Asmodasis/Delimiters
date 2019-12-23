#===============================================================================
#
#FILE:              Makefile
#
#DESCRIPTION:       This is the Makefile for the MyStack files
#
#COMPILER:          Linux make 

#NOTES:             Put other information here ...
#
#MODIFICATION HISTORY:
#
#Author                  Date               Version
#================================================================================
#Shawn Ray       	    2018-09-13          Version 1.0 started Assignment
#
#================================================================================

SHELL = /bin/sh                           # global variable for shell

CC = g++                                  # Compiler
CXXFLAGS = -pedantic -std=c++11 -Wall -g  # Compiler flags

OUTPUT = test6                          # executable
LIBS =                                    # libaries-I 

#Building will be done from the build file
SRCXXDIR = ../src/
HEADXXDIR = ../headers/
BUILDXXDIR = ../build/



OBJXXFILES = test6.o StackArray.o StackLinked.o
OBJXXFILES2 = postfix.o StackArray.o StackLinked.o
OBJXXFILES3 = delimiters.o StackArray.o StackLinked.o

#.PHONY: all
all: $(OBJXXFILES)	
	$(CC) $(CXXFLAGS) $(OBJXXFILES) -o test6

all: $(OBJXXFILES2)	
	$(CC) $(CXXFLAGS) $(OBJXXFILES2) -o postfix

all: $(OBJXXFILES3)	
	$(CC) $(CXXFLAGS) $(OBJXXFILES3) -o delimiters
#
#
#


test6.o: $(addprefix $(SRCXXDIR), test6.cpp) $(addprefix $(HEADXXDIR), config.h)
	$(CC) $(CXXFLAGS) -c $(addprefix $(SRCXXDIR), test6.cpp) -o test6.o

postfix.o: $(addprefix $(SRCXXDIR), postfix.cpp) 
	$(CC) $(CXXFLAGS) -c $(addprefix $(SRCXXDIR), postfix.cpp) -o postfix.o

delimiters.o: $(addprefix $(SRCXXDIR), delimiters.cpp)
	$(CC) $(CXXFLAGS) -c $(addprefix $(SRCXXDIR), delimiters.cpp) -o delimiters.o

StackArray.o: $(addprefix $(SRCXXDIR), StackArray.cpp) $(addprefix $(SRCXXDIR), StackArray.cpp)
	$(CC) $(CXXFLAGS) -c $(addprefix $(SRCXXDIR), StackArray.cpp) -o StackArray.o

StackLinked.o: $(addprefix $(SRCXXDIR), StackLinked.cpp) $(addprefix $(SRCXXDIR), StackLinked.cpp)
	$(CC) $(CXXFLAGS) -c $(addprefix $(SRCXXDIR), StackLinked.cpp) -o StackLinked.o


#
#
#
#
#
#.PHONY: clean
clean:
	
	rm -f $(OUTPUT)
	rm -f *.o

	reset
	@echo
	@echo
	@echo

	@echo Make clean, removed object and executable files ...
	@echo Contents in this Directory ...
	ls -lt

	@echo
	@echo
	@echo
#
#
#
#

