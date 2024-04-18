// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Eval_Tree_Node.h"

//
// Eval_Tree_Visitor
//
Eval_Tree_Visitor::Eval_Tree_Visitor(void)
{ }

//
// Destructor
//
Eval_Tree_Visitor::~Eval_Tree_Visitor(void)
{ }

//
// Visit Number Node
//
void Eval_Tree_Visitor::Visit_Number_Node(const Number_Node& node)
{
	std::cout << node.num_ << std::endl;
}

//
// Visit Add Node
//
void Eval_Tree_Visitor::Visit_Add_Node(const Add_Node& node)
{
	return;
}

//
// Visit Subtract Node
//
void Eval_Tree_Visitor::Visit_Subtract_Node(const Subtract_Node& node)
{
	return;
}

//
// Visit Multiply Node
//
void Eval_Tree_Visitor::Visit_Multiply_Node(const Multiply_Node& node)
{
	return;
}

//
// Visit Divide Node
//
void Eval_Tree_Visitor::Visit_Divide_Node(const Divide_Node& node)
{
	return;
}

//
// Visit Modulo Node
//
void Eval_Tree_Visitor::Visit_Modulo_Node(const Modulo_Node& node) 
{
	return;
}