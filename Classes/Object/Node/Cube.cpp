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

void Cube::update()
{
	if (m_bIsFirstUpDate)
	{ 
		InputVertexData();
		m_bIsFirstUpDate = false;
	}
	ObjectBase::update();
	//this->setRotate((float)glfwGetTime(), { 0,1,0 });
	transform.rotate = { 0, (float)glfwGetTime() / PI * 180, 0 };
}

void Cube::draw()
{
	glBindVertexArray(m_uVAO);
	ObjectBase::draw();

	updateColorUniform();
	updateLightUniform();
	glDrawArrays(GL_TRIANGLES, 0, 36);
}

void Cube::addTexture()
{
}

void Cube::init()
{
	//default
	m_CubeVexData[0].p1.vertex = { -0.5f, -0.5f, -0.5f };
	m_CubeVexData[0].p2.vertex = {	0.5f, -0.5f, -0.5f };
	m_CubeVexData[0].p3.vertex = {	0.5f,  0.5f, -0.5f };
	m_CubeVexData[1].p1.vertex = {	0.5f,  0.5f, -0.5f };
	m_CubeVexData[1].p2.vertex = { -0.5f,  0.5f, -0.5f };
	m_CubeVexData[1].p3.vertex = { -0.5f, -0.5f, -0.5f };

	m_CubeVexData[2].p3.vertex = { -0.5f, -0.5f,  0.5f };
	m_CubeVexData[2].p2.vertex = {	0.5f, -0.5f,  0.5f };
	m_CubeVexData[2].p1.vertex = {	0.5f,  0.5f,  0.5f };
	m_CubeVexData[3].p3.vertex = {	0.5f,  0.5f,  0.5f };
	m_CubeVexData[3].p2.vertex = { -0.5f,  0.5f,  0.5f };
	m_CubeVexData[3].p1.vertex = { -0.5f, -0.5f,  0.5f };

	m_CubeVexData[4].p3.vertex = { -0.5f,  0.5f,  0.5f };
	m_CubeVexData[4].p2.vertex = { -0.5f,  0.5f, -0.5f };
	m_CubeVexData[4].p1.vertex = { -0.5f, -0.5f, -0.5f };
	m_CubeVexData[5].p3.vertex = { -0.5f, -0.5f, -0.5f };
	m_CubeVexData[5].p2.vertex = { -0.5f, -0.5f,  0.5f };
	m_CubeVexData[5].p1.vertex = { -0.5f,  0.5f,  0.5f };

	m_CubeVexData[6].p1.vertex = { 0.5f,  0.5f,  0.5f };
	m_CubeVexData[6].p2.vertex = { 0.5f,  0.5f, -0.5f };
	m_CubeVexData[6].p3.vertex = { 0.5f, -0.5f, -0.5f };
	m_CubeVexData[7].p1.vertex = { 0.5f, -0.5f, -0.5f };
	m_CubeVexData[7].p2.vertex = { 0.5f, -0.5f,  0.5f };
	m_CubeVexData[7].p3.vertex = { 0.5f,  0.5f,  0.5f };

	m_CubeVexData[8].p3.vertex = { -0.5f, -0.5f, -0.5f };
	m_CubeVexData[8].p2.vertex = {	0.5f, -0.5f, -0.5f };
	m_CubeVexData[8].p1.vertex = {	0.5f, -0.5f,  0.5f };
	m_CubeVexData[9].p3.vertex = {	0.5f, -0.5f,  0.5f };
	m_CubeVexData[9].p2.vertex = { -0.5f, -0.5f,  0.5f };
	m_CubeVexData[9].p1.vertex = { -0.5f, -0.5f, -0.5f };

	m_CubeVexData[10].p1.vertex = { -0.5f,  0.5f, -0.5f };
	m_CubeVexData[10].p2.vertex = {	 0.5f,  0.5f, -0.5f };
	m_CubeVexData[10].p3.vertex = {	 0.5f,  0.5f,  0.5f };
	m_CubeVexData[11].p1.vertex = {	 0.5f,  0.5f,  0.5f };
	m_CubeVexData[11].p2.vertex = { -0.5f,  0.5f,  0.5f };
	m_CubeVexData[11].p3.vertex = { -0.5f,  0.5f, -0.5f };


	for (int i = 0; i < 12; i++)
	{
		m_CubeVexData[i].p1.color = c3(1, 1, 1);
		m_CubeVexData[i].p2.color = c3(1, 1, 1);
		m_CubeVexData[i].p3.color = c3(1, 1, 1);
	}

	for (int i = 0; i < 12; i++)
	{

		m_CubeVexData[i].p1.normal = m_CubeVexData[i].getnormal(1);
		m_CubeVexData[i].p2.normal = m_CubeVexData[i].getnormal(2);
		m_CubeVexData[i].p3.normal = m_CubeVexData[i].getnormal(3);
	}

	//��ɫ��
	GLProgram* program = GLShaderProgreamCatch::getInstance()->getGLProgream(ShaderProgramType_Cube);
	setProgram(program);
	m_ShaderProgram->useShaderProgream();
}

void Cube::InputVertexData()
{
	glBindVertexArray(m_uVAO);
	//VBO
	int len = sizeof(m_CubeVexData) / sizeof(Triangle_Vertex);
	m_VertexConfig->setVBO(m_CubeVexData, len);
	//��������
	m_VertexConfig->setup(VERTEX_ATTRIB_POSITION | VERTEX_ATTRIB_COLOR | VERTEX_ATTRIB_TEXTURE | VERTEX_ATTRIB_NORMAL);

}

void Cube::updateColorUniform()
{
	m_ShaderProgram->setUniform4F("_uniformColor", { m_objColor.r,m_objColor.g, m_objColor.b, m_objColor.a });
}

void Cube::updateLightUniform()
{
	m_ShaderProgram->setUniform4MatrixFV("model", transform.getUpdateModelMatrix());
	m_ShaderProgram->setUniform4F("lightPos", { 0,0,4,1 });
	m_ShaderProgram->setUniform4F("lightColor", { 1,1,1,1 });
	m_ShaderProgram->setUniform4F("viewPos", { 0,0,-10.0f,1 });
}

Cube::Cube()
{
	m_TextureCatch.clear();

	m_fWidth = 1;
	m_fHeight = 1;
	m_fDepth = 1;
	m_bIsFirstUpDate = true;
	m_objColor = c4(1,1,1,1);
}

Cube::~Cube()
{
	delete this;
}






OBJECT_END