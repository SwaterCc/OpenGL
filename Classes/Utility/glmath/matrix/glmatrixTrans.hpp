#ifndef _glmatrixTrans_
#define _glmatrixTrans_
#include"glmatrix4x4.hpp"
namespace glmath {
	template<typename T>  
	glmatrix<4, 4, T>& translation(glmatrix<4, 4, T>& mat, glvec<4, T> v)
	{
		glmatrix<4, 4, T> res(1.0);
		res[3] += v;
		res *= mat;
		return res;
	}
	template<typename T>  
	glmatrix<4, 4, T>& scaling(glmatrix<4, 4, T>& mat, float scale)
	{
		glmatrix<4, 4, T> res(1.0);
		res *= scale;
		res *= mat;
		return res;
	}
	template<typename T>  
	glmatrix<4, 4, T>& rotation(glmatrix<4, 4, T>& mat, float radios, glvec<3, T> r)//radios ª°∂»÷∆
	{
		float cosRad = cos(radios);
		float mCosRad = 1 - cosRad;
		float sinRad = sin(radios);

		glmatrix<4, 4, T> temp = {
			{cosRad + r.x * r.x * mCosRad,			r.x * r.y * mCosRad - r.z*sinRad,	r.x * r.z * mCosRad + r.y * sinRad,	0 },
			{r.y * r.x * mCosRad + r.z * sinRad,	cosRad + r.y * r.y * mCosRad,		r.y * r.z * mCosRad - r.x * sinRad,	0 },
			{r.z * r.x * mCosRad - r.y * sinRad,	r.z * r.y * mCosRad + r.x + sinRad,	cosRad + r.z * r.z * mCosRad,		0 },
			{0,									0,									 0,										1 }
		};

		glmatrix<4,4,T> res = temp * mat;
		return res;
	}
}

#endif // !_glmatrixTrans_
