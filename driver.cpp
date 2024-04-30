#include <iostream>
#include <sstream>
#include <string>
#include "Number_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Modulo_Command.h"
#include "Stack.h"
#include "Stack_Command_Factory.h"
#include "Number_Node.h"
#include "Add_Node.h"
#include "Subtract_Node.h"
#include "Multiply_Node.h"
#include "Divide_Node.h"
#include "Modulo_Node.h"
#include "Postfix_Expr.h"
#include "Postfix_Builder.h"
#include "Tree_Builder.h"


/**
* Creates a postfix statement from an infix statement
* 
* @param	input				istringstream of infix expression
* @param	factory				factory used to create commands
* @param	postfix				array to store commands in postfix order
* @param	opened_parenthesis	boolean value showing if an open parenthesis must be closed
* @return	if valid infix equation was given 	
*/
bool infix_to_postfix(std::istringstream & input,
					  Postfix_Builder & b,
					  bool opened_parenthesis = false)
{
	std::string token;
	if (!opened_parenthesis)
		b.start_expression();
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
			bool did_run = infix_to_postfix(input, parenthesis_builder, true);
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
	if (!opened_parenthesis){
		// empty temp stack onto end of postfix array
		b.end_expression();

		return true;
	}
	// open parenthesis never closed
	return false;
}

///
///	Main
/// 
int main(int argc, char* argv[])
{
	
	// COMMENT The program is to loop until QUIT is entered.
	// RESPONSE: added loop with and check for QUIT to end.
	/*
	std::string infix;
	Stack<int> result = Stack<int>();
	Postfix_Builder build(result);
	Math_Expression * postfix = new Postfix_Expr(result);

	while (true) {
		// get user input into 'infix'
		infix = "";
		std::cout << "Type your equation" << std::endl;
		std::getline(std::cin, infix);
		
		// check if user is exiting program
		if (infix == "QUIT")
			return 0;

		// translate infix equation to postfix and solve if infix was valid
		std::istringstream input(infix);
		if (infix_to_postfix(input, build)) {
			// output result
			postfix = build.get_expression();
			postfix->print();
			std::cout << postfix->eval() << std::endl;
		}

		// if invalid infix expression, output error statement
		else
			std::cout << "Invalid equation" << std::endl;

		std::cout << std::endl;
	}
	*/

	Tree_Builder b = Tree_Builder();
	Math_Expression* tree = nullptr;

	b.build_add_operator();
	b.build_number(2);
	b.build_number(3);
	tree = b.get_expression();
	tree->print();
}