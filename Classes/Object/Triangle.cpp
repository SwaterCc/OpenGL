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
	glBindVertexArray(m_uVAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

Triangle::Triangle():ObjectBase()
{
	m_VertexData.p1 = {v3(0,0.5f,0),c4(1,0,0,0.5)};
	m_VertexData.p2 = { v3(0.5f,-0.5f,0),c4(0,1,0,0.5) };
	m_VertexData.p3 = { v3(-0.5f,-0.5f,0),c4(0,0,1,0.5) };
}

Triangle::Triangle(Triangle_Vertex vertex):ObjectBase(),m_VertexData(vertex)
{

}

Triangle::~Triangle()
{
	delete this;
}

void Triangle::init()
{
	glGenVertexArrays(1, &m_uVAO);
	glBindVertexArray(m_uVAO);

	glGenBuffers(1, &m_uVBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_uVBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(Triangle_Vertex), &m_VertexData, GL_STATIC_DRAW);

	glVertexAttribPointer(VertexAttrib_Position, 3, GL_FLOAT, GL_FALSE, SIZE_VERTEX_UNIT, OFFSET_POSITION);
	glVertexAttribPointer(VertexAttrib_Color, 4, GL_FLOAT, GL_FALSE, SIZE_VERTEX_UNIT, OFFSET_COLOR);
	glVertexAttribPointer(VertexAttrib_Texture, 2, GL_FLOAT, GL_FALSE, SIZE_VERTEX_UNIT, OFFSET_TEXTURE);

	for (size_t i = 0; i < VertexAttrib_MaxNum; i++)
	{
		glEnableVertexAttribArray(i);
	}

	auto program = GLShaderProgreamCatch::getInstance()->getGLProgream(ShaderProgramType_Default);
	setProgram(program);

	glBindVertexArray(0);
}


OBJECT_END