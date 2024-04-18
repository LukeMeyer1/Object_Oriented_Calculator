// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Add_Node.h"


// 
// Add_Node 
//
Add_Node::Add_Node()
	: Binary_Operator_Node()
{ }

// 
// Add_Node 
//
Add_Node::Add_Node(Tree_Node* left_branch)
	: Binary_Operator_Node(left_branch)
{ }

// 
// Add_Node 
//
Add_Node::Add_Node(Tree_Node* left_branch, Tree_Node* right_branch)
	: Binary_Operator_Node(left_branch, right_branch)
{ }

//
// ~Add_Node
//
Add_Node::~Add_Node(void)
{ }

//
// accept
//
void Add_Node::accept(Tree_Node_Visitor& v)
{
	v.Visit_Add_Node(*this);
}