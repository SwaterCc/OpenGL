#ifndef _Matrix_H_
#define _Matrix_H_
#include"../../Include/data.h"

#define GL_MATH_BEGIN namespace gl_math{
#define GL_MATH_END }


GL_MATH_BEGIN

#include <iostream>
#include <cmath>
template<typename T>
class Matrix4
{
public:
	Matrix4(T num);
	~Matrix4();

	static Matrix4<T> LookAt(Vec3 camreaPosition, Vec3 origin, Vec3 up);
	static Matrix4<T> projection(float angle/*角度*/, float Aspect_ratio/*宽高比*/, float near, float far);
public:
	//矩阵变换
	void translation(Vec3 vec3);//平移
	void scaling(Vec3 vec3);//缩放
	void rotation(Vec3 vec3);//旋转
	//
private:
	T* m_pData;
	int m_nLine;//矩阵行
	int m_nRow;//矩阵列
};

template<typename T>
inline Matrix4<T>::Matrix4(T num)
{
	m_pData = new T[4 * 4];
	memset(m_pData, 0, sizeof(T) * (4 * 4));

	for (int i = 0; i < 4; i++)
	{
		m_pData[(i * 4) + i] = num;
	}

	m_nLine = 4;
	m_nRow = 4;
}

template<typename T>
inline Matrix4<T>::~Matrix4()
{
	delete m_pData;
}

template<typename T>
inline Matrix4<T> Matrix4<T>::LookAt(Vec3 camreaPosition, Vec3 origin, Vec3 up)
{
	return Matrix();
}

template<typename T>
inline Matrix4<T> Matrix4<T>::projection(float angle, float Aspect_ratio, float, float)
{
	return Matrix();
}

template<typename T>
inline void Matrix4<T>::translation(Vec3 vec3)
{
	m_pData[0 * m_nRow + (m_nRow - 1)] = vec3.X;
	m_pData[1 * m_nRow + (m_nRow - 1)] = vec3.Y;
	m_pData[2 * m_nRow + (m_nRow - 1)] = vec3.Z;
}

template<typename T>
inline void Matrix4<T>::scaling(Vec3 vec3)
{
	m_pData[0 * m_nRow] *= vec3.X;
	m_pData[1 * m_nRow + 1] *= vec3.Y;
	m_pData[2 * m_nRow + 2] *= vec3.Z;
}
//三分量，每个分量代表绕该轴旋转多少值，弧度值
template<typename T>
inline void Matrix4<T>::rotation(Vec3 radios)
{
	if (radios.X)
	{
		/**************************************/
		/* _                                _ */
		/*| cos(radios.z) -sin(radios.z) 0 0 |*/
		/*| sin(radios.z)  cos(radios.z) 0 0 |*/
		/*| 0			   0             1 0 |*/
		/*| 0			   0             0 1 |*/
		/* -                                - */
		/**************************************/

	}
	if (radios.Y)
	{
		/**************************************/
		/* _                                _ */
		/*| cos(radios.z) -sin(radios.z) 0 0 |*/
		/*| 0			   1             0 0 |*/
		/*| sin(radios.z)  cos(radios.z) 0 0 |*/
		/*| 0			   0             0 1 |*/
		/* -                                - */
		/**************************************/
		m_pData[0] *= cos(radios.Z);
		m_pData[1] *= -sin(radios.Z);
		m_pData[8] *= sin(radios.Z);
		m_pData[9] *= cos(radios.Z);
	}
	if (radios.Z)
	{
		/**************************************/
		/* _                                _ */
		/*| cos(radios.z) -sin(radios.z) 0 0 |*/
		/*| sin(radios.z)  cos(radios.z) 0 0 |*/
		/*| 0			   0             1 0 |*/
		/*| 0			   0             0 1 |*/
		/* -                                - */
		/**************************************/
		m_pData[0] *= cos(radios.Z);
		m_pData[1] *= -sin(radios.Z);
		m_pData[4] *= sin(radios.Z);
		m_pData[5] *= cos(radios.Z);
	}
}

#define mat4(n)  Matrix4<float>(n)
#define mat4i(n)  Matrix4<int>(n)
GL_MATH_END


#endif // !_Matrix_H_
