namespace glmath {
	template<typename T>
	inline constexpr glvec<4, T>::glvec() :x(0), y(0), z(0),w(0)
	{

	}

	template<typename T>
	inline constexpr glvec<4, T>::glvec(T a, T b, T c, T d) :x(a), y(b), z(c), w(d)
	{

	}

	template<typename T>
	inline constexpr glvec<4, T>::glvec(T scalar) :x(scalar), y(scalar), z(scalar),w(scalar)
	{
	}

	template<typename T>
	template<typename U>
	inline constexpr glvec<4, T>::glvec(U scalar) : x(static_cast<T>(scalar)), y(static_cast<T>(scalar)), z(static_cast<T>(scalar)), w(static_cast<T>(scalar))
	{
	}

	template<typename T>
	template<typename A, typename B, typename C, typename D>
	inline constexpr glvec<4, T>::glvec(A a, B b, C c, D d) : x(static_cast<T>(a)), y(static_cast<T>(b)), z(static_cast<T>(c)), w(static_cast<T>(d))
	{
	}

	template<typename T>
	inline constexpr glvec<4, T>::glvec(const glvec<2, T>& v, T c, T d) : x(v.x), y(v.y), z(c), w(d)
	{
	}
	template<typename T>
	inline constexpr glvec<4, T>::glvec(T a, T b, const glvec<2, T>& v) : x(a), y(b), z(v.x), w(v.y)
	{
	}
	template<typename T>
	template<typename A, typename B, typename C>
	inline constexpr glvec<4, T>::glvec(const glvec<2, A>& v, B b, C c) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(b)), w(static_cast<T>(d))
	{
	}

	template<typename T>
	template<typename A, typename B, typename C>
	inline constexpr glvec<4, T>::glvec(A a, B b, const glvec<2, C>& v) : x(static_cast<T>(a)), y(static_cast<T>(b)), z(static_cast<T>(v.x)), w(static_cast<T>(v.y))
	{

	}

	template<typename T>
	inline constexpr glvec<4, T>::glvec(const glvec<3, T>& v, T d) : x(v.x), y(v.y), z(v.z), w(d)
	{
	}
	template<typename T>
	inline constexpr glvec<4, T>::glvec(T a, const glvec<3, T>& v) : x(a), y(v.x), z(v.y), w(v.z)
	{
	}

	template<typename T>
	template<typename A, typename B>
	inline constexpr glvec<4, T>::glvec(const glvec<3, A>& v, B b) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(v.z)), w(static_cast<T>(b))
	{
	}

	template<typename T>
	template<typename A, typename B>
	inline constexpr glvec<4, T>::glvec(A a, const glvec<3, B>& v) : x(static_cast<T>(a)), y(static_cast<T>(v.x)), z(static_cast<T>(v.y)), w(static_cast<T>(v.z))
	{

	}

	template<typename T>
	inline T & glvec<4, T>::operator[](size_t i)
	{
		assert(i < 4);
		switch (i)
		{
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		case 3:
			return w;
		default:
			std::cerr << "error! glvec range out" << std::endl;
			break;
		}
	}

	template<typename T>
	inline T const & glvec<4, T>::operator[](size_t i) const
	{
		assert(i < 4);
		switch (i)
		{
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		case 3:
			return w;
		default:
			std::cerr << "error! glvec range out" << std::endl;
			break;
		}
	}

	template<typename T>
	inline glvec<4, T>& glvec<4, T>::operator++()
	{
		++x;
		++y;
		++z;
		++w;
		return *this;
	}
	template<typename T>
	inline glvec<4, T> glvec<4, T>::operator++(int)
	{
		glvec<4, T>res(*this);
		++(*this);
		return *this;
	}
	template<typename T>
	inline glvec<4, T>& glvec<4, T>::operator--()
	{
		--x;
		--y;
		--z;
		--w;
		return *this;
	}
	template<typename T>
	inline glvec<4, T> glvec<4, T>::operator--(int)
	{
		glvec<4, T>res(*this);
		--(*this);
		return *this;
	}
	template<typename T>
	inline glvec<4, T>& glvec<4, T>::operator+=(const T& scalar)
	{
		(*this).x += scalar;
		(*this).y += scalar;
		(*this).z += scalar;
		(*this).w += scalar;
		return (*this);
	}
	template<typename T>
	inline glvec<4, T>& glvec<4, T>::operator+=(const glvec& v1)
	{
		(*this).x += v1.x;
		(*this).y += v1.y;
		(*this).z += v1.z;
		(*this).w += v1.w;
		return (*this);
	}
	template<typename T>
	inline glvec<4, T>& glvec<4, T>::operator-=(const T& scalar)
	{
		(*this).x -= scalar;
		(*this).y -= scalar;
		(*this).z -= scalar;
		(*this).w -= scalar;
		return (*this);
	}
	template<typename T>
	inline glvec<4, T>& glvec<4, T>::operator-=(const glvec& v1)
	{
		(*this).x -= v1.x;
		(*this).y -= v1.y;
		(*this).z -= v1.z;
		(*this).w -= v1.w;
		return (*this);
	}
	template<typename T>
	inline glvec<4, T>& glvec<4, T>::operator*=(const T& scalar)
	{
		(*this).x *= scalar;
		(*this).y *= scalar;
		(*this).z *= scalar;
		(*this).w *= scalar;
		return (*this);
	}
	template<typename T>
	inline glvec<4, T>& glvec<4, T>::operator*=(const glvec& v1)
	{
		(*this).x *= v1.x;
		(*this).y *= v1.y;
		(*this).z *= v1.z;
		(*this).w *= v1.w;
		return (*this);
	}
	template<typename T>
	inline glvec<4, T>& glvec<4, T>::operator/=(const T& scalar)
	{
		(*this).x /= scalar;
		(*this).y /= scalar;
		(*this).z /= scalar;
		(*this).w /= scalar;
		return (*this);
	}
	template<typename T>
	inline glvec<4, T>& glvec<4, T>::operator/=(const glvec& v1)
	{
		(*this).x /= v1.x;
		(*this).y /= v1.y;
		(*this).z /= v1.z;
		(*this).w /= v1.z;
		return (*this);
	}
	template<typename T>
	inline glvec<4, T>& glvec<4, T>::operator%=(const T& scalar)
	{
		(*this).x %= scalar;
		(*this).y %= scalar;
		(*this).z %= scalar;
		(*this).w %= scalar;
		return (*this);
	}
	template<typename T>
	inline glvec<4, T>& glvec<4, T>::operator%=(const glvec& v1)
	{
		(*this).x %= v1.x;
		(*this).y %= v1.y;
		(*this).z %= v1.z;
		(*this).w %= v1.w;
		return (*this);
	}

	template<typename T>
	glvec<4, T> operator+(const glvec<4, T>& v)
	{
		return v;
	}
	template<typename T>
	glvec<4, T> operator-(const glvec<4, T>& v)
	{
		return glvec<4, T>(
			 - v.x,
			 - v.y,
			 - v.z,
			 - v.w
			);
	}

	template<typename T>
	glvec<4, T> operator+(T const& scalar, const glvec<4, T>& v2)
	{
		return glvec<4, T>(
			scalar + v2.x,
			scalar + v2.y,
			scalar + v2.z,
			scalar + v2.w
			);
	}
	template<typename T>
	glvec<4, T> operator-(T const& scalar, const glvec<4, T>& v2)
	{
		return glvec<4, T>(
			scalar - v2.x,
			scalar - v2.y,
			scalar - v2.z,
			scalar - v2.w
			);
	}
	template<typename T>
	glvec<4, T> operator-(const glvec<4, T>& v1, T const& scalar)
	{
		return glvec<4, T>(
			v1.x - scalar,
			v1.y - scalar,
			v1.z - scalar,
			v1.w - scalar
			);
	}
	template<typename T>
	glvec<4, T> operator*(T const& scalar, const glvec<4, T>& v2)
	{
		return glvec<4, T>(
			scalar * v2.x,
			scalar * v2.y,
			scalar * v2.z,
			scalar * v2.w
			);
	}
	template<typename T>
	glvec<4, T> operator/(T const& scalar, const glvec<4, T>& v2)
	{
		return glvec<4, T>(
			scalar / v2.x,
			scalar / v2.y,
			scalar / v2.z,
			scalar / v2.w
			);
	}
	template<typename T>
	glvec<4, T> operator%(T const& scalar, const glvec<4, T>& v2)
	{
		return glvec<4, T>(
			scalar % v2.x,
			scalar % v2.y,
			scalar % v2.z,
			scalar % v2.w
			);
	}

	template<typename T>
	glvec<4, T> operator+(const glvec<4, T>& v1, glvec<4, T> const& v2)
	{
		return glvec<4, T>(
			v1.x + v2.x,
			v1.y + v2.y,
			v1.z + v2.z,
			v1.w + v2.w
			);
	}
	template<typename T>
	glvec<4, T> operator-(const glvec<4, T>& v1, glvec<4, T> const& v2)
	{
		return glvec<4, T>(
			v1.x - v2.x,
			v1.y - v2.y,
			v1.z - v2.z,
			v1.w - v2.w
			);
	}
	template<typename T>
	T operator*(const glvec<4, T>& v1, const glvec<4, T> & v2)
	{
		T a1 = v1.x * v2.x;
		T a2 = v1.y * v2.y;
		T a3 = v1.z * v2.z;
		T a4 = v1.w * v2.w;
		return a1 + a2 + a3 + a4;
	}

}