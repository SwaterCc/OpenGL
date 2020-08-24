#pragma once
#ifndef _glmath_vec_4_
#define _glmath_vec_4_
#include"../gl_math_template.h"

namespace glmath
{
	template <typename T> class glvec<4, T>
	{
	public:
		union { T  x, r, s; };
		union { T  y, g, t; };
		union { T  z, b, p; };
		union { T  w, a, q; };

		static length_t length() { return 4; }
	public:
		// -- 默认构造函数 --
		constexpr glvec();
		//  -- 构造函数 --
		constexpr glvec(T a, T b, T c, T d);
		constexpr glvec(const glvec<2, T>& v, T c, T d);
		constexpr glvec(const glvec<3, T>& v, T d);
		constexpr explicit glvec(T scalar);
		//  -- 拷贝构造函数 --
		constexpr glvec(const glvec& obj) = default;
		//  -- 重载运算符 --
		glvec<4, T>& operator=(const glvec& obj) = default;

		T & operator[](size_t i);
		T const & operator[](size_t i) const;

		glvec<4, T>& operator++();//++v
		glvec<4, T> operator++(int);//v++

		glvec<4, T>& operator--();//--v
		glvec<4, T> operator--(int);//v--

		glvec<4, T>& operator+=(const T& scalar);
		glvec<4, T>& operator+=(const glvec& v1);
				 
		glvec<4, T>& operator-=(const T& scalar);
		glvec<4, T>& operator-=(const glvec& v1);
				 
		glvec<4, T>& operator*=(const T& scalar);
		glvec<4, T>& operator/=(const T& scalar);
		glvec<4, T>& operator%=(const T& scalar);
	private:
		//一下方法在数学中未定义
		glvec<4, T>& operator*=(const glvec& v1);
		glvec<4, T>& operator/=(const glvec& v1);
		glvec<4, T>& operator%=(const glvec& v1);


		glvec<4, T>& operator*(const glvec<3, T>& v) {}
		glvec<4, T>& operator/(const glvec<3, T>& v) {}
		glvec<4, T>& operator%(const glvec<3, T>& v) {}
	};						 
	//  -- 重载运算符 --
	//  -- 一元运算符 --
	template<typename T>
	glvec<4, T> operator+(const glvec<4, T>& v);
	template<typename T>
	glvec<4, T> operator-(const glvec<4, T>& v);
	//  --标量与向量运算--
	template<typename T>
	glvec<4, T> operator+(T const& scalar, const glvec<4, T>& v2);
	template<typename T>
	glvec<4, T> operator-(T const& scalar, const glvec<4, T>& v2);
	template<typename T>
	glvec<4, T> operator-(const glvec<4, T>& v2, T const& scalar);
	template<typename T>
	glvec<4, T> operator*(T const& scalar, const glvec<4, T>& v2);
	template<typename T>
	glvec<4, T> operator/(T const& scalar, const glvec<4, T>& v2);
	template<typename T>
	glvec<4, T> operator%(T const& scalar, const glvec<4, T>& v2);
	//  --标量与向量运算结束--

	//  --向量与向量运算--
	template<typename T>										 
	glvec<4, T> operator+(const glvec<4, T>& v1, glvec<4, T> const& v2);
	template<typename T>										
	glvec<4, T> operator-(const glvec<4, T>& v1, glvec<4, T> const& v2);													
	// --点乘--
	template<typename T>
	T operator*(const glvec<4, T>& v1, glvec<4, T> const& v2);
	//  --向量与向量运算结束--
}
#include"glvec4.inl"
#endif // !_glmath_vec_4_
