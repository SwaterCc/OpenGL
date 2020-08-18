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
		// -- ���캯�� --
		constexpr glmatrix();
		constexpr glmatrix(T scaler);
		constexpr glmatrix(glvec<2, T>& a, glvec<2, T>& b);
		constexpr glmatrix(T* arr, size_t t = 4);
		constexpr glmatrix
		(
			T a1, T a2,
			T b1, T b2
		);
		// -- �������캯�� --
		constexpr glmatrix(const glmatrix& obj) = default;
		// -- ��������� --
		// -- ��ֵ����� --
		glmatrix<2, 2, T>& operator=(const glmatrix<2, 2, T>&) = default;
		glmatrix<2, 2, T>& operator+=(T s);
		glmatrix<2, 2, T>& operator+=(const glmatrix<2, 2, T>&);
		glmatrix<2, 2, T>& operator-=(T s);
		glmatrix<2, 2, T>& operator-= (const glmatrix<2, 2, T>&);
		glmatrix<2, 2, T>& operator*=(T s);
		glmatrix<2, 2, T>& operator*= (const glmatrix<2, 2, T>&);
		
		glmatrix<2, 2, T>& operator/=(T s);
		glmatrix<2, 2, T>& operator%=(T s);
		// -- ��������� --
		glmatrix<2, 2, T>& operator++();
		glmatrix<2, 2, T> operator++(int);
		// -- ��������� --
		glmatrix<2, 2, T>& operator[](int i); //--Ĭ��ȡ��
		// -- ��Ա���� --
		row_type& getRowByIndex(int i); //--ȡ��
	public:
		col_type value[2];
	};
	// -- һԪ���� --
	template<typename T> glmatrix<2, 2, T> operator+(const glmatrix<2, 2, T>&);
	template<typename T> glmatrix<2, 2, T> operator-(const glmatrix<2, 2, T>&);
	// -- ��������� --
	template<typename T> glmatrix<2, 2, T> operator+(const glmatrix<2, 2, T>& m, T s);
	template<typename T> glmatrix<2, 2, T> operator-(const glmatrix<2, 2, T>& m, T s);
	template<typename T> glmatrix<2, 2, T> operator*(const glmatrix<2, 2, T>& m, T s);
	//template<typename T> glmatrix<2, 2, T>& operator/(const glmatrix<2, 2, T>& m, T s); //�����޳�������
	// -- ��������� --
	template<typename T> glmatrix<2, 2, T> operator+(const glmatrix<2, 2, T>& m, const glmatrix<2, 2, T>& n);
	template<typename T> glmatrix<2, 2, T> operator-(const glmatrix<2, 2, T>& m, const glmatrix<2, 2, T>& n);
	template<typename T> glmatrix<2, 2, T> operator*(const glmatrix<2, 2, T>& m, const glmatrix<2, 2, T>& n);
	// -- ���������� --
	template<typename T> glvec<2,T> operator*(const glmatrix<2, 2, T>& m, const glvec<2, T>& n);
}
#include"glmatrix2x2.inl"



#endif // !_Matrix2x2_