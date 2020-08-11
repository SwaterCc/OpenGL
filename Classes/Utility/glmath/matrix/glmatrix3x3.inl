#include"glmatrix3x3.hpp"
namespace glmath
{
	template<typename T>
	inline constexpr glmatrix<3, 3, T>::glmatrix() :value{ col_type(0),col_type(0),col_type(0)}
	{

	}
	template<typename T>
	inline constexpr glmatrix<3, 3, T>::glmatrix(T scaler) : value{ col_type(scaler),col_type(scaler),col_type(scaler)}
	{
	}
	template<typename T>
	inline constexpr glmatrix<3, 3, T>::glmatrix(glvec<3, T>& a, glvec<3, T>& b, glvec<3, T>& c) :
		value{ a,b,c }
	{
	}
	template<typename T>
	inline constexpr glmatrix<3, 3, T>::glmatrix(T* arr, size_t t) :
		value{ col_type(arr[0],arr[1]),col_type(arr[2],arr[3]) }
	{
	}
	template<typename T>
	inline constexpr glmatrix<3, 3, T>::glmatrix(T a1, T a2, T b1, T b2) :
		value{ col_type(a1,a2),col_type(b1,b2) }
	{
	}
	template<typename T>
	inline constexpr glmatrix<3, 3, T>& glmatrix<3, 3, T>::operator+=(T s)
	{
		this->value[0] += s;
		this->value[1] += s;
		return *this;
	}
	template<typename T>
	inline constexpr glmatrix<3, 3, T>& glmatrix<3, 3, T>::operator+=(const glmatrix<3, 3, T>& m)
	{
		this->valuep[0] += m[0];
		this->valuep[1] += m[1];
		return *this;
	}
	template<typename T>
	inline constexpr glmatrix<3, 3, T>& glmatrix<3, 3, T>::operator-=(T s)
	{
		this->value[0] -= s;
		this->value[1] -= s;
		return *this;
	}
	template<typename T>
	inline constexpr glmatrix<3, 3, T>& glmatrix<3, 3, T>::operator-=(const glmatrix<3, 3, T>& m)
	{
		this->value[0] -= m[0];
		this->value[1] -= m[1];
		return *this;
	}
	template<typename T>
	inline constexpr glmatrix<3, 3, T>& glmatrix<3, 3, T>::operator*=(T s)
	{
		this->value[0] *= s;
		this->value[1] *= s;
		return *this;
	}

	template<typename T>
	inline constexpr glmatrix<3, 3, T>& glmatrix<3, 3, T>::operator*=(const glmatrix<3, 3, T>& m)
	{
		(*this).value = (*this).value * m;
		return *this;
	}

	template<typename T>
	inline constexpr glmatrix<3, 3, T>& glmatrix<3, 3, T>::operator/=(T s)
	{
		this->value[0] /= s;
		this->value[1] /= s;
		return *this;
	}

	template<typename T>
	inline constexpr glmatrix<3, 3, T>& glmatrix<3, 3, T>::operator%=(T s)
	{
		this->value[0] %= s;
		this->value[1] %= s;
		return *this;
	}

	template<typename T>
	inline constexpr glmatrix<3, 3, T>& glmatrix<3, 3, T>::operator++()
	{
		++value[0];
		++value[1];
		return *this;
	}

	template<typename T>
	inline constexpr glmatrix<3, 3, T> glmatrix<3, 3, T>::operator++(int)
	{
		glmatrix<3, 3, T> res(*this);
		++value[0];
		++value[1];
		return res;
	}

	template<typename T>
	inline constexpr glmatrix<3, 3, T>& glmatrix<3, 3, T>::operator[](int i)
	{
		return value[i];
	}
	template<typename T>
	inline constexpr glvec<2, T>& glmatrix<3, 3, T>::getRowByIndex(int i)
	{
		return glvec<2, T>(value[0][i], value[1][i]);
	}
	template<typename T>
	glmatrix<3, 3, T> operator+(const glmatrix<3, 3, T>& m)
	{
		return m;
	}

	template<typename T>
	glmatrix<3, 3, T> operator-(const glmatrix<3, 3, T>& m)
	{
		return glmatrix<3, 3, T>(-m[0], -m[1]);
	}

	template<typename T>
	glmatrix<3, 3, T> operator+(const glmatrix<3, 3, T>& m, T s)
	{
		return glmatrix<3, 3, T>(m[0] + s, m[1] + s);
	}

	template<typename T>
	glmatrix<3, 3, T> operator-(const glmatrix<3, 3, T>& m, T s)
	{
		return glmatrix<3, 3, T>(m[0] - s, m[1] - s);
	}

	template<typename T>
	glmatrix<3, 3, T> operator*(const glmatrix<3, 3, T>& m, T s)
	{
		return glmatrix<3, 3, T>(m[0] * s, m[1] * s);
	}

	template<typename T>
	glmatrix<3, 3, T> operator+(const glmatrix<3, 3, T>& m, const glmatrix<3, 3, T>& n)
	{
		return glmatrix<3, 3, T>(m[0] + n[0], m[1] + n[1]);
	}

	template<typename T>
	glmatrix<3, 3, T> operator-(const glmatrix<3, 3, T>& m, const glmatrix<3, 3, T>& n)
	{
		return glmatrix<3, 3, T>(m[0] - n[0], m[1] - n[1]);
	}

	template<typename T>
	glmatrix<3, 3, T> operator*(const glmatrix<3, 3, T>& m, const glmatrix<3, 3, T>& n)
	{
		return glmatrix<3, 3, T>(
			m[0] * n.getRowByIndex(0), m[0] * n.getRowByIndex(1),
			m[1] * n.getRowByIndex(0), m[1] * n.getRowByIndex(1)
			);
	}

	template<typename T>
	glvec<2, T> operator*(const glmatrix<3, 3, T>& m, const glvec<2, T>& n)
	{
		return glvec<2, T>(m[0] * n, m[1] * n);
	}
}