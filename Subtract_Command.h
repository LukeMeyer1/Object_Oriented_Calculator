// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _SUBTRACT_COMMAND_H_
#define _SUBTRACT_COMMAND_H_

#include "Binary_Operator_Command.h"

/**
* @class Subtract_Command
*
* Binary operator concretion that describes the
* subtraction of two numbers
*/
class Subtract_Command : public Binary_Operator_Command
{
public:

	/**
	* Initializing constructor.
	*
	* @param[in]	s		stack object being executed on
	*/
	Subtract_Command(Stack<int>& s);

	/// Destructor
	~Subtract_Command(void);

	/**
	* Pops the top two numbers off the stack, subtracts
	* the first from the second then pushes the difference
	* back onto the stack
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

#include "Subtract_Command.cpp"

#endif   // !defined _SUBTRACT_COMMAND_H_