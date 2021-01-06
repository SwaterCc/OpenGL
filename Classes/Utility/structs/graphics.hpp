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
		glmath::vec3 t1 = p1.vertex - p2.vertex;
		glmath::vec3 t2 = p2.vertex - p3.vertex;

		res = glmath::normalize(glmath::cross(glmath::normalize(t2), glmath::normalize(t1)));
		return res;
	}
};





#endif // _graphics_template_
