#include "ObjectBase.h"

ObjectBase::ObjectBase()
{
	m_VertexConfig = new VertexConfig();
	m_ShaderProgram = nullptr;
	m_uProgramTarget = 0;

	m_uVAO = m_VertexConfig->getVAO();
	m_AnchorPoint = AnchorPoint_Center;
	m_bIsPhotosensitive = false;
}

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


ObjectBase::~ObjectBase()
{

}

//void ObjectBase::addToRenderingList()
//{
//	RenderPiplineManager::getInstance()->addObjectToList(this, _nRenderTag);
//}
//
//void ObjectBase::removeToRenderingList()
//{
//	RenderPiplineManager::getInstance()->removeObjectAtIndex(getRenderTag());
//}

void ObjectBase::draw()
{
	
}

void ObjectBase::update()
{
	m_ShaderProgram->setUniform4MatrixFV("model", transform.getUpdateModelMatrix());
	transform.update();
}

void ObjectBase::updateUniform()
{
	updateUniformOfShader();
}

int & ObjectBase::getRenderTag()
{
	return _nRenderTag;
}

Transform & ObjectBase::getTransform()
{
	return transform;
}

void ObjectBase::setProgram(GLProgram * GLProgram)
{
	m_ShaderProgram = GLProgram;
	m_uProgramTarget = m_ShaderProgram->getShaderProgram();
}

GLProgram* ObjectBase::getProgram()
{
	return m_ShaderProgram;
}

void ObjectBase::setIsPhotosensitive(int isPs)
{
	m_bIsPhotosensitive = isPs;
}

int ObjectBase::getIsPhotosensitive()
{
	return m_bIsPhotosensitive;
}

void ObjectBase::init()
{
}

void ObjectBase::updateUniformOfShader()
{
	m_ShaderProgram->setUniform4MatrixFV(MVP_MAT, transform.getMVPMatrix());
}

