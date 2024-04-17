// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Binary_Operator_Node.h"
#include "Number_Node.h"


// 
// Binary_Operator_Node 
//
Binary_Operator_Node::Binary_Operator_Node()
	: left_branch_(new Number_Node(1)),
	right_branch_(new Number_Node(2))
{ }

// 
// Binary_Operator_Node 
//
Binary_Operator_Node::Binary_Operator_Node(Tree_Node*& left_branch)
	: left_branch_(left_branch),
	right_branch_(new Number_Node(2))
{ }

// 
// Binary_Operator_Node 
//
//Binary_Operator_Node::Binary_Operator_Node(Tree_Node*& left_branch, Tree_Node*& right_branch)
//	: left_branch_(left_branch),
//	right_branch_(right_branch)
//{ }

//
// ~Binary_Operator_Node
//
Binary_Operator_Node::~Binary_Operator_Node(void)
{ 
	delete this->right_branch_;
	delete this->left_branch_;
}

//
// eval
//
int Binary_Operator_Node::eval()
{
	return (left_branch_->eval() + right_branch_->eval());
}
