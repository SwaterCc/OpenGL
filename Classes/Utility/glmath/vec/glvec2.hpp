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
		// -- Ĭ�Ϲ��캯�� --
		constexpr glvec();
		//  -- ���캯�� --
		constexpr glvec(T a, T b);
		constexpr explicit glvec(T scalar);
		// -- ��������ת�� --
		template<typename U> 
		constexpr explicit glvec(U scalar);
		template<typename A, typename B>
		constexpr glvec(A a, B b);
		// --��γת��ά�������캯��--
		constexpr explicit glvec<2, T>(const glvec<3, T>& obj);
		constexpr explicit glvec<2, T>(const glvec<4, T>& obj);
		template<typename U>
		constexpr explicit glvec<2, T>(const glvec<3, U>& obj);
		template<typename U>
		constexpr explicit glvec<2, T>(const glvec<4, U>& obj);
		//  -- �������캯�� --
		constexpr glvec(const glvec& obj) = default;
		//  -- ��������� --
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
		//һ�·�������ѧ��δ����
	    glvec<2, T>& operator*=(const glvec& v1);
	    glvec<2, T>& operator/=(const glvec& v1);
	    glvec<2, T>& operator%=(const glvec& v1);


		glvec<2, T>& operator*(const glvec<3, T>& v) {}
		glvec<2, T>& operator/(const glvec<3, T>& v) {}
		glvec<2, T>& operator%(const glvec<3, T>& v) {}
	};
	//  -- ��������� --
	//  -- һԪ����� --
	template<typename T>
	glvec<2, T> operator+(const glvec<2, T>& v);
	template<typename T>
	glvec<2, T> operator-(const glvec<2, T>& v);
	//  --��������������--
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
	//  --�����������������--

	//  --��������������--
	template<typename T>
	glvec<2, T> operator+(const glvec<2, T>& v1, glvec<2, T> const& v2);
	template<typename T>
	glvec<2, T> operator-(const glvec<2, T>& v1, glvec<2, T> const& v2);
	// --���--
	template<typename T>
	T operator*(const glvec<2, T>& v1, glvec<2, T> const& v2);
	//  --�����������������--
}
#include"glvec2.inl"
#endif // !_glmath_vec_2_
