// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Number_Node.h"


// 
// Number_Node 
//
Number_Node::Number_Node(int num)
	: num_(num)
{ }

//
// ~Number_Node
//
Number_Node::~Number_Node(void)
{ }

//
// eval
//
int Number_Node::eval(void)
{
	return this->num_;
}

//
// print
//
void Number_Node::print(void)
{
	std::cout << this->num_;
}