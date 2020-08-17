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
	void scaling(glmatrix<4, 4, T>& mat, float scale)
	{
		glmatrix<4, 4, T> res(1.0);
		res *= scale;
		res *= mat;
		return res;
	}
	template<typename T>  
	void rotation(glmatrix<4, 4, T>& mat, glvec<4, T> v)
	{
		mat[3].x = v.x;
		mat[3].y = v.y;
		mat[3].z = v.z;
		mat[3].w = v.w;
	}
}

#endif // !_glmatrixTrans_
