#ifndef _Matrix_H_
#define _Matrix_H_
#define GL_MATH_BEGIN namespace gl_math{

#define GL_MATH_END }

#include"../../Include/data.h"
GL_MATH_BEGIN

#include <iostream>
template<typename T>
class Matrix
{
public:
	Matrix(int line,int row,T num);
	~Matrix();

	static Matrix<T> LookAt(Vec3 camreaPosition, Vec3 origin, Vec3 up);
	static Matrix<T> projection(float angle/*角度*/, float Aspect_ratio/*宽高比*/, float near, float far);
public:
	//矩阵变换
	void translation(Vec3 vec3);//平移
	void scaling(Vec3 vec3);//缩放
	void rotation(Vec3 vec3);//旋转
	//
private:
	T* m_pData;
};

template<typename T>
inline Matrix<T>::Matrix(int line, int row, T num)
{
	m_pData = new int[line * row];
	memset(m_pData, 0, sizeof(int) * (line * row));

	for (int i = 0; i < line; i++)
	{
		m_pData[(i * row)] = num;
	}
}

template<typename T>
inline Matrix<T>::~Matrix()
{
	delete m_pData;
}

template<typename T>
inline Matrix<T> Matrix<T>::LookAt(Vec3 camreaPosition, Vec3 origin, Vec3 up)
{
	return Matrix();
}

template<typename T>
inline Matrix<T> Matrix<T>::projection(float angle, float Aspect_ratio, float, float)
{
	return Matrix();
}

template<typename T>
inline void Matrix<T>::translation(Vec3 vec3)
{
}

template<typename T>
inline void Matrix<T>::scaling(Vec3 vec3)
{
}

template<typename T>
inline void Matrix<T>::rotation(Vec3 vec3)
{
}


GL_MATH_END


#endif // !_Matrix_H_
