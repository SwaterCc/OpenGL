namespace glmath {
	template<typename T>
	inline constexpr glvec<2, T>::glvec() :x(0), y(0)
	{

	}

	template<typename T>
	inline constexpr glvec<2, T>::glvec(T a, T b) :x(a), y(b)
	{

	}

	template<typename T>
	inline constexpr glvec<2, T>::glvec(T scalar) :x(scalar), y(scalar)
	{
	}

	template<typename T>
	inline constexpr T& glvec<2, T>::operator[](const size_t i)
	{
		switch (i)
		{
		case 0:
			return x;
		case 1:
			return y;
		default:
			break;
		}
	}
	template<typename T>
	inline constexpr glvec<2, T>& glvec<2, T>::operator++()
	{
		++x;
		++y;
		return *this;
	}
	template<typename T>
	inline constexpr glvec<2, T> glvec<2, T>::operator++(int)
	{
		glvec<2, T>res(*this);
		++(*this);
		return *this;
	}
	template<typename T>
	inline constexpr glvec<2, T>& glvec<2, T>::operator--()
	{
		--x;
		--y;
		return *this;
	}
	template<typename T>
	inline constexpr glvec<2, T> glvec<2, T>::operator--(int)
	{
		glvec<2, T>res(*this);
		--(*this);
		return *this;
	}
	template<typename T>
	inline constexpr glvec<2, T>& glvec<2, T>::operator+=(const T& scalar)
	{
		(*this).x += scalar;
		(*this).y += scalar;
		return (*this);
	}
	template<typename T>
	inline constexpr glvec<2, T>& glvec<2, T>::operator+=(const glvec& v1)
	{
		(*this).x += v1.x;
		(*this).y += v1.y;
		return (*this);
	}
	template<typename T>
	inline constexpr glvec<2, T>& glvec<2, T>::operator-=(const T& scalar)
	{
		(*this).x -= scalar;
		(*this).y -= scalar;
		return (*this);
	}
	template<typename T>
	inline constexpr glvec<2, T>& glvec<2, T>::operator-=(const glvec& v1)
	{
		(*this).x -= v1.x;
		(*this).y -= v1.y;
		return (*this);
	}
	template<typename T>
	inline constexpr glvec<2, T>& glvec<2, T>::operator*=(const T& scalar)
	{
		(*this).x *= scalar;
		(*this).y *= scalar;
		return (*this);
	}
	template<typename T>
	inline constexpr glvec<2, T>& glvec<2, T>::operator*=(const glvec& v1)
	{
		(*this).x *= v1.x;
		(*this).y *= v1.y;
		return (*this);
	}
	template<typename T>
	inline constexpr glvec<2, T>& glvec<2, T>::operator/=(const T& scalar)
	{
		(*this).x /= scalar;
		(*this).y /= scalar;
		return (*this);
	}
	template<typename T>
	inline constexpr glvec<2, T>& glvec<2, T>::operator/=(const glvec& v1)
	{
		(*this).x /= v1.x;
		(*this).y /= v1.y;
		return (*this);
	}
	template<typename T>
	inline constexpr glvec<2, T>& glvec<2, T>::operator%=(const T& scalar)
	{
		(*this).x %= scalar;
		(*this).y %= scalar;
		return (*this);
	}
	template<typename T>
	inline constexpr glvec<2, T>& glvec<2, T>::operator%=(const glvec& v1)
	{
		(*this).x %= v1.x;
		(*this).y %= v1.y;
		return (*this);
	}


	template<typename T>
	constexpr glvec<2, T> operator+(const glvec<2, T>& v)
	{
		return v;
	}

	template<typename T>
	constexpr glvec<2, T> operator-(const glvec<2, T>& v)
	{
		return glvec<2, T>(-v.x, -v.y);
	}

	template<typename T>
	constexpr glvec<2, T> operator+(T const& scalar, const glvec<2, T>& v2)
	{
		return glvec<2, T>(
			scalar + v2.x,
			scalar + v2.y
			);
	}
	template<typename T>
	constexpr glvec<2, T> operator-(T const& scalar, const glvec<2, T>& v2)
	{
		return glvec<2, T>(
			scalar - v2.x,
			scalar - v2.y
			);
	}
	template<typename T>
	constexpr glvec<2, T> operator-(const glvec<2, T>& v1, T const& scalar)
	{
		return glvec<2, T>(
			v1.x - scalar,
			v1.y - scalar
			);
	}
	template<typename T>
	constexpr glvec<2, T> operator*(T const& scalar, const glvec<2, T>& v2)
	{
		return glvec<2, T>(
			scalar * v2.x,
			scalar * v2.y
			);
	}
	template<typename T>
	constexpr glvec<2, T> operator/(T const& scalar, const glvec<2, T>& v2)
	{
		return glvec<2, T>(
			scalar / v2.x,
			scalar / v2.y
			);
	}
	template<typename T>
	constexpr glvec<2, T> operator%(T const& scalar, const glvec<2, T>& v2)
	{
		return glvec<2, T>(
			scalar % v2.x,
			scalar % v2.y
			);
	}

	template<typename T>
	constexpr glvec<2, T> operator+(const glvec<2, T>& v1, glvec<2, T> const& v2)
	{
		return glvec<2, T>(
			v1.x + v2.x,
			v1.y + v2.y
			);
	}
	template<typename T>
	constexpr glvec<2, T> operator-(const glvec<2, T>& v1, glvec<2, T> const& v2)
	{
		return glvec<2, T>(
			v1.x - v2.x,
			v1.y - v2.y
			);
	}
	template<typename T>
	constexpr T operator*(const glvec<2, T>& v1, glvec<2, T> const& v2)
	{
		T a1 = v1.x * v2.x;
		T a2 = v1.y * v2.y;
		return a1 + a2;
	}

}