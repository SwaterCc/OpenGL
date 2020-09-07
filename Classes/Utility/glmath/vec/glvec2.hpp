#pragma once
#ifndef _glmath_vec_2_
#define _glmath_vec_2_
#include"../gl_math_template.h"

namespace glmath
{
	template <typename T> class glvec<2, T>
	{
	public:
		union { T  x, r, s; };
		union { T  y, g, t; };

		static length_t length() { return 2; }
	public:
		// -- 默认构造函数 --
		constexpr glvec();
		//  -- 构造函数 --
		constexpr glvec(T a, T b);
		constexpr explicit glvec(T scalar);
		// -- 传入类型转换 --
		template<typename U> 
		constexpr explicit glvec(U scalar);
		template<typename A, typename B>
		constexpr glvec(A a, B b);
		// --高纬转低维拷贝构造函数--
		constexpr explicit glvec<2, T>(const glvec<3, T>& obj);
		constexpr explicit glvec<2, T>(const glvec<4, T>& obj);
		template<typename U>
		constexpr explicit glvec<2, T>(const glvec<3, U>& obj);
		template<typename U>
		constexpr explicit glvec<2, T>(const glvec<4, U>& obj);
		//  -- 拷贝构造函数 --
		constexpr glvec(const glvec& obj) = default;
		//  -- 重载运算符 --
		glvec<2, T>& operator=(const glvec<2, T>& obj) = default;

		T & operator[](size_t i);
		T const & operator[](size_t i) const;

		glvec<2, T>& operator++();//++v
		glvec<2, T> operator++(int);//v++

		glvec<2, T>& operator--();//--v
		glvec<2, T> operator--(int);//v--

		glvec<2, T>& operator+=(const T& scalar);
		glvec<2, T>& operator+=(const glvec& v1);
					 
		glvec<2, T>& operator-=(const T& scalar);
		glvec<2, T>& operator-=(const glvec& v1);
					 
		glvec<2, T>& operator*=(const T& scalar);
		glvec<2, T>& operator/=(const T& scalar);
		glvec<2, T>& operator%=(const T& scalar);
	private:
		//一下方法在数学中未定义
	    glvec<2, T>& operator*=(const glvec& v1);
	    glvec<2, T>& operator/=(const glvec& v1);
	    glvec<2, T>& operator%=(const glvec& v1);


		glvec<2, T>& operator*(const glvec<3, T>& v) {}
		glvec<2, T>& operator/(const glvec<3, T>& v) {}
		glvec<2, T>& operator%(const glvec<3, T>& v) {}
	};
	//  -- 重载运算符 --
	//  -- 一元运算符 --
	template<typename T>
	glvec<2, T> operator+(const glvec<2, T>& v);
	template<typename T>
	glvec<2, T> operator-(const glvec<2, T>& v);
	//  --标量与向量运算--
	template<typename T>
	glvec<2, T> operator+(T const& scalar, const glvec<2, T>& v2);
	template<typename T>
	glvec<2, T> operator-(T const& scalar, const glvec<2, T>& v2);
	template<typename T>
	glvec<2, T> operator-(const glvec<2, T>& v2, T const& scalar);
	template<typename T>
	glvec<2, T> operator*(T const& scalar, const glvec<2, T>& v2);
	template<typename T>
	glvec<2, T> operator/(T const& scalar, const glvec<2, T>& v2);
	template<typename T>
	glvec<2, T> operator%(T const& scalar, const glvec<2, T>& v2);
	//  --标量与向量运算结束--

	//  --向量与向量运算--
	template<typename T>
	glvec<2, T> operator+(const glvec<2, T>& v1, glvec<2, T> const& v2);
	template<typename T>
	glvec<2, T> operator-(const glvec<2, T>& v1, glvec<2, T> const& v2);
	// --点乘--
	template<typename T>
	T operator*(const glvec<2, T>& v1, glvec<2, T> const& v2);
	//  --向量与向量运算结束--
}
#include"glvec2.inl"
#endif // !_glmath_vec_2_
