// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _OPERATOR_COMMAND_H_
#define _OPERATOR_COMMAND_H_

#include "Command.h"

/**
* @class Operator_Command
*
* Defines operations that are needed for an operator command
*/
class Operator_Command : public Command
{
public:
	/// Operation that is executed on the stack
	virtual void execute(void) = 0;

	/// Returns the commands priority for infix to postfix
	virtual int priority(void) = 0;

	// Prints command
	virtual void print(void) = 0;
};

#endif   // !defined _OPERATOR_COMMAND_H_