#include"vec/glvec2.hpp"
#include"vec/glvec3.hpp"
#include"vec/glvec4.hpp"
#include"matrix/glmatrix2x2.hpp"
#include"matrix/glmatrix3x3.hpp"
#include"matrix/glmatrix4x4.hpp"
#include"vec/glvecMathEx.hpp"

namespace glmath
{
	typedef		glvec<2, int8_t>		i8vec2;
	typedef		glvec<2, uint8_t>		u8vec2;
	typedef		glvec<2, int16_t>		i16vec2;
	typedef		glvec<2, uint16_t>		u16vec2;
	typedef		glvec<2, int>			ivec2;
	typedef		glvec<2, unsigned int>	uvec2;
	typedef		glvec<2, float>			vec2;
	typedef		glvec<2, double>		dvec2;

	typedef		glvec<3, int8_t>		i8vec3;
	typedef		glvec<3, uint8_t>		u8vec3;
	typedef		glvec<3, int16_t>		i16vec3;
	typedef		glvec<3, uint16_t>		u16vec3;
	typedef		glvec<3, int>			ivec3;
	typedef		glvec<3, unsigned int>	uvec3;
	typedef		glvec<3, float>			vec3;
	typedef		glvec<3, double>		dvec3;

	typedef		glvec<4, int8_t>		i8vec4;
	typedef		glvec<4, uint8_t>		u8vec4;
	typedef		glvec<4, int16_t>		i16vec4;
	typedef		glvec<4, uint16_t>		u16vec4;
	typedef		glvec<4, int>			ivec4;
	typedef		glvec<4, unsigned int>	uvec4;
	typedef		glvec<4, float>			vec4;
	typedef		glvec<4, double>		dvec4;

	typedef		glmatrix<2, 2, int8_t>			i8mat2;
	typedef		glmatrix<2, 2, uint8_t>			u8mat2;
	typedef		glmatrix<2, 2, int16_t>			i16mat2;
	typedef		glmatrix<2, 2, uint16_t>		u16mat2;
	typedef		glmatrix<2, 2, int>				imat2;
	typedef		glmatrix<2, 2, unsigned int>	umat2;
	typedef		glmatrix<2, 2, float>			mat2;
	typedef		glmatrix<2, 2, double>			dmat2;

	typedef		glmatrix<3, 3, int8_t>			i8mat3;
	typedef		glmatrix<3, 3, uint8_t>			u8mat3;
	typedef		glmatrix<3, 3, int16_t>			i16mat3;
	typedef		glmatrix<3, 3, uint16_t>		u16mat3;
	typedef		glmatrix<3, 3, int>				imat3;
	typedef		glmatrix<3, 3, unsigned int>	umat3;
	typedef		glmatrix<3, 3, float>			mat3;
	typedef		glmatrix<3, 3, double>			dmat3;

	typedef		glmatrix<4, 4, int8_t>			i8mat4;
	typedef		glmatrix<4, 4, uint8_t>			u8mat4;
	typedef		glmatrix<4, 4, int16_t>			i16mat4;
	typedef		glmatrix<4, 4, uint16_t>		u16mat4;
	typedef		glmatrix<4, 4, int>				imat4;
	typedef		glmatrix<4, 4, unsigned int>	umat4;
	typedef		glmatrix<4, 4, float>			mat4;
	typedef		glmatrix<4, 4, double>			dmat4;
}			