// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Divide_Command.h"


// 
// Divide_Command 
//
Divide_Command::Divide_Command(Stack<int>& s)
	: s_ (s)
{ }

//
// ~Divide_Command
//
Divide_Command::~Divide_Command(void)
{ }

//
// execute
//
void Divide_Command::execute(void)
{
	int num2 = this->s_.pop(), num1 = this->s_.pop();
	this->s_.push(int(num1 / num2));
}

//
// priority
//
int Divide_Command::priority(void)
{
	return 2;
}

// 
// print
//
void print(void)
{
	std::cout << "/";
}