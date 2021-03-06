#ifndef _Matrix2x2_
#define _Matrix2x2_
#include"../vec/glvec2.hpp"
namespace glmath {
	template<typename T>
	class glmatrix<2, 2, T>
	{
	public:
		typedef glvec<2, T> col_type;
		typedef glvec<2, T> row_type;
		// -- 构造函数 --
		constexpr glmatrix();
		constexpr glmatrix(T scaler);
		constexpr glmatrix(glvec<2, T> a, glvec<2, T> b);
		constexpr glmatrix(T* arr, size_t t = 4);
		constexpr glmatrix
		(
			T a1, T a2,
			T b1, T b2
		);
		// -- 拷贝构造函数 --
		constexpr glmatrix(const glmatrix& obj) = default;
		// -- 重载运算符 --
		// -- 赋值运算符 --
		glmatrix<2, 2, T>& operator=(const glmatrix<2, 2, T>&) = default;
		glmatrix<2, 2, T>& operator+=(T s);
		glmatrix<2, 2, T>& operator+=(const glmatrix<2, 2, T>&);
		glmatrix<2, 2, T>& operator-=(T s);
		glmatrix<2, 2, T>& operator-= (const glmatrix<2, 2, T>&);
		glmatrix<2, 2, T>& operator*=(T s);
		glmatrix<2, 2, T>& operator*= (const glmatrix<2, 2, T>&);
		
		glmatrix<2, 2, T>& operator/=(T s);
		glmatrix<2, 2, T>& operator%=(T s);
		// -- 自增运算符 --
		glmatrix<2, 2, T>& operator++();
		glmatrix<2, 2, T> operator++(int);
		// -- 索引运算符 --
		glvec<2, T>& operator[](int i); //--默认取行
		const glvec<2, T>& operator[](int i)const; //--默认取行
		// -- 成员方法 --
		glvec<2, T>& getRowByIndex(int i); //--取列
		const glvec<2, T>& getRowByIndex(int i)const; //--取列
	public:
		col_type value[2];
	};
	// -- 一元运算 --
	template<typename T> glmatrix<2, 2, T> operator+(const glmatrix<2, 2, T>&);
	template<typename T> glmatrix<2, 2, T> operator-(const glmatrix<2, 2, T>&);
	// -- 与标量运算 --
	template<typename T> glmatrix<2, 2, T> operator+(const glmatrix<2, 2, T>& m, T s);
	template<typename T> glmatrix<2, 2, T> operator-(const glmatrix<2, 2, T>& m, T s);
	template<typename T> glmatrix<2, 2, T> operator*(const glmatrix<2, 2, T>& m, T s);
	//template<typename T> glmatrix<2, 2, T>& operator/(const glmatrix<2, 2, T>& m, T s); //矩阵无除法运算
	// -- 与矩阵运算 --
	template<typename T> glmatrix<2, 2, T> operator+(const glmatrix<2, 2, T>& m, const glmatrix<2, 2, T>& n);
	template<typename T> glmatrix<2, 2, T> operator-(const glmatrix<2, 2, T>& m, const glmatrix<2, 2, T>& n);
	template<typename T> glmatrix<2, 2, T> operator*(const glmatrix<2, 2, T>& m, const glmatrix<2, 2, T>& n);
	// -- 与向量运算 --
	template<typename T> glvec<2,T> operator*(const glmatrix<2, 2, T>& m, const glvec<2, T>& n);
}
#include"glmatrix2x2.inl"



#endif // !_Matrix2x2_
