// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _NUMBER_COMMAND_H_
#define _NUMBER_COMMAND_H_

#include "Command.h"

/**
* @class Number_Command
*
* Concretion of the command class that describes a number
*/
class Number_Command : public Command
{
public:

	/**
	* Initializing constructor.
	*
	* @param[in]	s		stack object being executed on
	* @param[in]	num		number value to be stored
	*/
	Number_Command(Stack<int>& s, int num);

	/// Destructor
	~Number_Command(void);

	/// Pushes the value stored in 'num_' onto the stack
	virtual void execute(void);

	// Prints command
	virtual void print(void);

protected:
	/// Pointer to the stack being operated on
	Stack<int>& s_;

	/// Value of the number
	int num_;
};

#include "Number_Command.cpp"

#endif   // !defined _NUMBER_COMMAND_H_