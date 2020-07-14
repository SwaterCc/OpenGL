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

ObjectBase::ObjectBase()
{
	m_uVAO = 0;
	m_uVBO = 0;
	m_ShaderProgram = nullptr;
	m_uProgramTarget = 0;

	m_AnchorPoint = PointCenter;
}

ObjectBase::~ObjectBase()
{

}
