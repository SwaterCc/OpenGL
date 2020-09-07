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
	m_AnchorPoint = AnchorPoint_Center;
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
	m_ShaderProgram->setUniform4MatrixFV(MVP_MAT, m_ObjMVPMatrix);
}

glmath::mat4 ObjectBase::updateModelTranslate()
{
	glmath::mat4 modelOfUpdate(1.0f);

	modelOfUpdate = glmath::scaling(modelOfUpdate, m_fScale);
	modelOfUpdate = glmath::rotation(modelOfUpdate, m_fRadio, m_objRotateAxle);
	modelOfUpdate = glmath::translation(modelOfUpdate, { m_objPosition,0 });

	return modelOfUpdate;
}
