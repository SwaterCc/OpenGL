#ifndef _glmath_namespace_
#define _glmath_namespace_

#include<iostream>
#include<cmath>
#include<cassert>

namespace glmath
{
	typedef unsigned int length_t;

	template<length_t len, typename T> class glvec;
	template<length_t line, length_t row, typename T> class glmatrix;
}



#endif // !_glmath_namespace_

