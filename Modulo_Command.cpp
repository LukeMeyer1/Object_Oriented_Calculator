// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Modulo_Command.h"


// 
// Modulo_Command 
//
Modulo_Command::Modulo_Command(Stack<int>& s)
	: s_ (s)
{ }

//
// ~Modulo_Command
//
Modulo_Command::~Modulo_Command(void)
{ }

//
// execute
//
void Modulo_Command::execute(void)
{
	int num2 = this->s_.pop(), num1 = this->s_.pop();
	this->s_.push(num1 % num2);
}

//
// priority
//
int Modulo_Command::priority(void)
{
	return 2;
}

// 
// print
//
void print(void)
{
	std::cout << "%";
}