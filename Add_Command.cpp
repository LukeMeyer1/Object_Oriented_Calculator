// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Add_Command.h"


// 
// Add_Command 
//
Add_Command::Add_Command(Stack<int>& s)
	: s_(s)
{ }

//
// ~Add_Command
//
Add_Command::~Add_Command (void)
{ }

//
// execute
//
void Add_Command::execute (void)
{
	int num2 = this->s_.pop(), num1 = this->s_.pop();
	this->s_.push(num1 + num2);
}

//
// priority
//
int Add_Command::priority(void)
{
	return 1;
}

// 
// print
//
void print(void)
{
	std::cout << "+";
}