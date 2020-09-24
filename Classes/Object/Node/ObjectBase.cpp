#include "ObjectBase.h"

ObjectBase* ObjectBase::create()
{
	ObjectBase* p = new ObjectBase();
	if (p)
	{
		p->init();
	}
	return p;
}
void ObjectBase::setVertexConfig(VertexConfig* config)
{
	m_VertexConfig = config;
}
ObjectBase::ObjectBase(): m_ObjMVPMatrix(0.0f)
{
	m_VertexConfig = new VertexConfig();
	m_ShaderProgram = nullptr;
	m_uProgramTarget = 0;

	m_uVAO = m_VertexConfig->getVAO();
	m_AnchorPoint = AnchorPoint_Center;
}

ObjectBase::~ObjectBase()
{

}

void ObjectBase::draw()
{
	
}

void ObjectBase::update()
{
	transform.update();
}

void ObjectBase::updateUniformOfShader()
{
	m_ShaderProgram->setUniform4MatrixFV(MVP_MAT, m_ObjMVPMatrix);
}

