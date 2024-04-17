// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _STACK_COMMAND_FACTORY_H_
#define _STACK_COMMAND_FACTORY_H_

#include "Command_Factory.h"

/**
* @class Stack_Command_Factory
*
* Pure Abstract class that acts as a template for
* creation of command storage objects of different
* types
*/
class Stack_Command_Factory : public Command_Factory
{ 
public:
	/**
	* Initializing constructor.
	*
	* @param[in]	s		stack object being executed on
	*/
	Stack_Command_Factory(Stack<int>& s);

	/// Destructor
	~Stack_Command_Factory(void);

	/**
	* Creates a number command
	*
	* @param	num		integer value that the command is instantiated with
	*/
	Number_Command * create_number_command(int num);

	/// Creates an add command
	Add_Command * create_add_command(void);

	/// Creates an subtract command
	Subtract_Command* create_subtract_command(void);

	/// Creates an multiply command
	Multiply_Command* create_multiply_command(void);

	/// Creates an divide command
	Divide_Command* create_divide_command(void);

	/// Creates an modulo command
	Modulo_Command* create_modulo_command(void);

protected:
	/// Pointer to the stack that the commands will be operating on
	Stack<int> & stack_;
};

#include "Stack_Command_Factory.cpp"

#endif   // !defined _STACK_COMMAND_FACTORY_H_
