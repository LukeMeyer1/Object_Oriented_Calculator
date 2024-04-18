// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Multiply_Node.h"


// 
// Multiply_Node 
//
Multiply_Node::Multiply_Node()
	: Binary_Operator_Node()
{ }

// 
// Multiply_Node 
//
Multiply_Node::Multiply_Node(Tree_Node* left_branch)
	: Binary_Operator_Node(left_branch)
{ }

// 
// Multiply_Node 
//
Multiply_Node::Multiply_Node(Tree_Node* left_branch, Tree_Node* right_branch)
	: Binary_Operator_Node(left_branch, right_branch)
{ }

//
// ~Multiply_Node
//
Multiply_Node::~Multiply_Node(void)
{ }

//
// accept
//
void Multiply_Node::accept(Tree_Node_Visitor& v)
{
	v.Visit_Multiply_Node(*this);
}