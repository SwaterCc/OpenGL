#include "Triangle.h"
OBJECT_BEGIN
Triangle* Triangle::create()
{
	auto* p = new Triangle();
	if (p)
	{
		p->init();
	}
	return p;
}

Triangle* Triangle::create(Triangle_Vertex vertex)
{
	auto* p = new Triangle(vertex);
	if (p)
	{
		p->init();
	}
	return p;
}

void Triangle::draw()
{
	m_ShaderProgram->useShaderProgream();
	glBindVertexArray(m_VertexConfig->getVAO());
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

Triangle::Triangle():ObjectBase()
{
	m_VertexData.p1 = { v3(0,0.5f,0),c4(1,0,0,0.5) };
	m_VertexData.p2 = { v3(0.5f,-0.5f,0),c4(0,1,0,0.5) };
	m_VertexData.p3 = { v3(-0.5f,-0.5f,0),c4(0,0,1,0.5) };
}

Triangle::Triangle(Triangle_Vertex vertex):ObjectBase(),m_VertexData(vertex)
{

}

Triangle::~Triangle()
{

}

void Triangle::init()
{
	m_VertexConfig->setVBO(&m_VertexData, 1);
	m_VertexConfig->setup(VERTEX_ATTRIB_POSITION | VERTEX_ATTRIB_COLOR | VERTEX_ATTRIB_TEXTURE);

	auto program = GLShaderProgreamCatch::getInstance()->getGLProgream(ShaderProgramType_Default);
	setProgram(program);
}


OBJECT_END