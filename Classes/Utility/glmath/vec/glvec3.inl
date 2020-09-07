namespace glmath {
	template<typename T>
	inline constexpr glvec<3, T>::glvec() :x(0), y(0), z(0)
	{

	}

	template<typename T>
	inline constexpr glvec<3, T>::glvec(T a, T b, T c):x(a),y(b),z(c)
	{

	}

	template<typename T>
	inline constexpr glvec<3, T>::glvec(const glvec<2, T>& v, T c) :x(v.x), y(v.y), z(c)
	{
	}

	template<typename T>
	inline constexpr glvec<3, T>::glvec(T c, const glvec<2, T>& v) : x(c), y(v.x), z(v.y)
	{

	}

	template<typename T>
	inline constexpr glvec<3, T>::glvec(T scalar):x(scalar), y(scalar), z(scalar)
	{
	}
	
	template<typename T>
	template<typename U>
	inline constexpr glvec<3, T>::glvec(U scalar) : x(static_cast<T>(scalar)), y(static_cast<T>(scalar)), z(static_cast<T>(scalar))
	{
	}

	template<typename T>
	template<typename A, typename B, typename C>
	inline constexpr glvec<3, T>::glvec(A a, B b, C c) : x(static_cast<T>(a)), y(static_cast<T>(b)), z(static_cast<T>(c))
	{
	}

	template<typename T>
	template<typename A, typename B>
	inline constexpr glvec<3, T>::glvec(const glvec<2, A>& v, B c) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(c))
	{
	}

	template<typename T>
	template<typename A, typename B>
	inline constexpr glvec<3, T>::glvec(A c, const glvec<2, B>& v) : x(static_cast<T>(c)), y(static_cast<T>(v.x)), z(static_cast<T>(v.y))
	{

	}

	template<typename T>
	inline constexpr glvec<3, T>::glvec(const glvec<4, T>& obj) : x(obj.x), y(obj.y), z(obj.z)
	{
	}

	template<typename T>
	template<typename U>
	inline constexpr glvec<3, T>::glvec(const glvec<4, U>& obj) : x(static_cast<T>(obj.x)), y(static_cast<T>(obj.y)), z(static_cast<T>(obj.z))
	{
	}

	template<typename T>
	inline T & glvec<3, T>::operator[](size_t i) 
	{
		assert(i < 3);
		switch (i)
		{
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		default:
			std::cerr << "error! glvec range out" << std::endl;
			break;
		}
	}

	template<typename T>
	inline T const & glvec<3, T>::operator[](size_t i) const
	{
		assert(i < 3);
		switch (i)
		{
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		default:
			std::cerr << "error! glvec range out" << std::endl;
			break;
		}
	}

	template<typename T>
	inline glvec<3, T>& glvec<3, T>::operator++()
	{
		++x;
		++y;
		++z;
		return *this;
	}
	template<typename T>
	inline glvec<3, T> glvec<3, T>::operator++(int)
	{
		glvec<3, T>res(*this);
		++(*this);
		return *this;
	}
	template<typename T>
	inline glvec<3, T>& glvec<3, T>::operator--()
	{
		--x;
		--y;
		--z;
		return *this;
	}
	template<typename T>
	inline glvec<3, T> glvec<3, T>::operator--(int)
	{
		glvec<3, T>res(*this);
		--(*this);
		return *this;
	}
	template<typename T>
	inline glvec<3, T>& glvec<3, T>::operator+=(const T& scalar)
	{
		(*this).x += scalar;
		(*this).y += scalar;
		(*this).z += scalar;

		return (*this);
	}
	template<typename T>
	inline glvec<3, T>& glvec<3, T>::operator+=(const glvec& v1)
	{
		(*this).x += v1.x;
		(*this).y += v1.y;
		(*this).z += v1.z;

		return (*this);
	}
	template<typename T>
	inline glvec<3, T>& glvec<3, T>::operator-=(const T& scalar)
	{
		(*this).x -= scalar;
		(*this).y -= scalar;
		(*this).z -= scalar;

		return (*this);
	}
	template<typename T>
	inline glvec<3, T>& glvec<3, T>::operator-=(const glvec& v1)
	{
		(*this).x -= v1.x;
		(*this).y -= v1.y;
		(*this).z -= v1.z;

		return (*this);
	}
	template<typename T>
	inline glvec<3, T>& glvec<3, T>::operator*=(const T& scalar)
	{
		(*this).x *= scalar;
		(*this).y *= scalar;
		(*this).z *= scalar;

		return (*this);
	}
	template<typename T>
	inline glvec<3, T>& glvec<3, T>::operator*=(const glvec& v1)
	{
		(*this).x *= v1.x;
		(*this).y *= v1.y;
		(*this).z *= v1.z;

		return (*this);
	}
	template<typename T>
	inline glvec<3, T>& glvec<3, T>::operator/=(const T& scalar)
	{
		(*this).x /= scalar;
		(*this).y /= scalar;
		(*this).z /= scalar;

		return (*this);
	}
	template<typename T>
	inline glvec<3, T>& glvec<3, T>::operator/=(const glvec& v1)
	{
		(*this).x /= v1.x;
		(*this).y /= v1.y;
		(*this).z /= v1.z;

		return (*this);
	}
	template<typename T>
	inline glvec<3, T>& glvec<3, T>::operator%=(const T& scalar)
	{
		(*this).x %= scalar;
		(*this).y %= scalar;
		(*this).z %= scalar;

		return (*this);
	}
	template<typename T>
	inline glvec<3, T>& glvec<3, T>::operator%=(const glvec& v1)
	{
		(*this).x %= v1.x;
		(*this).y %= v1.y;
		(*this).z %= v1.z;

		return (*this);
	}

	template<typename T>
    glvec<3, T> operator+(const glvec<3, T>& v)
	{
		return v;
	}
	template<typename T>
	glvec<3, T> operator-(const glvec<3, T>& v)
	{
		return glvec<3, T>(-v.x,-v.y,-v.y);
	}

	template<typename T>
	glvec<3, T> operator+(T const& scalar, const glvec<3, T>& v2)
	{
		return glvec<3, T>(
			scalar + v2.x,
			scalar + v2.y,
			scalar + v2.z
			);
	}
	template<typename T>
	glvec<3, T> operator+(const glvec<3, T>& v1, glvec<3, T> const& v2)
	{
		return glvec<3, T>(
			v1.x + v2.x,
			v1.y + v2.y,
			v1.z + v2.z
			);
	}

	template<typename T>
	glvec<3, T> operator-(T const& scalar, const glvec<3, T>& v2)
	{
		return glvec<3, T>(
			scalar - v2.x,
			scalar - v2.y,
			scalar - v2.z
			);
	}
	template<typename T>
	glvec<3, T> operator-(const glvec<3, T>& v1, T const& scalar)
	{
		return glvec<3, T>(
			v1.x - scalar,
			v1.y - scalar,
			v1.z - scalar
			);
	}
	template<typename T>
	glvec<3, T> operator-(const glvec<3, T>& v1, glvec<3, T> const& v2)
	{
		return glvec<3, T>(
			v1.x - v2.x,
			v1.y - v2.y,
			v1.z - v2.z
			);
	}

	template<typename T>
	glvec<3, T> operator*(T const& scalar, const glvec<3, T>& v2)
	{
		return glvec<3, T>(
			scalar * v2.x,
			scalar * v2.y,
			scalar * v2.z
			);
	}
	template<typename T>
	T operator*(const glvec<3, T>& v1, glvec<3, T> const& v2)
	{
		
		T a1 = v1.x * v2.x;
		T a2 = v1.y * v2.y;
		T a3 = v1.z * v2.z;

		return a1 + a2 + a3;
	}

	template<typename T>
	glvec<3, T> operator/(T const& scalar, const glvec<3, T>& v2)
	{
		return glvec<3, T>(
			scalar / v2.x,
			scalar / v2.y,
			scalar / v2.z
			);
	}

	template<typename T>
	glvec<3, T> operator%(T const& scalar, const glvec<3, T>& v2)
	{
		return glvec<3, T>(
			scalar % v2.x,
			scalar % v2.y,
			scalar % v2.z
			);
	}
}