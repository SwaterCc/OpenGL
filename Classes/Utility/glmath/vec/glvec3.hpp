#ifndef _glmath_vec_3_
#define _glmath_vec_3_
#include"../gl_math_template.h"

namespace glmath
{
	template <typename T> class glvec<3, T>
	{
	public:
		union { T  x, r, s; };
		union { T  y, g, t; };
		union { T  z, b, p; };

		static length_t length() { return 3; }
	public:
		// -- Ĭ�Ϲ��캯�� --
		constexpr glvec();
		//  -- ���캯�� --
		constexpr glvec(T a, T b, T c);
		constexpr glvec(const glvec<2, T>& v, T c);
		constexpr glvec(T c, const glvec<2, T>& v);
		constexpr explicit glvec(T scalar);
		//  -- �������캯�� --
		constexpr glvec(const glvec& obj) = default;
		//  -- ��������� --
		glvec<3, T>& operator=(const glvec<3, T>& obj) = default;
		
		T & operator[](size_t i);
		T const & operator[](size_t i) const;

		glvec<3, T>& operator++();//++v
		glvec<3, T> operator++(int);//v++
		
		glvec<3, T>& operator--();//--v
		glvec<3, T> operator--(int);//v--
		
		glvec<3, T>& operator+=(const T& scalar);
		glvec<3, T>& operator+=(const glvec& v1);
				
		glvec<3, T>& operator-=(const T& scalar);
		glvec<3, T>& operator-=(const glvec& v1);
				 
		glvec<3, T>& operator*=(const T& scalar);
		glvec<3, T>& operator/=(const T& scalar);
		glvec<3, T>& operator%=(const T& scalar);
	private:
		//һ�·�������ѧ��δ����
		glvec<3, T>& operator*=(const glvec& v1);
		glvec<3, T>& operator/=(const glvec& v1);
		glvec<3, T>& operator%=(const glvec& v1);

		
		glvec<3, T>& operator*(const glvec<3, T>& v) {}
		glvec<3, T>& operator/(const glvec<3, T>& v) {}
		glvec<3, T>& operator%(const glvec<3, T>& v) {}
	};
	//  -- һԪ����� --
	template<typename T>
	glvec<3, T> operator+(const glvec<3, T>& v);
	template<typename T>
	glvec<3, T> operator-(const glvec<3, T>& v);
	//  -- ��������� --
	template<typename T>
	glvec<3, T> operator+(T const& scalar , const glvec<3,T> & v2);
	template<typename T>
	glvec<3, T> operator+(const glvec<3, T>& v1, glvec<3, T> const& v2);

	template<typename T>
	glvec<3, T> operator-(T const& scalar, const glvec<3, T>& v2);
	template<typename T>
	glvec<3, T> operator-(const glvec<3, T>& v1, T const& scalar);
	template<typename T>
	glvec<3, T> operator-(const glvec<3, T>& v1, glvec<3, T> const& v2);
	
	template<typename T>
	glvec<3, T> operator*(T const& scalar, const glvec<3, T>& v2);
	
	// --���--
	template<typename T>
	T operator*(const glvec<3, T>& v1, glvec<3, T> const& v2);

	template<typename T>
	glvec<3, T> operator/(T const& scalar, const glvec<3, T>& v2);
	template<typename T>
	glvec<3, T> operator%(T const& scalar, const glvec<3, T>& v2);
}
#include"glvec3.inl"
#endif // !_glmath_vec_3_
