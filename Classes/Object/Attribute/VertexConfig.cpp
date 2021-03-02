#include "VertexConfig.h"

VertexConfig::VertexConfig()
{
	m_uVAO = 0;
	m_uVBO = 0;
	m_uVEO = 0;


	initVAO();
}


void VertexConfig::initVAO()
{
	glGenVertexArrays(1,&m_uVAO);
	glBindVertexArray(m_uVAO);

	assert(m_uVAO != 0);
}

void VertexConfig::setVBO(Quad_Vertex * arr, int size, int GL_Type)
{
	glGenBuffers(1, &m_uVBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_uVBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(Quad_Vertex) * size, arr, GL_Type);
}


void VertexConfig::setVBO(std::vector<vertexUnit>& v, int GL_Type)
{
	glGenBuffers(1, &m_uVBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_uVBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexUnit) * v.size(), &v[0], GL_Type);
}

void VertexConfig::setVBO(Triangle_Vertex* arr, int size, int GL_Type)
{
	glGenBuffers(1, &m_uVBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_uVBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(Triangle_Vertex) * size, arr, GL_Type);
}


void VertexConfig::setVEO(uVec3* arr, int size, int GL_Type)
{
	glGenBuffers(1, &m_uVEO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_uVEO);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uVec3) * size, arr, GL_Type);
}

void VertexConfig::setVEO(vector<uint>& v, int GL_Type)
{
	glGenBuffers(1, &m_uVEO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_uVEO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint) * v.size(), &v[0], GL_Type);
}


void VertexConfig::setup(uint target)
{
	glVertexAttribPointer(VertexAttrib_Position	, 3, GL_FLOAT, GL_FALSE, SIZE_VERTEX_UNIT, 0);
	glVertexAttribPointer(VertexAttrib_Color	, 4, GL_FLOAT, GL_FALSE, SIZE_VERTEX_UNIT, (void*)(offsetof(vertexUnit, color)));
	glVertexAttribPointer(VertexAttrib_Texture	, 2, GL_FLOAT, GL_FALSE, SIZE_VERTEX_UNIT, (void*)(offsetof(vertexUnit, texture)));
	glVertexAttribPointer(VertexAttrib_Normal   , 3, GL_FLOAT, GL_FALSE, SIZE_VERTEX_UNIT, (void*)(offsetof(vertexUnit, normal)));

	if (target & VERTEX_ATTRIB_POSITION)
	{
		glEnableVertexAttribArray(VertexAttrib_Position);
	}

	if (target & VERTEX_ATTRIB_COLOR)
	{
		glEnableVertexAttribArray(VertexAttrib_Color);
	}

	if (target & VERTEX_ATTRIB_TEXTURE)
	{
		glEnableVertexAttribArray(VertexAttrib_Texture);
	}

	if (target & VERTEX_ATTRIB_NORMAL)
	{
		glEnableVertexAttribArray(VertexAttrib_Normal);
	}
	//glBindVertexArray(0);
}


VertexConfig::~VertexConfig()
{
	
}
