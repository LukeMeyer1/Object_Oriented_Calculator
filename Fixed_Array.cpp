// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.


//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array<T, N>::Fixed_Array(void)
{ 
	this->data_ = new T[N];
	this->cur_size_ = N;
	this->max_size_ = N;
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array<T,N>::Fixed_Array(T fill)
	:Fixed_Array<T,N>()
{ 
	this->fill(fill);
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array<T, N>::Fixed_Array(const Fixed_Array<T,N>& arr)
	:Fixed_Array<T,N>()
{ 
	*this = arr;
}
	
//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array(void)
{ }

//
// operator =
//
template <typename T, size_t N>
const Fixed_Array<T, N>& Fixed_Array<T, N>::operator = (const Fixed_Array& rhs)
{

	// Check that rhs isn't the same location in memory as the array
	if (this == &rhs)
		return *this;

	// Set array values equal to respective rhs array values
	for (T* iter = this->data_, *iter_end = this->data_ + this->cur_size_, *rhs_iter = rhs.data_;
		iter != iter_end;
		++iter, ++rhs_iter)
	{
		*iter = *rhs_iter;
	}

	return *this;
}

///
/// operator []
/// 
template <typename T, size_t N>
T& Fixed_Array<T, N>::operator [] (size_t index)
{
	return Base_Array<T>::operator[](index);
}

///
/// operator []
/// 
template <typename T, size_t N>
const T& Fixed_Array<T, N>::operator [] (size_t index) const
{
	return Base_Array<T>::operator[](index);
}

//
//operator ==
//
template <typename T, size_t N>
bool Fixed_Array<T, N>::operator == (const Fixed_Array& rhs) const
{
	return Base_Array<T>::operator==(rhs);
}
///
/// operator !=
/// 
template <typename T, size_t N>
bool Fixed_Array<T, N>::operator != (const Fixed_Array& rhs) const
{
	return !(*this == rhs);
}
