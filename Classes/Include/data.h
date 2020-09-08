#ifndef _DATA_H_
#define _DATA_H_

#include "../Utility/glmath/glmathlib.h"


const int SIZE_FLOAT = sizeof(float);

typedef unsigned int uint;
typedef unsigned char uchar;

using Point = glmath::vec2;
using uVec3 = glmath::uvec3;

enum ShaderType
{
	VertexShader = 1,
	FragmentShader,
};

typedef struct uniform_fv {
	float v1;
	float v2;
	float v3;
	float v4;
}uniform_fv;

constexpr glmath::vec3 v3(float x, float y, float z) { return glmath::vec3(x, y, z); }
constexpr glmath::vec4 v4(float x, float y, float z, float w) { return glmath::vec4(x, y, z, w); }
constexpr glmath::vec4 c3(float r, float g, float b) { return glmath::vec4(r, g, b, 1.0f); }
constexpr glmath::vec4 c4(float r, float g, float b, float a) { return glmath::vec4(r, g, b, a); }
constexpr glmath::uvec3 uv3(uint x, uint y, uint z) { return glmath::uvec3(x, y, z); }

typedef struct VertexColorTexture_DataStruct{
	glmath::vec3 vertex;
	glmath::vec4 color;
	glmath::vec2 texture;
}VCT_Data;

struct Quad_Vertex{
	VCT_Data rt;
	VCT_Data lt;
	VCT_Data lb;
	VCT_Data rb;
};

struct Triangle_Vertex{
	VCT_Data p1;
	VCT_Data p2;
	VCT_Data p3;
};

struct Size{
	float width;
	float height;
	Size() :width(0), height(0) {}
	Size(float w, float h) :width(w), height(h) {}
};



#define SizeMake(w,h) Size(w,h)
#define PointZero Point(0,0)
#define SIZE_VERTEX_UNIT sizeof(VCT_Data)
#define QUAD_UNIT_NUM (sizeof(glmath::vec3)+sizeof(glmath::vec4)+sizeof(glmath::vec2))
#define OFFSET_POSITION (void*)(0)
#define OFFSET_COLOR (void*)(sizeof(glmath::vec3))
#define OFFSET_TEXTURE (void*)(sizeof(glmath::vec3)+sizeof(glmath::vec4))

#define PI 3.1415926535
#define MVP_MAT "mvp_mat"

#endif // !_DATA_H_
