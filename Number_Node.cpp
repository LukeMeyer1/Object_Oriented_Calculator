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
// accept
//
void Number_Node::accept(Tree_Node_Visitor& v)
{
	return;
}

//
// get num
//
int Number_Node::get_num(void)
{
	return this->num_;
}