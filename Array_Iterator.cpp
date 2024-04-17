// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Array_Iterator.h"


//
// Array_Iterator
//
Array_Iterator::Array_Iterator (Array<Command*> & a) 
	:a_ (a),
	curr_ (0)
{ }

//
// ~Array_Iterator
//
Array_Iterator::~Array_Iterator (void)
{ }

//
// is_done
//
bool Array_Iterator::is_done(void)
{
	return this->curr_ >= this->a_.cur_size_;
}

//
// advance
//
void Array_Iterator::advance(void)
{
	++this->curr_;
}

//
// operator *
//
Command& Array_Iterator::operator * (void)
{
	return this->a.data_[this->curr_];
}

//
// operator ->
//
Command* Array_Iterator::operator -> (void)
{
	return &this->a_.data_[this->curr_];
}