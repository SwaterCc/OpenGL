#include "Cube.h"
OBJECT_BEGIN
Cube* Cube::create()
{
	auto* p = new Cube();
	if (p)
	{
		p->init();
	}
	return p;
}

void Cube::draw()
{
	m_ShaderProgram->useShaderProgream();
	glBindVertexArray(m_uVAO);

	glDrawArrays(GL_TRIANGLES, 0, 36);
}

void Cube::addTexture()
{
}

void Cube::init()
{
	//VBO
	int len = sizeof(m_CubeVexData) / sizeof(Quad_Vertex);
	m_VertexConfig->setVBO(m_CubeVexData, len);
	//顶点属性
	m_VertexConfig->setup(VERTEX_ATTRIB_POSITION | VERTEX_ATTRIB_COLOR | VERTEX_ATTRIB_TEXTURE);
	//着色器
	GLProgram* program = GLShaderProgreamCatch::getInstance()->getGLProgream(ShaderProgramType_Default);
	setProgram(program);
}

Cube::Cube()
{
	//初始化
	m_CubeVexData[0].p1.vertex = { -0.5f, -0.5f, -0.5f };
	m_CubeVexData[0].p2.vertex = {  0.5f, -0.5f, -0.5f };
	m_CubeVexData[0].p3.vertex = {  0.5f,  0.5f, -0.5f };
	m_CubeVexData[1].p1.vertex = {  0.5f,  0.5f, -0.5f };
	m_CubeVexData[1].p2.vertex = { -0.5f,  0.5f, -0.5f };
	m_CubeVexData[1].p3.vertex = { -0.5f, -0.5f, -0.5f };

	m_CubeVexData[2].p1.vertex = { -0.5f, -0.5f,  0.5f };
	m_CubeVexData[2].p2.vertex = {  0.5f, -0.5f,  0.5f };
	m_CubeVexData[2].p3.vertex = {  0.5f,  0.5f,  0.5f };
	m_CubeVexData[3].p1.vertex = {  0.5f,  0.5f,  0.5f };
	m_CubeVexData[3].p2.vertex = { -0.5f,  0.5f,  0.5f };
	m_CubeVexData[3].p3.vertex = { -0.5f, -0.5f,  0.5f };

	m_CubeVexData[4].p1.vertex = { -0.5f,  0.5f,  0.5f };
	m_CubeVexData[4].p2.vertex = { -0.5f,  0.5f, -0.5f };
	m_CubeVexData[4].p3.vertex = { -0.5f, -0.5f, -0.5f };
	m_CubeVexData[5].p1.vertex = { -0.5f, -0.5f, -0.5f };
	m_CubeVexData[5].p2.vertex = { -0.5f, -0.5f,  0.5f };
	m_CubeVexData[5].p3.vertex = { -0.5f,  0.5f,  0.5f };

	m_CubeVexData[6].p1.vertex = { 0.5f,  0.5f,  0.5f };
	m_CubeVexData[6].p2.vertex = { 0.5f,  0.5f, -0.5f };
	m_CubeVexData[6].p3.vertex = { 0.5f, -0.5f, -0.5f };
	m_CubeVexData[7].p1.vertex = { 0.5f, -0.5f, -0.5f };
	m_CubeVexData[7].p2.vertex = { 0.5f, -0.5f,  0.5f };
	m_CubeVexData[7].p3.vertex = { 0.5f,  0.5f,  0.5f };

	m_CubeVexData[8].p1.vertex = { -0.5f, -0.5f, -0.5f };
	m_CubeVexData[8].p2.vertex = { 0.5f, -0.5f, -0.5f };
	m_CubeVexData[8].p3.vertex = { 0.5f, -0.5f,  0.5f };
	m_CubeVexData[9].p1.vertex = { 0.5f, -0.5f,  0.5f };
	m_CubeVexData[9].p2.vertex = { -0.5f, -0.5f,  0.5f };
	m_CubeVexData[9].p3.vertex = { -0.5f, -0.5f, -0.5f };

	m_CubeVexData[10].p1.vertex = { -0.5f,  0.5f, -0.5f };
	m_CubeVexData[10].p2.vertex = { 0.5f,  0.5f, -0.5f };
	m_CubeVexData[10].p3.vertex = { 0.5f,  0.5f,  0.5f };
	m_CubeVexData[11].p1.vertex = { 0.5f,  0.5f,  0.5f };
	m_CubeVexData[11].p2.vertex = { -0.5f,  0.5f,  0.5f };
	m_CubeVexData[11].p3.vertex = { -0.5f,  0.5f, -0.5f };

	for (int i = 0; i < 12; i++)
	{
		m_CubeVexData[i].p1.color = { 1,0,0 };
		m_CubeVexData[i].p2.color = { 0,1,0 };
		m_CubeVexData[i].p3.color = { 0,0,1 };
	}

	m_TextureCatch.clear();
}

Cube::~Cube()
{
	delete this;
}






OBJECT_END