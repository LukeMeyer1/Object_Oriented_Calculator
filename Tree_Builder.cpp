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
{}

//
// build add
//
void Tree_Builder::build_add_operator(void)
{}

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