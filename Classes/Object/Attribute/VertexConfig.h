#ifndef _VertexConfig_h_
#define _VertexConfig_h_

#include<iostream>

#include"../../Include/makeFileInclude.h"
#include"../../Include/Include.h"
		 
#define VERTEX_ATTRIB_POSITION  1
#define VERTEX_ATTRIB_COLOR  2
#define VERTEX_ATTRIB_TEXTURE  4
#define VERTEX_ATTRIB_NORMAL  8

using namespace std;

enum {
	VertexAttrib_Position = 0,
	VertexAttrib_Color = 1,
	VertexAttrib_Texture = 2,
	VertexAttrib_Normal = 3,
	VertexAttrib_MaxNum,
};

class VertexConfig
{
public:
	VertexConfig();
	~VertexConfig();

	void initVAO();
	void setVBO(Quad_Vertex * arr, int size, int GL_Type = GL_STATIC_DRAW);
	void setVBO(Triangle_Vertex * arr, int size, int GL_Type = GL_STATIC_DRAW);
	void setVEO(uVec3 * arr,int size, int GL_Type = GL_STATIC_DRAW);
	virtual void setup(uint target);
	
    virtual void updateVertexAttrib() {}


	GLuint getVAO() { return m_uVAO; }
	GLuint getVBO() { return m_uVBO; }
	GLuint getVEO() { return m_uVEO; }
protected:
	
	GLuint m_uVAO;
	GLuint m_uVBO;
	GLuint m_uVEO;
};



#endif // !_VertexConfig_h_


