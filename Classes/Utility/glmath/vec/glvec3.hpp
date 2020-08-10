#ifndef _glmath_vec_3_
#define _glmath_vec_3_
#include"../glmath.hpp"

namespace glmath
{
	template <typename T> class glvec<3, T>
	{
	public:
		union { T  x, r, s };
		union { T  y, g, t };
		union { T  z, b, p };

		static length_t length() { return 3; }
	public:
		// -- 默认构造函数 --
		constexpr glvec();
		//  -- 构造函数 --
		constexpr glvec(T a, T b, T c);
		constexpr glvec(const glvec<2, T>& v, T c);
		constexpr glvec(T c, const glvec<2, T>& v);
		constexpr explicit glvec(T scalar);
		//  -- 拷贝构造函数 --
		constexpr glvec(const glvec& obj) = default;
		//

		//  -- 重载运算符 --
		constexpr glvec<3, T>& operator=(const glvec& obj) = default;
		
		constexpr T& operator[](const size_t i);
		
		constexpr glvec<3, T>& operator++();//++v
		constexpr glvec<3, T> operator++(int);//v++

		constexpr glvec<3, T>& operator--();//--v
		constexpr glvec<3, T> operator--(int);//v--

		constexpr glvec<3, T>& operator+=(const T& scalar);
		constexpr glvec<3, T>& operator+=(const glvec& v1);
							
		constexpr glvec<3, T>& operator-=(const T& scalar);
		constexpr glvec<3, T>& operator-=(const glvec& v1);
							 
		constexpr glvec<3, T>& operator*=(const T& scalar);
		constexpr glvec<3, T>& operator/=(const T& scalar);
		constexpr glvec<3, T>& operator%=(const T& scalar);
	private:
		//一下方法在数学中未定义
		constexpr glvec<3, T>& operator*=(const glvec& v1);
		constexpr glvec<3, T>& operator/=(const glvec& v1);
		constexpr glvec<3, T>& operator%=(const glvec& v1);

		
		constexpr glvec<3, T>& operator*(const glvec<3, T>& v) {}
		constexpr glvec<3, T>& operator/(const glvec<3, T>& v) {}
		constexpr glvec<3, T>& operator%(const glvec<3, T>& v) {}
	};
	//  -- 一元运算符 --
	template<typename T>
	constexpr glvec<3, T> operator+(const glvec<3, T>& v);
	template<typename T>
	constexpr glvec<3, T> operator-(const glvec<3, T>& v);
	//  -- 重载运算符 --
	template<typename T>
	constexpr glvec<3, T> operator+(T const& scalar , const glvec<3,T> & v2);
	template<typename T>
	constexpr glvec<3, T> operator+(const glvec<3, T>& v1, glvec<3, T> const& v2);

	template<typename T>
	constexpr glvec<3, T> operator-(T const& scalar, const glvec<3, T>& v2);
	template<typename T>
	constexpr glvec<3, T> operator-(const glvec<3, T>& v1, T const& scalar);
	template<typename T>
	constexpr glvec<3, T> operator-(const glvec<3, T>& v1, glvec<3, T> const& v2);
	
	template<typename T>
	constexpr glvec<3, T> operator*(T const& scalar, const glvec<3, T>& v2);
	
	// --点乘--
	template<typename T>
	constexpr T operator*(const glvec<3, T>& v1, glvec<3, T> const& v2);

	template<typename T>
	constexpr glvec<3, T> operator/(T const& scalar, const glvec<3, T>& v2);
	template<typename T>
	constexpr glvec<3, T> operator%(T const& scalar, const glvec<3, T>& v2);
}

#endif // !_glmath_vec_3_
