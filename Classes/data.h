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

	ColorData(float r = 0.0f, float g = 0.0f, float b = 0.0f, float a = 0.0f)
		:R(r),G(g),B(b),A(a) {}
};
#define c3(r,g,b) ColorData(r,g,b)


typedef struct VertexData_3
{
	float X;
	float Y;
	float Z;

	VertexData_3(float x = 0.0f, float y = 0.0f, float z = 0.0f)
		:X(x), Y(y), Z(z) {}

}Vec3;

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

typedef struct Quad_Vertex
{
	VCT_Data rt;
	VCT_Data lt;
	VCT_Data lb;
	VCT_Data rb;
}Quad_Vertex;

#define SIZE_QUAD_UNIT sizeof(VCT_Data)
#define QUAD_UNIT_NUM (sizeof(Vec3)+sizeof(ColorData)+sizeof(TextureCoord))
#define OFFSET_POSITION (void*)(0)
#define OFFSET_COLOR (void*)(sizeof(Vec3))
#define OFFSET_TEXTURE (void*)(sizeof(Vec3)+sizeof(ColorData))

#endif // !_DATA_H_
