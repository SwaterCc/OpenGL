#pragma once
#ifndef _glmath_vec_4_
#define _glmath_vec_4_
#include"../gl_math_template.hpp"

namespace glmath
{
	template <typename T> class glvec<4, T>
	{
	public:
		union { T  x, r, s };
		union { T  y, g, t };
		union { T  z, b, p };
		union { T  w, a, q };

		static length_t length() { return 4; }
	public:
		// -- Ĭ�Ϲ��캯�� --
		constexpr glvec();
		//  -- ���캯�� --
		constexpr glvec(T a, T b, T c, T d);
		constexpr glvec(const glvec<2, T>& v, T c, T d);
		constexpr glvec(const glvec<3, T>& v, T d);
		constexpr explicit glvec(T scalar);
		//  -- �������캯�� --
		constexpr glvec(const glvec& obj) = default;
		//  -- ��������� --
		constexpr glvec<4, T> operator=(const glvec& obj) = default;

		constexpr T& operator[](const size_t i);

		constexpr glvec<4, T>& operator++();//++v
		constexpr glvec<4, T> operator++(int);//v++

		constexpr glvec<4, T>& operator--();//--v
		constexpr glvec<4, T> operator--(int);//v--

		constexpr glvec<4, T>& operator+=(const T& scalar);
		constexpr glvec<4, T>& operator+=(const glvec& v1);
							 
		constexpr glvec<4, T>& operator-=(const T& scalar);
		constexpr glvec<4, T>& operator-=(const glvec& v1);
							 
		constexpr glvec<4, T>& operator*=(const T& scalar);
		constexpr glvec<4, T>& operator/=(const T& scalar);
		constexpr glvec<4, T>& operator%=(const T& scalar);
	private:
		//һ�·�������ѧ��δ����
		constexpr glvec<4, T>& operator*=(const glvec& v1);
		constexpr glvec<4, T>& operator/=(const glvec& v1);
		constexpr glvec<4, T>& operator%=(const glvec& v1);


		constexpr glvec<4, T>& operator*(const glvec<3, T>& v) {}
		constexpr glvec<4, T>& operator/(const glvec<3, T>& v) {}
		constexpr glvec<4, T>& operator%(const glvec<3, T>& v) {}
	};						 
	//  -- ��������� --
	//  -- һԪ����� --
	template<typename T>
	constexpr glvec<4, T> operator+(const glvec<4, T>& v);
	template<typename T>
	constexpr glvec<4, T> operator-(const glvec<4, T>& v);
	//  --��������������--
	template<typename T>
	constexpr glvec<4, T> operator+(T const& scalar, const glvec<4, T>& v2);
	template<typename T>
	constexpr glvec<4, T> operator-(T const& scalar, const glvec<4, T>& v2);
	template<typename T>
	constexpr glvec<4, T> operator-(const glvec<4, T>& v2, T const& scalar);
	template<typename T>
	constexpr glvec<4, T> operator*(T const& scalar, const glvec<4, T>& v2);
	template<typename T>
	constexpr glvec<4, T> operator/(T const& scalar, const glvec<4, T>& v2);
	template<typename T>
	constexpr glvec<4, T> operator%(T const& scalar, const glvec<4, T>& v2);
	//  --�����������������--

	//  --��������������--
	template<typename T>										 
	constexpr glvec<4, T> operator+(const glvec<4, T>& v1, glvec<4, T> const& v2);
	template<typename T>										
	constexpr glvec<4, T> operator-(const glvec<4, T>& v1, glvec<4, T> const& v2);													
	// --���--
	template<typename T>
	constexpr T operator*(const glvec<4, T>& v1, glvec<4, T> const& v2);
	//  --�����������������--
}

#endif // !_glmath_vec_4_
