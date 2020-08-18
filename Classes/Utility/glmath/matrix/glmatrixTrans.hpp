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
	glmatrix<4, 4, T>& rotation(glmatrix<4, 4, T>& mat,float radios, glvec<3, T> v)
	{
		glmatrix<4, 4, T> res(1.0);
	}
}

#endif // !_glmatrixTrans_
