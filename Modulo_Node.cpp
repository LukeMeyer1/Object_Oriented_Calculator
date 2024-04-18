// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Modulo_Node.h"


// 
// Modulo_Node 
//
Modulo_Node::Modulo_Node()
	: Binary_Operator_Node()
{ }

// 
// Modulo_Node 
//
Modulo_Node::Modulo_Node(Tree_Node* left_branch)
	: Binary_Operator_Node(left_branch)
{ }

// 
// Modulo_Node 
//
Modulo_Node::Modulo_Node(Tree_Node* left_branch, Tree_Node* right_branch)
	: Binary_Operator_Node(left_branch, right_branch)
{ }

//
// ~Modulo_Node
//
Modulo_Node::~Modulo_Node(void)
{ }

//
// accept
//
void Modulo_Node::accept(Tree_Node_Visitor& v)
{
	v.Visit_Modulo_Node(*this);
}