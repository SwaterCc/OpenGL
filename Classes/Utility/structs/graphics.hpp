#ifndef _graphics_triangle_
#define _graphics_triangle_

#include "../glmath/glmathlib.h"

typedef struct VertexColorTexture_DataStruct {
	glmath::vec3 vertex;
	glmath::vec4 color;
	glmath::vec2 texture;
	glmath::vec3 normal;
}vertexUnit;

class graphics_triangle
{
public:
	vertexUnit p1;
	vertexUnit p2;
	vertexUnit p3;
public:
	glmath::vec3 getnormal(int i) {
		
		glmath::vec3 res;
		glmath::vec3 t1;
		glmath::vec3 t2;
		switch (i)
		{
		case 1://p1的法向量
			t1 = p2.vertex - p1.vertex;
			t2 = p3.vertex - p1.vertex;
			res = glmath::cross(glmath::normalize(t1), glmath::normalize(t2));
		case 2:
			t1 = p1.vertex - p2.vertex;
			t2 = p3.vertex - p2.vertex;
			res = glmath::cross(glmath::normalize(t1), glmath::normalize(t2));
		case 3:
			t1 = p1.vertex - p3.vertex;
			t2 = p2.vertex - p3.vertex;
			res = glmath::cross(glmath::normalize(t1), glmath::normalize(t2));
		default:
			break;
		}
		return res;
	}
};





#endif // _graphics_template_
