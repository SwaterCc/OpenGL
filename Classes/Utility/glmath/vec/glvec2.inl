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
	template<typename U>
	inline constexpr glvec<2, T>::glvec(U scalar) : x(static_cast<T>(scalar)), y(static_cast<T>(scalar))
	{
	}

	template<typename T>
	template<typename A, typename B>
	inline constexpr glvec<2, T>::glvec(A a, B b) : x(static_cast<T>(a)), y(static_cast<T>(b))
	{
	}

	template<typename T>
	inline constexpr glvec<2, T>::glvec(const glvec<3, T>& obj) : x(obj.x), y(obj.y)
	{
	}

	template<typename T>
	inline constexpr glvec<2, T>::glvec(const glvec<4, T>& obj) : x(obj.x), y(obj.y)
	{
	}

	template<typename T>
	template<typename U>
	inline constexpr glvec<2, T>::glvec(const glvec<3, U>& obj) : x(static_cast<T>(obj.x)), y(static_cast<T>(obj.y))
	{
	}

	template<typename T>
	template<typename U>
	inline constexpr glvec<2, T>::glvec(const glvec<4, U>& obj) : x(static_cast<T>(obj.x)), y(static_cast<T>(obj.y))
	{
	}

	template<typename T>
	inline T & glvec<2, T>::operator[](size_t i)
	{
		assert(i < 2);
		switch (i)
		{
		case 0:
			return x;
		case 1:
			return y;
		default:
			std::cerr << "error! glvec range out" << std::endl;
			break;
		}
	}

	template<typename T>
	inline T const & glvec<2, T>::operator[](size_t i) const
	{
		assert(i < 2);
		switch (i)
		{
		case 0:
			return x;
		case 1:
			return y;
		default:
			std::cerr << "error! glvec range out" << std::endl;
			break;
		}
	}
	template<typename T>
	inline glvec<2, T>& glvec<2, T>::operator++()
	{
		++x;
		++y;
		return *this;
	}
	template<typename T>
	inline glvec<2, T> glvec<2, T>::operator++(int)
	{
		glvec<2, T>res(*this);
		++(*this);
		return *this;
	}
	template<typename T>
	inline glvec<2, T>& glvec<2, T>::operator--()
	{
		--x;
		--y;
		return *this;
	}
	template<typename T>
	inline glvec<2, T> glvec<2, T>::operator--(int)
	{
		glvec<2, T>res(*this);
		--(*this);
		return *this;
	}
	template<typename T>
	inline glvec<2, T>& glvec<2, T>::operator+=(const T& scalar)
	{
		(*this).x += scalar;
		(*this).y += scalar;
		return (*this);
	}
	template<typename T>
	inline glvec<2, T>& glvec<2, T>::operator+=(const glvec& v1)
	{
		(*this).x += v1.x;
		(*this).y += v1.y;
		return (*this);
	}
	template<typename T>
	inline glvec<2, T>& glvec<2, T>::operator-=(const T& scalar)
	{
		(*this).x -= scalar;
		(*this).y -= scalar;
		return (*this);
	}
	template<typename T>
	inline glvec<2, T>& glvec<2, T>::operator-=(const glvec& v1)
	{
		(*this).x -= v1.x;
		(*this).y -= v1.y;
		return (*this);
	}
	template<typename T>
	inline glvec<2, T>& glvec<2, T>::operator*=(const T& scalar)
	{
		(*this).x *= scalar;
		(*this).y *= scalar;
		return (*this);
	}
	template<typename T>
	inline glvec<2, T>& glvec<2, T>::operator*=(const glvec& v1)
	{
		(*this).x *= v1.x;
		(*this).y *= v1.y;
		return (*this);
	}
	template<typename T>
	inline glvec<2, T>& glvec<2, T>::operator/=(const T& scalar)
	{
		(*this).x /= scalar;
		(*this).y /= scalar;
		return (*this);
	}
	template<typename T>
	inline glvec<2, T>& glvec<2, T>::operator/=(const glvec& v1)
	{
		(*this).x /= v1.x;
		(*this).y /= v1.y;
		return (*this);
	}
	template<typename T>
	inline glvec<2, T>& glvec<2, T>::operator%=(const T& scalar)
	{
		(*this).x %= scalar;
		(*this).y %= scalar;
		return (*this);
	}
	template<typename T>
	inline glvec<2, T>& glvec<2, T>::operator%=(const glvec& v1)
	{
		(*this).x %= v1.x;
		(*this).y %= v1.y;
		return (*this);
	}


	template<typename T>
	glvec<2, T> operator+(const glvec<2, T>& v)
	{
		return v;
	}

	template<typename T>
	glvec<2, T> operator-(const glvec<2, T>& v)
	{
		return glvec<2, T>(-v.x, -v.y);
	}

	template<typename T>
	glvec<2, T> operator+(T const& scalar, const glvec<2, T>& v2)
	{
		return glvec<2, T>(
			scalar + v2.x,
			scalar + v2.y
			);
	}
	template<typename T>
	glvec<2, T> operator-(T const& scalar, const glvec<2, T>& v2)
	{
		return glvec<2, T>(
			scalar - v2.x,
			scalar - v2.y
			);
	}
	template<typename T>
	glvec<2, T> operator-(const glvec<2, T>& v1, T const& scalar)
	{
		return glvec<2, T>(
			v1.x - scalar,
			v1.y - scalar
			);
	}
	template<typename T>
	glvec<2, T> operator*(T const& scalar, const glvec<2, T>& v2)
	{
		return glvec<2, T>(
			scalar * v2.x,
			scalar * v2.y
			);
	}
	template<typename T>
	glvec<2, T> operator/(T const& scalar, const glvec<2, T>& v2)
	{
		return glvec<2, T>(
			scalar / v2.x,
			scalar / v2.y
			);
	}
	template<typename T>
	glvec<2, T> operator%(T const& scalar, const glvec<2, T>& v2)
	{
		return glvec<2, T>(
			scalar % v2.x,
			scalar % v2.y
			);
	}

	template<typename T>
	glvec<2, T> operator+(const glvec<2, T>& v1, glvec<2, T> const& v2)
	{
		return glvec<2, T>(
			v1.x + v2.x,
			v1.y + v2.y
			);
	}
	template<typename T>
	glvec<2, T> operator-(const glvec<2, T>& v1, glvec<2, T> const& v2)
	{
		return glvec<2, T>(
			v1.x - v2.x,
			v1.y - v2.y
			);
	}
	template<typename T>
	T operator*(const glvec<2, T>& v1, glvec<2, T> const& v2)
	{
		T a1 = v1.x * v2.x;
		T a2 = v1.y * v2.y;
		return a1 + a2;
	}

}