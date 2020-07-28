#ifndef _Vector_Math_H_
#define _Vector_Math_H_
#include"../../Include/makeFileInclude.h"
#include<iostream>

GL_MATH_BEGIN

class Matirx4;

template <typename T>
class Vec3
{
public:
	Vec3(T a, T b, T c);
	static Matirx4 cross(Vec3 a, Vec3 b);
public:
	union { T x, r, s };
	union { T y, g, t };
	union { T z, b, p };

};


template<typename T>
inline Vec3<T>::Vec3(T a, T b, T c)
{

}

template<typename T>
inline Matirx4 Vec3<T>::cross(Vec3 a, Vec3 b)
{
	return Matrix4<T>();
}




GL_MATH_END

#endif // !_Vector_Math_H_
