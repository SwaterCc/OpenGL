#ifndef _DATA_H_
#define _DATA_H_

const int SIZE_FLOAT = sizeof(float);

typedef unsigned int uint;
typedef unsigned char uchar;


enum ShaderType
{
	VertexShader = 1,
	FragmentShader,
};


typedef union uniformValue_union {
	int ival;
	uint uval;
	float fval;
}uniformValue_union;


typedef struct uniformValue {
	char tag;
	uniformValue_union uu;
}uniformValue;

typedef struct uniform_fv {
	float v1;
	float v2;
	float v3;
	float v4;
}uniform_fv;

typedef enum SenceType
{
	SenceType_Default = 0,

}SenceType;


typedef struct TextureCoord_Position
{
	float S;
	float T;
	TextureCoord_Position(float s = 0.0f, float t = 0.0f):S(s),T(t) {}
}TextureCoord;


typedef struct ColorData
{
	float R;
	float G;
	float B;
	float A;

	ColorData(float r = 0.0f, float g = 0.0f, float b = 0.0f, float a = 1.0f)
		:R(r),G(g),B(b),A(a) {}
}Color4;
#define c3(r,g,b) ColorData(r,g,b)
#define c4(r,g,b,a) ColorData(r,g,b,a)

typedef struct VertexData_3
{
	float X;
	float Y;
	float Z;

	VertexData_3(float x = 0.0f, float y = 0.0f, float z = 0.0f)
		:X(x), Y(y), Z(z) {}

}Vec3;

typedef struct uVertexData_3
{
	uint X;
	uint Y;
	uint Z;

	uVertexData_3(uint x = 0, uint y = 0, uint z = 0)
		:X(x), Y(y), Z(z) {}

}uVec3;

#define v3(x,y,z) Vec3(x,y,z)
#define uv3(x,y,z) uVec3(x,y,z)

typedef struct VertexData_4
{
	float X;
	float Y;
	float Z;
	float W;

	VertexData_4(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f)
		:X(x), Y(y), Z(z), W(w) {}

}Vec4;

typedef struct VertexColorTexture_DataStruct
{
	Vec3 vertex;
	ColorData color;
	TextureCoord texture;
}VCT_Data;

struct Quad_Vertex
{
	VCT_Data rt;
	VCT_Data lt;
	VCT_Data lb;
	VCT_Data rb;

};

struct Triangle_Vertex
{
	VCT_Data p1;
	VCT_Data p2;
	VCT_Data p3;

};

struct Point
{
	float X;
	float Y;
	Point(float x = 0.0f, float y = 0.0f):X(x),Y(y)
	{}
};

struct Size
{
	float width;
	float height;
	Size() :width(0), height(0) {}
	Size(float w,float h):width(w),height(h){}
};

enum Projection_Type
{
	Projection_ortho = 10,
	Projection_Perspective = 12,
};
#define SizeMake(w,h) Size(w,h)


#define PointZero Point(0,0)
#define PointCenter Point(0.5f,0.5f);

#define SIZE_VERTEX_UNIT sizeof(VCT_Data)
#define QUAD_UNIT_NUM (sizeof(Vec3)+sizeof(ColorData)+sizeof(TextureCoord))
#define OFFSET_POSITION (void*)(0)
#define OFFSET_COLOR (void*)(sizeof(Vec3))
#define OFFSET_TEXTURE (void*)(sizeof(Vec3)+sizeof(ColorData))


#endif // !_DATA_H_
