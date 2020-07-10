#include "Square.h"
#include "GLShaderProgreamCatch.h"
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
	cout << "sizeof(m_pSquareVertexData):" << sizeof(m_pSquareVertexData) << endl;;
	//VEO
	glGenBuffers(1, &m_uVEO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_uVEO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_pSquareVertexElement), m_pSquareVertexElement, GL_STATIC_DRAW);
	cout << "sizeof(m_pSquareVertexElement):" << sizeof(m_pSquareVertexElement) << endl;;
	//顶点属性
	glVertexAttribPointer(VertexAttrib_Position, 3, GL_FLOAT, GL_FALSE, QUAD_UNIT_NUM, OFFSET_POSITION);
	glVertexAttribPointer(VertexAttrib_Color, 4, GL_FLOAT, GL_FALSE, QUAD_UNIT_NUM, OFFSET_COLOR);
	glVertexAttribPointer(VertexAttrib_Texture, 2, GL_FLOAT, GL_FALSE, QUAD_UNIT_NUM, OFFSET_TEXTURE);
	cout << "QUAD_UNIT_NUM:" << QUAD_UNIT_NUM << endl;;
	cout << "OFFSET_TEXTURE:" << sizeof(Vec3)+ sizeof(ColorData) << endl;;

	//属性激活
	for (int i = 0; i < VertexAttrib_MaxNum; i++)
	{
		glEnableVertexAttribArray(i);
	}

	//着色器
	GLProgram * program = GLShaderProgreamCatch::getInstance()->getGLProgream(ShaderProgramType_Default);
	setProgram(program);
}

void Square::draw()
{
	m_uShaderProgram->useShaderProgream();

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
Square::Square() :ObjectBase()
{
	m_uVEO = 0;

	m_pSquareVertexData.rt = {Vec3(0.5,0.5),c3(1,1,1)};
	m_pSquareVertexData.lt = { Vec3(-0.5,0.5),c3(1,1,1) };
	m_pSquareVertexData.lb = { Vec3(-0.5,-0.5),c3(1,1,1) };
	m_pSquareVertexData.rb = { Vec3(0.5,-0.5),c3(1,1,1) };

	m_pSquareVertexElement[0] = { Vec3(0,1,2) };
	m_pSquareVertexElement[1] = { Vec3(0,2,3) };
}
Square::~Square()
{
}
OBJECT_END