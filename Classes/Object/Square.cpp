#include "Square.h"

OBJECT_BEGIN

Square* Square::create()
{
	Square* p = new Square();
	if (p)
	{
		p->init();
	}
	return p;
}


void Square::init()
{
	m_VertexConfig->setVBO(&m_pSquareVertexData, 1);
	m_VertexConfig->setVEO(m_pSquareVertexElement, 2);
	m_VertexConfig->setup(VERTEX_ATTRIB_POSITION | VERTEX_ATTRIB_COLOR);
	//×ÅÉ«Æ÷
	GLProgram * program = GLShaderProgreamCatch::getInstance()->getGLProgream(ShaderProgramType_Default);
	setProgram(program);
}

void Square::draw()
{
	m_ShaderProgram->useShaderProgream();
	glBindVertexArray(m_VertexConfig->getVAO());
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
Square::Square() :ObjectBase()
{
	m_uVEO = 0;

	m_pSquareVertexData.rt = {Vec3(0.5,0.5,0),c3(0.5,1,1)};
	m_pSquareVertexData.lt = { Vec3(0.5,-0.5,0),c3(1,0.5,1) };
	m_pSquareVertexData.lb = { Vec3(-0.5,-0.5,0),c3(1,1,0.5) };
	m_pSquareVertexData.rb = { Vec3(-0.5,0.5,0),c3(1,1,1) };

	m_pSquareVertexElement[0] = { uVec3(0, 1, 3) };
	m_pSquareVertexElement[1] = { uVec3(1, 2, 3) };
}
Square::~Square()
{
}
OBJECT_END