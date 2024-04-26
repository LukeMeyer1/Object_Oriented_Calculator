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
	std::cout << "start in post- ";
	std::string token;
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
			std::cout << "op paren build start- ";
			Postfix_Builder parenthesis_builder(b);
			std::cout << "op paren built- ";
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

				std::cout << "start close paren- ";
				b.end_expression();
				std::cout << "close paren fin- ";
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

	std::string infix;
	Stack<int> result = Stack<int>();
	std::cout << "result built- ";
	Postfix_Builder build(result);
	std::cout << "build built- ";
	Postfix_Expr postfix(result);
	std::cout << "post built- ";
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
			postfix = build.postfix();
			postfix.print();
			std::cout << postfix.eval() << std::endl;
		}
		// if invalid infix expression, output error statement
		else
			std::cout << "Invalid equation" << std::endl;

		std::cout << std::endl;
	}






	//Number_Node * n1 = new Number_Node(4);
	//Tree_Node * n2 = new Number_Node(2);
	//Add_Node * n3 = new Add_Node(n1, n2);
	//Tree_Node * n4 = new Subtract_Node(new Number_Node(4), new Number_Node(2));
	//Tree_Node * n5 = new Multiply_Node(new Number_Node(4), new Number_Node(2));
	//Tree_Node * n6 = new Divide_Node(new Number_Node(4), new Number_Node(2));
	//Tree_Node * n7 = new Modulo_Node(new Number_Node(4), new Number_Node(3));

	//delete n3;
	//delete n4;
	//delete n5;
	//delete n6;
	//delete n7;
}