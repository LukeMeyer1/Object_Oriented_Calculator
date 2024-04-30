// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _CS507_FIXED_ARRAY_H_
#define _CS507_FIXED_ARRAY_H_

#include "Base_Array.h"

/**
 * @class Fixed_Array
 *
 * Implementation of a fixed size array, i.e., one that is not
 * resizeable. It is derived from Array so it can inherit of 
 * the Array class's methods.
 */
template <typename T, size_t N>
class Fixed_Array : public Base_Array <T>
{
public:
  /// Default consstructor
	Fixed_Array(void);

	/**
	 * Initializing constructor.
	 *
	 * @param[in]      fill          Initial value for each element
	 */
	Fixed_Array(T fill);

	/**
	 * Copy constructor
	 *
	 * @param[in]     arr         The source array.
	 */
	Fixed_Array(const Fixed_Array& arr);

  /// Destructor.
  ~Fixed_Array (void);

  /**
   * Assignment operation
   *
   * @param[in]       rhs      Right-hand side of equal sign
   * @return          Reference to self
   */
  const Fixed_Array<T,N>& operator = (const Fixed_Array& rhs);
  
  /**
   * Get the character at the specified index. If the index is not
   * within the range of the array, then std::out_of_range exception
   * is thrown.
   *
   * @param[in]       index               Zero-based location
   * @exception       std::out_of_range   Invalid \a index value
   */
  T& operator [] (size_t index);

  /**
   * @overload
   *
   * The returned character is not modifiable.
   */
  const T& operator [] (size_t index) const;
  
  /**
   * Test the array for equality.
   *
   * @param[in]       rhs                  Right hand side of equal to sign
   * @retval          true                 Left side is equal to right side
   * @retval          false                Left side is not equal to right side
   */
  bool operator == (const Fixed_Array& rhs) const;

  /**
   * Test the array for inequality.
   *
   * @param[in]       rhs                  Right-hand size of not equal to sign
   * @retval          true                 Left side is not equal to right side
   * @retval          false                Left size is equal to right side
   */
  bool operator != (const Fixed_Array& rhs) const;
};

// include the inline files
#include "Fixed_Array.inl"

// include the source file since template class
#include "Fixed_Array.cpp"

#endif  // !defined _CS507_FIXED_ARRAY_H_


