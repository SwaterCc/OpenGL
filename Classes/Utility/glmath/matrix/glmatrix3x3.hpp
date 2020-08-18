#ifndef _Matrix3x3_
#define _Matrix3x3_
#include"../vec/glvec3.hpp"
namespace glmath {
	template<typename T>
	class glmatrix<3,3,T> 
	{
		typedef glvec<3, T> col_type;
		typedef glvec<3, T> row_type;
	public:
		// -- ���캯�� --
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
		// -- �������캯�� --
		constexpr glmatrix(const glmatrix& obj) = default;
		// -- ��������� --
		glmatrix<3, 3, T>& operator=(const glmatrix<3, 3, T>&) = default;
		glmatrix<3, 3, T>& operator+=(T s);
		glmatrix<3, 3, T>& operator+=(const glmatrix<3, 3, T>&);
		glmatrix<3, 3, T>& operator-=(T s);
		glmatrix<3, 3, T>& operator-= (const glmatrix<3, 3, T>&);
		glmatrix<3, 3, T>& operator*=(T s);
		glmatrix<3, 3, T>& operator*= (const glmatrix<3, 3, T>&);
		glmatrix<3, 3, T>& operator/=(T s);
		glmatrix<3, 3, T>& operator%=(T s);
		// -- ��������� --
		glmatrix<3, 3, T>& operator++();
		glmatrix<3, 3, T> operator++(int);
		// -- ��������� --
		glmatrix<3, 3, T>& operator[](int i);
		// -- ��Ա���� --
		glvec<3, T>& getRowByIndex(int i);
	public:
		col_type value[3];
	};
	// -- һԪ���� --
	template<typename T> glmatrix<3, 3, T> operator+(const glmatrix<3, 3, T>&);
	template<typename T> glmatrix<3, 3, T> operator-(const glmatrix<3, 3, T>&);
	// -- ��������� --
	template<typename T> glmatrix<3, 3, T> operator+(const glmatrix<3, 3, T>& m, T s);
	template<typename T> glmatrix<3, 3, T> operator-(const glmatrix<3, 3, T>& m, T s);
	template<typename T> glmatrix<3, 3, T> operator*(const glmatrix<3, 3, T>& m, T s);
	//template<typename T> glmatrix<3, 3, T>& operator/(const glmatrix<3, 3, T>& m, T s); //�����޳�������
	// -- ��������� --
	template<typename T> glmatrix<3, 3, T> operator+(const glmatrix<3, 3, T>& m, const glmatrix<3, 3, T>& n);
	template<typename T> glmatrix<3, 3, T> operator-(const glmatrix<3, 3, T>& m, const glmatrix<3, 3, T>& n);
	template<typename T> glmatrix<3, 3, T> operator*(const glmatrix<3, 3, T>& m, const glmatrix<3, 3, T>& n);
	// -- ���������� --
	template<typename T> glmatrix<3, 3, T> operator*(const glmatrix<3, 3, T>& m, const glvec<3, T>& n);
}
#include"glmatrix3x3.inl"


#endif // !_Matrix_H_