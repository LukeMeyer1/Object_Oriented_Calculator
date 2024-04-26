// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "Stack.h"

/**
* @class Command
* 
* Command is the base class for all calculator commands, defines
* functionality that will be implemented by the concretions
*/
class Command
{
public:
	/// Operation that is executed on the stack
	virtual void execute (void) = 0;
	virtual void print (void) = 0;
};

#endif   // !defined _COMMAND_H_