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
// eval
//
int Divide_Node::eval(void)
{
	return this->left_branch_->eval() / this->right_branch_->eval();
}