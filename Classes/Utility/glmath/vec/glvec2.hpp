#pragma once
#ifndef _glmath_vec_2_
#define _glmath_vec_2_
#include"../gl_math_template.hpp"

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

		// --高纬转低维拷贝构造函数--
		constexpr glvec<2, T>(const glvec<3, T>& obj);
		constexpr glvec<2, T>(const glvec<4, T>& obj);
		//  -- 拷贝构造函数 --
		constexpr glvec(const glvec& obj) = default;
		//  -- 重载运算符 --
		constexpr glvec<2, T>& operator=(const glvec& obj) = default;

		constexpr T& operator[](const size_t i);

		constexpr glvec<2, T>& operator++();//++v
		constexpr glvec<2, T> operator++(int);//v++

		constexpr glvec<2, T>& operator--();//--v
		constexpr glvec<2, T> operator--(int);//v--

		constexpr glvec<2, T>& operator+=(const T& scalar);
		constexpr glvec<2, T>& operator+=(const glvec& v1);
							 
		constexpr glvec<2, T>& operator-=(const T& scalar);
		constexpr glvec<2, T>& operator-=(const glvec& v1);
							 
		constexpr glvec<2, T>& operator*=(const T& scalar);
		constexpr glvec<2, T>& operator/=(const T& scalar);
		constexpr glvec<2, T>& operator%=(const T& scalar);
	private:
		//一下方法在数学中未定义
		constexpr glvec<2, T>& operator*=(const glvec& v1);
		constexpr glvec<2, T>& operator/=(const glvec& v1);
		constexpr glvec<2, T>& operator%=(const glvec& v1);


		constexpr glvec<2, T>& operator*(const glvec<3, T>& v) {}
		constexpr glvec<2, T>& operator/(const glvec<3, T>& v) {}
		constexpr glvec<2, T>& operator%(const glvec<3, T>& v) {}
	};
	//  -- 重载运算符 --
	//  -- 一元运算符 --
	template<typename T>
	constexpr glvec<2, T> operator+(const glvec<2, T>& v);
	template<typename T>
	constexpr glvec<2, T> operator-(const glvec<2, T>& v);
	//  --标量与向量运算--
	template<typename T>
	constexpr glvec<2, T> operator+(T const& scalar, const glvec<2, T>& v2);
	template<typename T>
	constexpr glvec<2, T> operator-(T const& scalar, const glvec<2, T>& v2);
	template<typename T>
	constexpr glvec<2, T> operator-(const glvec<2, T>& v2, T const& scalar);
	template<typename T>
	constexpr glvec<2, T> operator*(T const& scalar, const glvec<2, T>& v2);
	template<typename T>
	constexpr glvec<2, T> operator/(T const& scalar, const glvec<2, T>& v2);
	template<typename T>
	constexpr glvec<2, T> operator%(T const& scalar, const glvec<2, T>& v2);
	//  --标量与向量运算结束--

	//  --向量与向量运算--
	template<typename T>
	constexpr glvec<2, T> operator+(const glvec<2, T>& v1, glvec<2, T> const& v2);
	template<typename T>
	constexpr glvec<2, T> operator-(const glvec<2, T>& v1, glvec<2, T> const& v2);
	// --点乘--
	template<typename T>
	constexpr T operator*(const glvec<2, T>& v1, glvec<2, T> const& v2);
	//  --向量与向量运算结束--
}
#include"glvec2.inl"
#endif // !_glmath_vec_2_
