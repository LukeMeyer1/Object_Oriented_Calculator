// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Multiply_Command.h"


// 
// Multiply_Command 
//
Multiply_Command::Multiply_Command(Stack<int>& s)
	: s_ (s)
{ }

//
// ~Multiply_Command
//
Multiply_Command::~Multiply_Command(void)
{ }

//
// execute
//
void Multiply_Command::execute(void)
{
	int num2 = this->s_.pop(), num1 = this->s_.pop();
	this->s_.push(num1 * num2);
}

//
// priority
//
int Multiply_Command::priority(void)
{
	return 2;
}