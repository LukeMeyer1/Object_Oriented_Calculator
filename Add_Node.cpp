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
// eval
//
int Add_Node::eval(void)
{
	return this->left_branch_->eval() + this->right_branch_->eval();
}

//
// print
//
void Add_Node::print(void)
{
	try {
		this->left_branch_->print();
		this->right_branch_->print();
	}catch(...){ }
	std::cout << "+";
}