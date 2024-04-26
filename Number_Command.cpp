// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Number_Command.h"


// 
// Number_Command 
//
Number_Command::Number_Command (Stack<int> & s, int num)
	: s_ (s),
	num_ (num)
{ }

//
// ~Number_Command
//
Number_Command::~Number_Command (void)
{ }

//
// execute
//
void Number_Command::execute (void)
{
	this->s_.push(this->num_);
}

// 
// print
//
void Number_Command::print(void)
{
	std::cout << this->num_;
}