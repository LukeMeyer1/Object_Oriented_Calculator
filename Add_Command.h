// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

#include "Binary_Operator_Command.h"

/**
* @class Add_Command
*
* Binary operator concretion that describes the
* addition of two numbers
*/
class Add_Command : public Binary_Operator_Command
{
public:

	/**
	* Initializing constructor.
	*
	* @param[in]	s		stack object being executed on
	*/
	Add_Command (Stack<int>& s);

	/// Destructor
	~Add_Command (void);

	/** 
	* Pops the top two numbers off the stack, adds them
	* together and then pushes the result back onto the stack
	*/
	virtual void execute(void);

	/// Returns the commands priority for infix to postfix
	virtual int priority(void);

	// Prints command
	virtual void print(void);

protected:
	/// Pointer to the stack being operated on
	Stack<int>& s_;
};

#include "Add_Command.cpp"

#endif   // !defined _ADD_COMMAND_H_