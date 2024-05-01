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
	for (size_t i = 0; i < infix.length(); i++)
	{
		// set index = to the current string at the index
		index = infix[i];

		// if reached the end of a token then process token
		if (index == " " or i == infix.length() - 1) {
			if (pass_index != -1) 
			{
				switch (token.str()) {
					case "+":
						priority = 1;
						least_pri_index = i-1;
						least_pri_token = token.str();
					case "-":
						priority = 1;
						least_pri_index = i-1;
						least_pri_token = token.str();
					case "*":
						if (priority >= 2) {
							priority = 2;
							least_pri_index = i - 1;
							least_pri_token = token.str();
						}
					case "/":
						if (priority <= 2){
							priority = 2;
							least_pri_index = i - 1;
							least_pri_token = token.str();
						}
					case "%":
						if (priority <= 2) {
							priority = 2;
							least_pri_index = i - 1;
							least_pri_token = token.str();
						}
					case "(":
						pass_index = i-1;
					case ")":
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
		}
		// if not end of token then add to token
		else
			token << index;
	}
	// end of loop and have found operator with least priority
	// check that operator was found
	// if found then build operator and recursively call both sides of the operator
	if (priority != 0)
	{
		switch (least_pri_token) {
		case "+":
			this->builder_.build_add_operator();
			if (!this->parse(infix.substr(0, least_pri_index - 2))) { return false; }
			if (!this->parse(infix.substr(least_pri_index + 2, infix.length() - least_pri_index - 2))) { return false; }
		case "-":
			this->builder_.build_subtract_operator();
			if (!this->parse(infix.substr(0, least_pri_index - 2))) { return false; }
			if (!this->parse(infix.substr(least_pri_index + 2, infix.length() - least_pri_index - 2))) { return false; }
		case "*":
			this->builder_.build_multiply_operator();
			if (!this->parse(infix.substr(0, least_pri_index - 2))) { return false; }
			if (!this->parse(infix.substr(least_pri_index + 2, infix.length() - least_pri_index - 2))) { return false; }
		case "/":
			this->builder_.build_divide_operator();
			if (!this->parse(infix.substr(0, least_pri_index - 2))) { return false; }
			if (!this->parse(infix.substr(least_pri_index + 2, infix.length() - least_pri_index - 2))) { return false; }
		case "%":
			this->builder_.build_modulo_operator();
			if (!this->parse(infix.substr(0, least_pri_index - 2))) { return false; }
			if (!this->parse(infix.substr(least_pri_index + 2, infix.length() - least_pri_index - 2))) { return false; }
	}
	// else build a number node
	else
	{
		this->builder_.build_number(stoi(token.str()));
		return true;
	}
	return true;
}