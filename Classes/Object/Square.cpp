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
	//VAO
	glGenVertexArrays(1, &m_uVAO);
	glBindVertexArray(m_uVAO);

	//VBO
	glGenBuffers(1, &m_uVBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_uVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(m_pSquareVertexData), &m_pSquareVertexData, GL_STATIC_DRAW);
	
	//VEO
	///索引的值必须是uint类型，否则会无法识别
	glGenBuffers(1, &m_uVEO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_uVEO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_pSquareVertexElement), &m_pSquareVertexElement, GL_STATIC_DRAW);
	
	//顶点属性
	glVertexAttribPointer(VertexAttrib_Position, 3, GL_FLOAT, GL_FALSE, SIZE_VERTEX_UNIT, OFFSET_POSITION);
	glVertexAttribPointer(VertexAttrib_Color, 4, GL_FLOAT, GL_FALSE, SIZE_VERTEX_UNIT, OFFSET_COLOR);
	glVertexAttribPointer(VertexAttrib_Texture, 2, GL_FLOAT, GL_FALSE, SIZE_VERTEX_UNIT, OFFSET_TEXTURE);
	
	//属性激活
	for (int i = 0; i < VertexAttrib_MaxNum; i++)
	{
		glEnableVertexAttribArray(i);
	}

	//着色器
	GLProgram * program = GLShaderProgreamCatch::getInstance()->getGLProgream(ShaderProgramType_Default);
	setProgram(program);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Square::draw()
{
	m_ShaderProgram->useShaderProgream();
	glBindVertexArray(m_uVAO);
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