// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Tree_Builder.h"
#include "Number_Node.h"
#include "Add_Node.h"


// 
// Tree_Builder 
//
Tree_Builder::Tree_Builder()
	: tree_(nullptr)
{ }

//
// ~Tree_Builder
//
Tree_Builder::~Tree_Builder(void)
{ }

//
// build number
//
void Tree_Builder::build_number(int num)
{
	Number_Node * node = new Number_Node(num);
	this->set_first_empty_node(node);
}

//
// build add
//
void Tree_Builder::build_add_operator(void)
{
	Add_Node * node = new Add_Node();
	this->build_operator(node);
}

//
// build subtract
//
void Tree_Builder::build_subtract_operator(void)
{}

//
// build multiply
//
void Tree_Builder::build_multiply_operator(void)
{}

//
// build divide
//
void Tree_Builder::build_divide_operator(void)
{}

//
// build modulo
//
void Tree_Builder::build_modulo_operator(void)
{}

//
//	start expression
//
void Tree_Builder::start_expression(void)
{}

//
//	end expression
//
void Tree_Builder::end_expression(void)
{}

//
// parser
//
Expression_Parser& Postfix_Builder::parser(void)
{
	return Tree_Parser(this);
}

//
//	get expression
//
Tree_Node * Tree_Builder::get_expression(void)
{
	return this->tree_;
}

//
// build 
//
void Tree_Builder::build_operator(Binary_Operator_Node* node) 
{
	if (this->tree_ == nullptr)
	{
		this->tree_ = node;
		return;
	}
	this->set_first_empty_node(node);
}

//
//	set first empty node
//
bool Tree_Builder::set_first_empty_node(Tree_Node* node)
{
	if (this->tree_->left_branch_ == nullptr)
	{
		this->tree_->left_branch_ = node;
		return true;
	}
	else if (this->tree_->right_branch_ == nullptr)
	{
		this->tree_->right_branch_ = node;
		return true;
	}
	return false;
}