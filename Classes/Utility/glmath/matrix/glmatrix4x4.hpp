#ifndef _Matrix4x4_
#define _Matrix4x4_
#include"../gl_math_template.hpp"
namespace glmath {
	template<typename T>
	class glmatrix<4, 4, T>
	{
		typedef glvec<4, T> col_type;
		typedef glvec<4, T> row_type;
	public:
		// -- ���캯�� --
		constexpr glmatrix();
		constexpr glmatrix(T scaler);
		constexpr glmatrix(glvec<4, T>& a, glvec<4, T>& b, glvec<4, T>& c);
		constexpr glmatrix(T* arr, size_t t = 9);
		constexpr glmatrix
		(
			T a1, T a2, T a3,
			T b1, T b2, T b3,
			T c1, T c2, T c3
		);
		// -- �������캯�� --
		constexpr glmatrix(const glmatrix& obj) = default;
		// -- ��������� --
		// -- ��ֵ����� --
		constexpr glmatrix<4, 4, T>& operator=(const glmatrix<4, 4, T>&) = default;
		constexpr glmatrix<4, 4, T>& operator+=(T s);
		constexpr glmatrix<4, 4, T>& operator+=(const glmatrix<4, 4, T>&);
		constexpr glmatrix<4, 4, T>& operator-=(T s);
		constexpr glmatrix<4, 4, T>& operator-= (const glmatrix<4, 4, T>&);
		constexpr glmatrix<4, 4, T>& operator-=(T s);
		constexpr glmatrix<4, 4, T>& operator-= (const glmatrix<4, 4, T>&);
		constexpr glmatrix<4, 4, T>& operator*=(T s);
		template<length_t row> constexpr glmatrix<4, 4, T>& operator*= (const glmatrix<4, row, T>&);
		template<length_t row> constexpr glmatrix<4, 4, T>& operator*= (const glvec<4, T>&);
		constexpr glmatrix<4, 4, T>& operator/=(T s);
		constexpr glmatrix<4, 4, T>& operator%=(T s);
		// -- ��������� --
		constexpr glmatrix<4, 4, T>& operator++();
		constexpr glmatrix<4, 4, T> operator++(int);
		// -- ��������� --
		constexpr glmatrix<4, 4, T>& operator[](int i);
	public:
		col_type value[3];
	};
	// -- һԪ���� --
	template<typename T> glmatrix<4, 4, T> operator+(const glmatrix<4, 4, T>&);
	template<typename T> glmatrix<4, 4, T> operator-(const glmatrix<4, 4, T>&);
	// -- ��������� --
	template<typename T> glmatrix<4, 4, T> operator+(const glmatrix<4, 4, T>& m, T s);
	template<typename T> glmatrix<4, 4, T> operator-(const glmatrix<4, 4, T>& m, T s);
	template<typename T> glmatrix<4, 4, T> operator*(const glmatrix<4, 4, T>& m, T s);
	//template<typename T> glmatrix<4, 4, T>& operator/(const glmatrix<4, 4, T>& m, T s); //�����޳�������
	// -- ��������� --
	template<typename T> glmatrix<4, 4, T> operator+(const glmatrix<4, 4, T>& m, const glmatrix<4, 4, T>& n);
	template<typename T> glmatrix<4, 4, T> operator-(const glmatrix<4, 4, T>& m, const glmatrix<4, 4, T>& n);
	template<typename T> glmatrix<4, 4, T> operator*(const glmatrix<4, 4, T>& m, const glmatrix<4, 4, T>& n);
	// -- ���������� --
	template<typename T> glmatrix<4, 4, T> operator*(const glmatrix<4, 4, T>& m, const glvec<4, T>& n);
}




#endif // !_Matrix_H_
