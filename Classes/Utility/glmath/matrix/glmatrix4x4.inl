namespace glmath
{
	template<typename T>
	inline constexpr glmatrix<4, 4, T>::glmatrix() :value{ col_type(0),col_type(0),col_type(0),col_type(0) }
	{

	}
	template<typename T>
	inline constexpr glmatrix<4, 4, T>::glmatrix(T scaler) : value{ col_type(scaler,0,0,0),col_type(0,scaler,0,0),col_type(0,0,scaler,0),col_type(0,0,0,scaler) }
	{

	}
	template<typename T>
	inline constexpr glmatrix<4, 4, T>::glmatrix(glvec<4, T>& a, glvec<4, T>& b, glvec<4, T>& c, glvec<4, T>& d) :
		value{ a,b,c }
	{
	}
	template<typename T>
	inline constexpr glmatrix<4, 4, T>::glmatrix(T* arr, size_t t) :
		value
	{
		col_type(arr[0], arr[1], arr[2], arr[3]),
		col_type(arr[4], arr[5], arr[6], arr[7]),
		col_type(arr[8], arr[9], arr[10],arr[11]),
		col_type(arr[12],arr[13],arr[14],arr[15])
	} {}
	template<typename T>
	inline constexpr glmatrix<4, 4, T>::glmatrix(
		T a1, T a2, T a3, T a4,
		T b1, T b2, T b3, T b4,
		T c1, T c2, T c3, T c4,
		T d1, T d2, T d3, T d4) :
		value{ col_type(a1,a2,a3,a4),col_type(b1,b2,b3,b4),col_type(c1,c2,c3,c4),col_type(d1,d2,d3,d4) }
	{
	}
	template<typename T>
	inline glmatrix<4, 4, T>& glmatrix<4, 4, T>::operator+=(T s)
	{
		this->value[0] += s;
		this->value[1] += s;
		this->value[2] += s;
		this->value[3] += s;
		return *this;
	}
	template<typename T>
	inline glmatrix<4, 4, T>& glmatrix<4, 4, T>::operator+=(const glmatrix<4, 4, T>& m)
	{
		this->valuep[0] += m[0];
		this->valuep[1] += m[1];
		this->valuep[2] += m[2];
		this->valuep[3] += m[3];
		return *this;
	}
	template<typename T>
	inline glmatrix<4, 4, T>& glmatrix<4, 4, T>::operator-=(T s)
	{
		this->value[0] -= s;
		this->value[1] -= s;
		this->value[2] -= s;
		this->value[3] -= s;
		return *this;
	}
	template<typename T>
	inline glmatrix<4, 4, T>& glmatrix<4, 4, T>::operator-=(const glmatrix<4, 4, T>& m)
	{
		this->value[0] -= m[0];
		this->value[1] -= m[1];
		this->value[2] -= m[2];
		this->value[3] -= m[3];
		return *this;
	}
	template<typename T>
	inline glmatrix<4, 4, T>& glmatrix<4, 4, T>::operator*=(T s)
	{
		this->value[0] *= s;
		this->value[1] *= s;
		this->value[2] *= s;
		this->value[3] *= s;
		return *this;
	}

	template<typename T>
	inline glmatrix<4, 4, T>& glmatrix<4, 4, T>::operator*=(const glmatrix<4, 4, T>& m)
	{
		(*this).value = (*this).value * m;
		return *this;
	}

	template<typename T>
	inline glmatrix<4, 4, T>& glmatrix<4, 4, T>::operator/=(T s)
	{
		this->value[0] /= s;
		this->value[1] /= s;
		this->value[2] /= s;
		this->value[3] /= s;
		return *this;
	}

	template<typename T>
	inline glmatrix<4, 4, T>& glmatrix<4, 4, T>::operator%=(T s)
	{
		this->value[0] %= s;
		this->value[1] %= s;
		this->value[2] %= s;
		this->value[3] %= s;
		return *this;
	}

	template<typename T>
	inline glmatrix<4, 4, T>& glmatrix<4, 4, T>::operator++()
	{
		++value[0];
		++value[1];
		++value[2];
		++value[3];
		return *this;
	}

	template<typename T>
	inline glmatrix<4, 4, T> glmatrix<4, 4, T>::operator++(int)
	{
		glmatrix<4, 4, T> res(*this);
		++value[0];
		++value[1];
		++value[2];
		++value[3];
		return res;
	}

	template<typename T>
	inline glmatrix<4, 4, T>& glmatrix<4, 4, T>::operator[](int i)
	{
		return value[i];
	}
	template<typename T>
	inline glvec<4, T>& glmatrix<4, 4, T>::getRowByIndex(int i)
	{
		return glvec<4, T>(value[0][i], value[1][i], value[2][i], value[3][i]);
	}


	template<typename T>
	glmatrix<4, 4, T> operator+(const glmatrix<4, 4, T>& m)
	{
		return m;
	}

	template<typename T>
	glmatrix<4, 4, T> operator-(const glmatrix<4, 4, T>& m)
	{
		return glmatrix<4, 4, T>(-m[0], -m[1], -m[2], -m[3]);
	}

	template<typename T>
	glmatrix<4, 4, T> operator+(const glmatrix<4, 4, T>& m, T s)
	{
		return glmatrix<4, 4, T>(m[0] + s, m[1] + s, m[2] + s, m[3] + s);
	}

	template<typename T>
	glmatrix<4, 4, T> operator-(const glmatrix<4, 4, T>& m, T s)
	{
		return glmatrix<4, 4, T>(m[0] - s, m[1] - s, m[2] - s, m[3] - s);
	}

	template<typename T>
	glmatrix<4, 4, T> operator*(const glmatrix<4, 4, T>& m, T s)
	{
		return glmatrix<4, 4, T>(m[0] * s, m[1] * s, m[2] * s, m[3] * s);
	}

	template<typename T>
	glmatrix<4, 4, T> operator+(const glmatrix<4, 4, T>& m, const glmatrix<4, 4, T>& n)
	{
		return glmatrix<4, 4, T>(m[0] + n[0], m[1] + n[1], m[2] + n[2], m[3] + n[3]);
	}

	template<typename T>
	glmatrix<4, 4, T> operator-(const glmatrix<4, 4, T>& m, const glmatrix<4, 4, T>& n)
	{
		return glmatrix<4, 4, T>(m[0] - n[0], m[1] - n[1], m[2] - n[2], m[3] - n[3]);
	}

	template<typename T>
	glmatrix<4, 4, T> operator*(const glmatrix<4, 4, T>& m, const glmatrix<4, 4, T>& n)
	{
		return glmatrix<4, 4, T>(
			m[0] * n.getRowByIndex(0), m[0] * n.getRowByIndex(1), m[0] * n.getRowByIndex(2), m[0] * n.getRowByIndex(3),
			m[1] * n.getRowByIndex(0), m[1] * n.getRowByIndex(1), m[1] * n.getRowByIndex(2), m[1] * n.getRowByIndex(3),
			m[2] * n.getRowByIndex(0), m[2] * n.getRowByIndex(1), m[2] * n.getRowByIndex(2), m[2] * n.getRowByIndex(3),
			m[3] * n.getRowByIndex(0), m[3] * n.getRowByIndex(1), m[3] * n.getRowByIndex(2), m[3] * n.getRowByIndex(3)
			);
	}

	template<typename T>
	glvec<4, T> operator*(const glmatrix<4, 4, T>& m, const glvec<4, T>& n)
	{
		return glvec<2, T>(m[0] * n, m[1] * n, m[2] * n, m[3] * n);
	}
}