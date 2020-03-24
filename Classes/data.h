#ifndef _DATA_H_
#define _DATA_H_



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

#endif // !_DATA_H_
