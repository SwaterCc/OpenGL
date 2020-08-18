namespace glmath
{
	template<typename T>
	inline constexpr glmatrix<3, 3, T>::glmatrix() :value{ col_type(0),col_type(0),col_type(0)}
	{

	}
	template<typename T>
	inline constexpr glmatrix<3, 3, T>::glmatrix(T scaler) : value{ col_type.x(scaler),col_type.y(scaler),col_type.z(scaler)}
	{
	}
	template<typename T>
	inline constexpr glmatrix<3, 3, T>::glmatrix(glvec<3, T>& a, glvec<3, T>& b, glvec<3, T>& c) :
		value{ a,b,c }
	{
	}
	template<typename T>
	inline constexpr glmatrix<3, 3, T>::glmatrix(T* arr, size_t t) :
		value{ col_type(arr[0],arr[1],arr[2]),col_type(arr[3],arr[4],arr[5]),col_type(arr[6],arr[7],arr[8]) }
	{
	}
	template<typename T>
	inline constexpr glmatrix<3, 3, T>::glmatrix(T a1, T a2, T a3,T b1, T b2, T b3,T c1, T c2, T c3) :
		value{ col_type(a1,a2,a3),col_type(b1,b2,b3),col_type(c1,c2,c3) }
	{
	}
	template<typename T>
	inline constexpr glmatrix<3, 3, T>& glmatrix<3, 3, T>::operator+=(T s)
	{
		this->value[0] += s;
		this->value[1] += s;
		this->value[2] += s;
		return *this;
	}
	template<typename T>
	inline constexpr glmatrix<3, 3, T>& glmatrix<3, 3, T>::operator+=(const glmatrix<3, 3, T>& m)
	{
		this->valuep[0] += m[0];
		this->valuep[1] += m[1];
		this->valuep[2] += m[2];
		return *this;
	}
	template<typename T>
	inline constexpr glmatrix<3, 3, T>& glmatrix<3, 3, T>::operator-=(T s)
	{
		this->value[0] -= s;
		this->value[1] -= s;
		this->value[2] -= s;
		return *this;
	}
	template<typename T>
	inline constexpr glmatrix<3, 3, T>& glmatrix<3, 3, T>::operator-=(const glmatrix<3, 3, T>& m)
	{
		this->value[0] -= m[0];
		this->value[1] -= m[1];
		this->value[2] -= m[2];
		return *this;
	}
	template<typename T>
	inline constexpr glmatrix<3, 3, T>& glmatrix<3, 3, T>::operator*=(T s)
	{
		this->value[0] *= s;
		this->value[1] *= s;
		this->value[2] *= s;
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
		this->value[2] /= s;
		return *this;
	}

	template<typename T>
	inline constexpr glmatrix<3, 3, T>& glmatrix<3, 3, T>::operator%=(T s)
	{
		this->value[0] %= s;
		this->value[1] %= s;
		this->value[2] %= s;
		return *this;
	}

	template<typename T>
	inline constexpr glmatrix<3, 3, T>& glmatrix<3, 3, T>::operator++()
	{
		++value[0];
		++value[1];
		++value[2];
		return *this;
	}

	template<typename T>
	inline constexpr glmatrix<3, 3, T> glmatrix<3, 3, T>::operator++(int)
	{
		glmatrix<3, 3, T> res(*this);
		++value[0];
		++value[1];
		++value[2];
		return res;
	}

	template<typename T>
	inline constexpr glmatrix<3, 3, T>& glmatrix<3, 3, T>::operator[](int i)
	{
		return value[i];
	}
	template<typename T>
	inline constexpr glvec<3, T>& glmatrix<3, 3, T>::getRowByIndex(int i)
	{
		return glvec<3, T>(value[0][i], value[1][i],value[2][i]);
	}
	template<typename T>
	glmatrix<3, 3, T> operator+(const glmatrix<3, 3, T>& m)
	{
		return m;
	}

	template<typename T>
	glmatrix<3, 3, T> operator-(const glmatrix<3, 3, T>& m)
	{
		return glmatrix<3, 3, T>(-m[0], -m[1],-m[2]);
	}

	template<typename T>
	glmatrix<3, 3, T> operator+(const glmatrix<3, 3, T>& m, T s)
	{
		return glmatrix<3, 3, T>(m[0] + s, m[1] + s, m[2] + s);
	}

	template<typename T>
	glmatrix<3, 3, T> operator-(const glmatrix<3, 3, T>& m, T s)
	{
		return glmatrix<3, 3, T>(m[0] - s, m[1] - s, m[2] - s);
	}

	template<typename T>
	glmatrix<3, 3, T> operator*(const glmatrix<3, 3, T>& m, T s)
	{
		return glmatrix<3, 3, T>(m[0] * s, m[1] * s, m[2] * s);
	}

	template<typename T>
	glmatrix<3, 3, T> operator+(const glmatrix<3, 3, T>& m, const glmatrix<3, 3, T>& n)
	{
		return glmatrix<3, 3, T>(m[0] + n[0], m[1] + n[1], m[2] + n[2]);
	}

	template<typename T>
	glmatrix<3, 3, T> operator-(const glmatrix<3, 3, T>& m, const glmatrix<3, 3, T>& n)
	{
		return glmatrix<3, 3, T>(m[0] - n[0], m[1] - n[1], m[2] - n[2]);
	}

	template<typename T>
	glmatrix<3, 3, T> operator*(const glmatrix<3, 3, T>& m, const glmatrix<3, 3, T>& n)
	{
		return glmatrix<3, 3, T>(
			m[0] * n.getRowByIndex(0), m[0] * n.getRowByIndex(1), m[0] * n.getRowByIndex(2),
			m[1] * n.getRowByIndex(0), m[1] * n.getRowByIndex(1), m[1] * n.getRowByIndex(2),
			m[2] * n.getRowByIndex(0), m[2] * n.getRowByIndex(1), m[2] * n.getRowByIndex(2)
			);
	}

	template<typename T>
	glvec<3, T> operator*(const glmatrix<3, 3, T>& m, const glvec<3, T>& n)
	{
		return glvec<3, T>(m[0] * n, m[1] * n, m[2] * n);
	}
}
