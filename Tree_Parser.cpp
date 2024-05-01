// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Tree_Parser.h"
#include <sstream>
#include <string>

//
// Tree_Parser
//
Tree_Parser::Tree_Parser(Tree_Builder& builder)
	: builder_(builder)
{ }

//
// ~Tree_Parser
//
Tree_Parser::~Tree_Parser(void)
{ }

//
// parse equation
//
bool Tree_Parser::parse(const std::string & infix)
{
	std::stringstream token;
	std::string index;
	int priority = 0;
	int least_pri_index = 0;
	int pass_index = -1;
	std::string least_pri_token = "";
	std::cout << "loop start: " << infix << std::endl;
	for (size_t i = 0; i < infix.length(); i++)
	{
		// set index = to the current string at the index
		index = infix[i];

		// if reached the end of a token then process token
		if (index == " " or i == infix.length() - 1) {
			std::cout << "token found: " << token.str() << std::endl;
			if (pass_index = -1) 
			{
				if (token.str() == "+") {
					priority = 1;
					least_pri_index = i - 1;
					least_pri_token = token.str();
				}
				if (token.str() == "-") {
					priority = 1;
					least_pri_index = i - 1;
					least_pri_token = token.str();
				}
				if (token.str() == "*") {
					if (priority >= 2) {
						priority = 2;
						least_pri_index = i - 1;
						least_pri_token = token.str();
					}
				}
				if (token.str() == "/") {
					if (priority <= 2) {
						priority = 2;
						least_pri_index = i - 1;
						least_pri_token = token.str();
					}
				}
				if (token.str() == "%") {
					if (priority <= 2) {
						priority = 2;
						least_pri_index = i - 1;
						least_pri_token = token.str();
					}
				}
				if (token.str() == "(") {
					pass_index = i - 1;
				}
				if (token.str() == ")") {
					return false;

				}
			}
			// if pass_index is at an index then search for the closing parenthesis and once found then check that parenthesis don't encapsulate the entire statement
			else {
				if (token.str() == ")") {
					if (pass_index == 0 and i == infix.length() - 1) {
						//recursive without the parenthesis
						return this->parse(infix.substr(2, i - 4)); 
					}
					pass_index = -1;
				}
			}
			//clear token
			token.str(std::string());
		}
		// if not end of token then add to token
		else
			token << index;
	}
	std::cout << "loop exit: ";
	std::cout << infix << std::endl;
	// end of loop and have found operator with least priority
	// check that operator was found
	// if found then build operator and recursively call both sides of the operator
	if (priority != 0)
	{
		std::cout << "enter priority > 0" << std::endl;
		if (least_pri_token == "+") {
			std::cout << "+ operator started" << std::endl;
			this->builder_.build_add_operator();
			std::cout << "+ operator built" << std::endl;
			std::cout << "left ( 0 , "<< least_pri_index - 1 << " ): " << infix.substr(0, least_pri_index - 1) << std::endl;
			if (!this->parse(infix.substr(0, least_pri_index - 1))) { return false; }
			std::cout << "parse left finished: " << std::endl;
			std::cout << "right ( " << least_pri_index + 2 << " , " << infix.length() - least_pri_index - 2 << " ): " << infix.substr(least_pri_index + 2, infix.length() - least_pri_index - 2) << std::endl;
			if (!this->parse(infix.substr(least_pri_index + 2, infix.length() - least_pri_index - 2))) { return false; }
			std::cout << "parse right finished: " << std::endl;
		}
		if (least_pri_token == "-") {
			this->builder_.build_subtract_operator();
			if (!this->parse(infix.substr(0, least_pri_index - 2))) { return false; }
			if (!this->parse(infix.substr(least_pri_index + 2, infix.length() - least_pri_index - 2))) { return false; }
		}
		if (least_pri_token == "*") {
			this->builder_.build_multiply_operator();
			if (!this->parse(infix.substr(0, least_pri_index - 2))) { return false; }
			if (!this->parse(infix.substr(least_pri_index + 2, infix.length() - least_pri_index - 2))) { return false; }
		}
		if (least_pri_token == "/") {
			this->builder_.build_divide_operator();
			if (!this->parse(infix.substr(0, least_pri_index - 2))) { return false; }
			if (!this->parse(infix.substr(least_pri_index + 2, infix.length() - least_pri_index - 2))) { return false; }
		}
		if (least_pri_token == "%") {
			this->builder_.build_modulo_operator();
			if (!this->parse(infix.substr(0, least_pri_index - 2))) { return false; }
			if (!this->parse(infix.substr(least_pri_index + 2, infix.length() - least_pri_index - 2))) { return false; }
		}
	}
	// else build a number node
	else
	{
		std::cout << "enter number create" << std::endl;
		this->builder_.build_number(stoi(infix));
		std::cout << "print in number" << std::endl;
		this->builder_.get_expression()->print();
		return true;
	}
	std::cout << "print in parser" << std::endl;
	this->builder_.get_expression()->print();
	return true;
}