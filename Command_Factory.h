// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _COMMAND_FACTORY_H_
#define _COMMAND_FACTORY_H_

#include "Number_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Modulo_Command.h"


/**
* @class Command_Factory
*
* Pure Abstract class that acts as a template for
* creation of command storage objects of different
* types
*/
class Command_Factory
{
public:

	/**
	* Creates a number command
	* 
	* @param	num		integer value that the command is instantiated with
	*/
	virtual Number_Command * create_number_command(int num) = 0;

	/// Creates an add command
	virtual Add_Command * create_add_command(void) = 0;

	/// Creates an subtract command
	virtual Subtract_Command * create_subtract_command(void) = 0;

	/// Creates an multiply command
	virtual Multiply_Command * create_multiply_command(void) = 0;

	/// Creates an divide command
	virtual Divide_Command * create_divide_command(void) = 0;

	/// Creates an modulo command
	virtual Modulo_Command * create_modulo_command(void) = 0;
};

#endif   // !defined _COMMAND_FACTORY_H_
