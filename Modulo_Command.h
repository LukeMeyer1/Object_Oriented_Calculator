// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _MODULO_COMMAND_H_
#define _MODULO_COMMAND_H_

#include "Binary_Operator_Command.h"

/**
* @class Modulo_Command
*
* Binary operator concretion that describes the
* division of two numbers
*/
class Modulo_Command : public Binary_Operator_Command
{
public:

	/**
	* Initializing constructor.
	*
	* @param[in]	s		stack object being executed on
	*/
	Modulo_Command(Stack<int>& s);

	/// Destructor
	~Modulo_Command(void);

	/**
	* Pops the top two numbers off the stack, divides the
	* top number from the number below it, then pushes
	* the remainder back onto the stack
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

#include "Modulo_Command.cpp"

#endif   // !defined _MODULO_COMMAND_H_