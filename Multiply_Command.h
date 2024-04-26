// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _MULTIPLY_COMMAND_H_
#define _MULTIPLY_COMMAND_H_

#include "Binary_Operator_Command.h"

/**
* @class Multiply_Command
*
* Binary operator concretion that describes the
* multiplication of two numbers
*/
class Multiply_Command : public Binary_Operator_Command
{
public:

	/**
	* Initializing constructor.
	*
	* @param[in]	s		stack object being executed on
	*/
	Multiply_Command(Stack<int>& s);

	/// Destructor
	~Multiply_Command(void);

	/**
	* Pops the top two numbers off the stack, multiplies them
	* together and then pushes the product back onto the stack
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

#include "Multiply_Command.cpp"

#endif   // !defined _MULTIPLY_COMMAND_H_