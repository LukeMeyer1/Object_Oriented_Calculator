// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _UNARY_OPERATOR_COMMAND_H_
#define _UNARY_OPERATOR_COMMAND_H_

/**
* @class Unary_Operator_Command
*
* Defines operations that are needed for an unary operator command
*/
class Unary_Operator_Command : public Operator_Command
{
public:
	/// Operation that is executed on the stack
	virtual void execute(void) = 0;

	/// Returns the commands priority for infix to postfix
	virtual int priority(void) = 0;

	// Prints command
	virtual void print(void) = 0;
};

#endif   // !defined _UNARY_OPERATOR_COMMAND_H_