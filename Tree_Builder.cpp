// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Postfix_Builder.h"


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
	if (this->tree_ == nullptr)
	{
		this->tree_ = node;
		return;
	}
	this->set_first_empty_node(this->tree_, node)
}

//
// build add
//
void Tree_Builder::build_add_operator(void)
{
	Add_Node * node = new Add_Node();
	this->build(node);
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
//	get expression
//
Tree_Node * Tree_Builder::get_expression(void)
{
	return this->tree_;
}

//
// build 
//
void Tree_Builder::build(Tree_Node* node) 
{
	if (this->tree_ == nullptr)
	{
		this->tree_ = node;
		return;
	}
	this->set_first_empty_node(this->tree_, node);
}

//
//	set first empty node
//
bool Tree_Builder::set_first_empty_node(Binary_Operator_Node& root, Tree_Node& node)
{
	if (root.left_branch_ == nullptr)
	{
		root.left_branch_ = node;
		return true;
	}
	else if (root.right_branch_ == nullptr)
	{
		root.right_branch_ = node;
		return true;
	}
	return false
}