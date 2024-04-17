// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _BINARY_OPERATOR_COMMAND_H_
#define _BINARY_OPERATOR_COMMAND_H_

#include "Operator_Command.h"

/**
* @class Binary_Operator_Command
*
* Defines operations that are needed for an binary operator command
*/
class Binary_Operator_Command : public Operator_Command
{
public:
	/// Operation that is executed on the stack
	virtual void execute(void) = 0;

	/// Returns the commands priority for infix to postfix
	virtual int priority(void) = 0;
};

#endif   // !defined _BINARY_OPERATOR_COMMAND_H_