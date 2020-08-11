#ifndef _Matrix3x3_
#define _Matrix3x3_
#include"../gl_math_template.hpp"
namespace glmath {
	template<typename T>
	class glmatrix<3,3,T> 
	{
		typedef glvec<3, T> col_type;
		typedef glvec<3, T> row_type;
	public:
		// -- 构造函数 --
		constexpr glmatrix();
		constexpr glmatrix(T scaler);
		constexpr glmatrix(glvec<3, T>& a, glvec<3, T>& b, glvec<3, T>& c);
		constexpr glmatrix(T* arr, size_t t = 9);
		constexpr glmatrix
		(
			T a1, T a2, T a3,
			T b1, T b2, T b3,
			T c1, T c2, T c3
		);
		// -- 拷贝构造函数 --
		constexpr glmatrix(const glmatrix& obj) = default;
		// -- 重载运算符 --
		// -- 赋值运算符 --
		constexpr glmatrix<3,3,T>& operator=(const glmatrix<3, 3, T>&) = default;
		constexpr glmatrix<3,3,T>& operator+=(T s);
		constexpr glmatrix<3,3,T>& operator+=(const glmatrix<3, 3, T>&);
		constexpr glmatrix<3,3,T>& operator-=(T s);
		constexpr glmatrix<3,3,T>& operator-= (const glmatrix<3, 3, T>&);
		constexpr glmatrix<3,3,T>& operator-=(T s);
		constexpr glmatrix<3,3,T>& operator-= (const glmatrix<3, 3, T>&);
		constexpr glmatrix<3,3,T>& operator*=(T s);
		template<length_t row> constexpr glmatrix<3, 3, T>& operator*= (const glmatrix<3, row, T>&);
		template<length_t row> constexpr glmatrix<3, 3, T>& operator*= (const glvec<3, T>&);
		constexpr glmatrix<3, 3, T>& operator/=(T s);
		constexpr glmatrix<3, 3, T>& operator%=(T s);
		// -- 自增运算符 --
		constexpr glmatrix<3, 3, T>& operator++();
		constexpr glmatrix<3, 3, T> operator++(int);
		// -- 索引运算符 --
		constexpr glmatrix<3, 3, T>& operator[](int i);
	public:
		col_type value[3];
	};
	// -- 一元运算 --
	template<typename T> glmatrix<3, 3, T> operator+(const glmatrix<3, 3, T>&);
	template<typename T> glmatrix<3, 3, T> operator-(const glmatrix<3, 3, T>&);
	// -- 与标量运算 --
	template<typename T> glmatrix<3, 3, T> operator+(const glmatrix<3, 3, T>& m, T s);
	template<typename T> glmatrix<3, 3, T> operator-(const glmatrix<3, 3, T>& m, T s);
	template<typename T> glmatrix<3, 3, T> operator*(const glmatrix<3, 3, T>& m, T s);
	//template<typename T> glmatrix<3, 3, T>& operator/(const glmatrix<3, 3, T>& m, T s); //矩阵无除法运算
	// -- 与矩阵运算 --
	template<typename T> glmatrix<3, 3, T> operator+(const glmatrix<3, 3, T>& m, const glmatrix<3, 3, T>& n);
	template<typename T> glmatrix<3, 3, T> operator-(const glmatrix<3, 3, T>& m, const glmatrix<3, 3, T>& n);
	template<typename T> glmatrix<3, 3, T> operator*(const glmatrix<3, 3, T>& m, const glmatrix<3, 3, T>& n);
	// -- 与向量运算 --
	template<typename T> glmatrix<3, 3, T> operator*(const glmatrix<3, 3, T>& m, const glvec<3, T>& n);
}




#endif // !_Matrix_H_
