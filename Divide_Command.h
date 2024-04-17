// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _DIVIDE_COMMAND_H_
#define _DIVIDE_COMMAND_H_

#include "Binary_Operator_Command.h"

/**
* @class Divide_Command
*
* Binary operator concretion that describes the
* division of two numbers
*/
class Divide_Command : public Binary_Operator_Command
{
public:

	/**
	* Initializing constructor.
	*
	* @param[in]	s		stack object being executed on
	*/
	Divide_Command(Stack<int>& s);

	/// Destructor
	~Divide_Command(void);

	/**
	* Pops the top two numbers off the stack, divides the
	* top number from the number below it, then pushes
	* the qoutient as an integer back onto the stack
	*/
	virtual void execute(void);

	/// Returns the commands priority for infix to postfix
	virtual int priority(void);

protected:
	/// Pointer to the stack being operated on
	Stack<int>& s_;
};

#include "Divide_Command.cpp"

#endif   // !defined _DIVIDE_COMMAND_H_