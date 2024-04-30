// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Postfix_Parser.h"

//
// Postfix_Parser
//
Postfix_Parser::Postfix_Parser(Postfix_Builder& builder)
	:builder_(builder)
{ }

//
// ~Postfix_Parser
//
Postfix_Parser::~Postfix_Parser(void)
{ }

//
// parse
//
bool Postfix_Parser::parse(const std::string & infix)
{
	std::istringstream input(infix);
	return this->parse_equation(input, this->builder_, false);
}

//
// parse equation
//
bool Postfix_Parser::parse_equation(std::istringstream& input,
									Postfix_Builder& b,
									bool opened_parenthesis)
{
	std::string token;
	if (!opened_parenthesis)
		this->builder_.start_expression();
	while (!input.eof()) {

		input >> token;

		// Plus operator
		if (token == "+") {
			b.build_add_operator();
		}
		// Minus operator
		else if (token == "-") {
			b.build_subtract_operator();
		}
		// Multiply operator
		else if (token == "*") {
			b.build_multiply_operator();
		}
		// Divide operator
		else if (token == "/") {
			b.build_divide_operator();
		}
		// Modulo operator
		else if (token == "%") {
			b.build_modulo_operator();
		}

		// Open parenthesis operator
		else if (token == "(") {
			// recursive call, will put all new postfix onto the same postfix equation until reaching a close parenthesis
			// or the end of the statement
			Postfix_Builder parenthesis_builder(b);
			bool did_run = this->parse_equation(input, parenthesis_builder, true);
			if (!did_run)
				return false;
		}
		// Close parenthesis operator
		else if (token == ")") {
			// if called with opened parenthesis then push all commands onto the postfix and return 'true' because it is 
			// closed, else return false because there is a closed parenthesis without an open.
			if (opened_parenthesis) {
				// empty temp stack onto end of postfix array

				b.end_expression();
				return true;
			}
			return false;
		}
		// Number operator
		else {
			// add number command directly to end of postfix array
			b.build_number(std::stoi(token));
		}
	}
	// reached end of input

	// check if opened parenthesis 
	if (!opened_parenthesis) {
		// empty temp stack onto end of postfix array
		b.end_expression();

		return true;
	}
	// open parenthesis never closed
	return false;
}