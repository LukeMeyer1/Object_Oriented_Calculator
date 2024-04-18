// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Subtract_Node.h"


// 
// Subtract_Node 
//
Subtract_Node::Subtract_Node()
	: Binary_Operator_Node()
{ }

// 
// Subtract_Node 
//
Subtract_Node::Subtract_Node(Tree_Node* left_branch)
	: Binary_Operator_Node(left_branch)
{ }

// 
// Subtract_Node 
//
Subtract_Node::Subtract_Node(Tree_Node* left_branch, Tree_Node* right_branch)
	: Binary_Operator_Node(left_branch, right_branch)
{ }

//
// ~Subtract_Node
//
Subtract_Node::~Subtract_Node(void)
{ }

//
// eval
//
int Subtract_Node::eval(void)
{
	return this->left_branch_->eval() - this->right_branch_->eval();
}