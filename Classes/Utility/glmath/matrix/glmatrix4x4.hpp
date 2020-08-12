#ifndef _Matrix4x4_
#define _Matrix4x4_
#include"../vec/glvec4.hpp"
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
		constexpr glmatrix(glvec<4, T>& a, glvec<4, T>& b, glvec<4, T>& c, glvec<4, T>& d);
		constexpr glmatrix(T* arr, size_t t = 16);
		constexpr glmatrix
		(
			T a1, T a2, T a3, T a4,
			T b1, T b2, T b3, T b4,
			T c1, T c2, T c3, T c4,
			T d1, T d2, T d3, T d4
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
		constexpr glmatrix<4, 4, T>& operator*=(T s);
		constexpr glmatrix<4, 4, T>& operator*= (const glmatrix<4, 4, T>&);
		
		constexpr glmatrix<4, 4, T>& operator/=(T s);
		constexpr glmatrix<4, 4, T>& operator%=(T s);
		// -- ��������� --
		constexpr glmatrix<4, 4, T>& operator++();
		constexpr glmatrix<4, 4, T> operator++(int);
		// -- ��������� --
		constexpr glmatrix<4, 4, T>& operator[](int i);
		// -- ��Ա���� --
		constexpr glvec<4, T>& glmatrix<4, 4, T>::getRowByIndex(int i);
	public:
		col_type value[4];
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
