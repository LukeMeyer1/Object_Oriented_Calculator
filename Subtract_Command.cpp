// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Subtract_Command.h"


// 
// Subtract_Command 
//
Subtract_Command::Subtract_Command(Stack<int>& s)
	: s_ (s)
{ }

//
// ~Subtract_Command
//
Subtract_Command::~Subtract_Command(void)
{ }

//
// execute
//
void Subtract_Command::execute(void)
{
	int num2 = this->s_.pop(), num1 = this->s_.pop();
	this->s_.push(num1 - num2);
}

//
// priority
//
int Subtract_Command::priority(void)
{
	return 1;
}

// 
// print
//
void print(void)
{
	std::cout << "-";
}