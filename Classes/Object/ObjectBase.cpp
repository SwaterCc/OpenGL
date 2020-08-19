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

ObjectBase::ObjectBase():m_pObjModelMatrix(glmath::mat4(1.0f))
{
	m_VertexConfig = new VertexConfig();
	m_ShaderProgram = nullptr;
	m_uProgramTarget = 0;

	m_uVAO = m_VertexConfig->getVAO();
	m_AnchorPoint = PointCenter;
}

ObjectBase::~ObjectBase()
{

}

void ObjectBase::update()
{

}
