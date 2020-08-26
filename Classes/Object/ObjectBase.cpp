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

ObjectBase::ObjectBase():m_pObjModelMatrix(glmath::mat4(1.0f)), m_ObjMVPMatrix(0.0f)
{
	m_VertexConfig = new VertexConfig();
	m_ShaderProgram = nullptr;
	m_uProgramTarget = 0;

	m_uVAO = m_VertexConfig->getVAO();
	m_AnchorPoint = PointCenter;
	m_fScale = 1;
}

ObjectBase::~ObjectBase()
{

}

void ObjectBase::draw()
{
	
}

void ObjectBase::update()
{
	m_pObjModelMatrix = { 1.0f };
	m_pObjModelMatrix = updateModelTranslate();
}

void ObjectBase::updateUniformOfShader()
{

}

glmath::mat4 ObjectBase::updateModelTranslate()
{
	glmath::mat4 modelOfUpdate(1.0f);
	
	modelOfUpdate = glmath::scaling(modelOfUpdate, m_fScale);
	glm::rotate()
	modelOfUpdate = glmath::rotation(modelOfUpdate, m_fRadio, m_objRotateAxle);
	modelOfUpdate = glmath::translation(modelOfUpdate, { m_objPosition,0 });

	return modelOfUpdate;
}
