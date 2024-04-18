// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Eval_Tree_Visitor.h"

//
// Default constructor
//
Eval_Tree_Visitor::Eval_Tree_Visitor()
{ }

// 
// Destructor
// 
Eval_Tree_Visitor::~Eval_Tree_Visitor(void)
{ }

// 
// Visit Number Node
// 
void Eval_Tree_Visitor::Visit_Number_Node(const Tree_Node& node)
{
	std::cout << "visited number node";
}
