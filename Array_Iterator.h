// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _ARRAY_ITERATOR_H_
#define _ARRAY_ITERATOR_H_

#include "Array.h"
#include "Command.h"

/**
* @class Array_Iterator
*
* Iterator of the Array class
*/
class Array_Iterator 
{
public:

	/**
	* Initializing constructor.
	*
	* @param[in]	a		Array object being iterated through
	*/
	Array_Iterator (Array<Command *> & a);

	/// Destructor
	~Array_Iterator (void);

	/// returns true if the iterator has reached the end of the array
	bool is_done(void);

	/// sets the location of the iterator to the next position in the array
	void advance(void);

	/// Get the value of the iterator
	Command& operator * (void);

	/// Get the value of the position of the iterator
	Command* operator -> (void);

private:
	Array <Command *>& a_;
	size_t curr_;
};

#include "Array_Iterator.cpp"

#endif   // !defined _ARRAY_ITERATOR_H_