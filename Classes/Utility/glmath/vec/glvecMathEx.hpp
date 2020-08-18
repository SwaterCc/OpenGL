#ifndef _gl_vec_math_
#define _gl_vec_math_
#include"../gl_math_template.h"

namespace glmath
{	
	// -- 叉乘 --
	template <typename T> constexpr glvec<3, T> cross(const glvec<3, T>& v1, const glvec<3, T>& v2)
	{
		return glvec<3, T>(
			v1.y * v2.z - v1.z * v2.y,
			v1.z * v2.x - v1.x * v2.z,
			v1.x * v2.y - v2.x * v1.y
			);
	}

	// -- 向量的模 --
	template <length_t len, typename T> constexpr T mod(const glvec<len, T>& v1)
	{
		T res = 0;
		for (size_t i = 0; i < len; i++)
		{
			res += pow(v1[i],2);
		}
		return sqrt(res);
	}
}



#endif // !_gl_vec_math_


