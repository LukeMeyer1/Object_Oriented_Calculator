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
#include "Calculator.h"


/**
* Creates a postfix statement from an infix statement
* 
* @param	input				istringstream of infix expression
* @param	factory				factory used to create commands
* @param	postfix				array to store commands in postfix order
* @param	opened_parenthesis	boolean value showing if an open parenthesis must be closed
* @return	if valid infix equation was given 	

bool infix_to_postfix(std::istringstream & input,
					  Postfix_Builder & b,
					  bool opened_parenthesis = false)
{
}*/

///
///	Main
/// 
int main(int argc, char* argv[])
{
	
	// COMMENT The program is to loop until QUIT is entered.
	// RESPONSE: added loop with and check for QUIT to end.
	
	std::string infix;
	Stack<int> result = Stack<int>();
	Postfix_Builder * build = new Postfix_Builder(result);
	Calculator calc(build);


	while (true) {
		// get user input into 'infix'
		infix = "";
		std::cout << "Type your equation" << std::endl;
		std::getline(std::cin, infix);
		
		// check if user is exiting program
		if (infix == "QUIT")
			return 0;

		// solve equation and print it out
		std::cout << calc.evaluate(infix) << std::endl;
	}
	
	delete build;
/*
	Tree_Builder b = Tree_Builder();
	Math_Expression* tree = nullptr;

	b.build_add_operator();
	b.build_number(2);
	b.build_number(3);
	tree = b.get_expression();
	tree->print();
*/
}