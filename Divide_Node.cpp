// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Divide_Node.h"


// 
// Divide_Node 
//
Divide_Node::Divide_Node()
	: Binary_Operator_Node()
{ }

// 
// Divide_Node 
//
Divide_Node::Divide_Node(Tree_Node* left_branch)
	: Binary_Operator_Node(left_branch)
{ }

// 
// Divide_Node 
//
Divide_Node::Divide_Node(Tree_Node* left_branch, Tree_Node* right_branch)
	: Binary_Operator_Node(left_branch, right_branch)
{ }

//
// ~Divide_Node
//
Divide_Node::~Divide_Node(void)
{ }

//
// accept
//
void Divide_Node::accept(Tree_Node_Visitor& v)
{
	v.Visit_Divide_Node(*this);
}