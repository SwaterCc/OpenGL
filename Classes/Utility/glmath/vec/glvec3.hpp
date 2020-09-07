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
		// -- 默认构造函数 --
		constexpr glvec();
		//  -- 构造函数 --
		constexpr glvec(T a, T b, T c);
		constexpr explicit glvec(T scalar);
		// -- 传入类型转换 --
		template<typename U>
		constexpr explicit glvec(U scalar);
		template<typename A, typename B, typename C>
		constexpr glvec(A a, B b, C c);
		//	-- 低维转高维 --
		constexpr glvec(const glvec<2, T>& v, T c);
		constexpr glvec(T c, const glvec<2, T>& v);
		template<typename A, typename B>
		constexpr glvec(const glvec<2, A>& v, B c);
		template<typename A, typename B>
		constexpr glvec(A c, const glvec<2, B>& v);
		// -- 高纬转低维拷贝构造函数 --
		constexpr explicit glvec<3, T>(const glvec<4, T>& obj);
		template<typename U>
		constexpr explicit glvec<3, T>(const glvec<4, U>& obj);
		//  -- 拷贝构造函数 --
		constexpr glvec(const glvec& obj) = default;
		//  -- 重载运算符 --
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
		//一下方法在数学中未定义
		glvec<3, T>& operator*=(const glvec& v1);
		glvec<3, T>& operator/=(const glvec& v1);
		glvec<3, T>& operator%=(const glvec& v1);

		
		glvec<3, T>& operator*(const glvec<3, T>& v) {}
		glvec<3, T>& operator/(const glvec<3, T>& v) {}
		glvec<3, T>& operator%(const glvec<3, T>& v) {}
	};
	//  -- 一元运算符 --
	template<typename T>
	glvec<3, T> operator+(const glvec<3, T>& v);
	template<typename T>
	glvec<3, T> operator-(const glvec<3, T>& v);
	//  -- 重载运算符 --
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
	
	// --点乘--
	template<typename T>
	T operator*(const glvec<3, T>& v1, glvec<3, T> const& v2);

	template<typename T>
	glvec<3, T> operator/(T const& scalar, const glvec<3, T>& v2);
	template<typename T>
	glvec<3, T> operator%(T const& scalar, const glvec<3, T>& v2);
}
#include"glvec3.inl"
#endif // !_glmath_vec_3_
