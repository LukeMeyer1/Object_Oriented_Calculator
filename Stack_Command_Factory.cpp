// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Stack_Command_Factory.h"


// 
// Stack_Command_Factory 
//
Stack_Command_Factory::Stack_Command_Factory(Stack<int>& s)
	: stack_ (s)
{ }

//
// ~Stack_Command_Factory
//
Stack_Command_Factory::~Stack_Command_Factory(void)
{ }

//
// create_number_command
//
Number_Command * Stack_Command_Factory::create_number_command(int num)
{
	return new Number_Command(stack_, num);
}

//
// create_add_command
//
Add_Command * Stack_Command_Factory::create_add_command(void)
{
	return new Add_Command(stack_);
}

//
// create_subtract_command
//
Subtract_Command* Stack_Command_Factory::create_subtract_command(void)
{
	return new Subtract_Command(stack_);
}

//
// create_multiply_command
//
Multiply_Command* Stack_Command_Factory::create_multiply_command(void)
{
	return new Multiply_Command(stack_);
}

//
// create_divide_command
//
Divide_Command* Stack_Command_Factory::create_divide_command(void)
{
	return new Divide_Command(stack_);
}

//
// create_modulo_command
//
Modulo_Command* Stack_Command_Factory::create_modulo_command(void)
{
	return new Modulo_Command(stack_);
}
