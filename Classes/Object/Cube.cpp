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

}

void Cube::addTexture()
{
}

void Cube::init()
{

}

Cube::Cube()
{
	//≥ı ºªØ
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