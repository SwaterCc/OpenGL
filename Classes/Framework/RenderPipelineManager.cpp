#include "RenderPipelineManager.h"
#include "../Object/ObjectBase.h"
#include "../Sence/SenceInclude.h"
#include "GLShaderProgreamCatch.h"

RenderPiplineManager* RenderPiplineManager::m_pInstance = nullptr;
int RenderPiplineManager::m_nListCount = 0;

RenderPiplineManager* RenderPiplineManager::getInstance()
{
	if (!m_pInstance)
	{
		m_pInstance = new RenderPiplineManager();
	}
	return m_pInstance;
}

void RenderPiplineManager::mainLoop()
{
	RenderingList::iterator it;
	for (it = m_RenderingList.begin(); it != m_RenderingList.end(); it++)
	{
		(it->second)->update();//此步执行model变换

		//vp变换
		m_pDefaultCamera->makeObjectTransfomation(it->second);
		
		(it->second)->draw();
		glBindVertexArray(0);
	}
}

void RenderPiplineManager::addObjectToList(ObjectBase* object,int & tag)
{
	tag = m_nListCount;
	m_RenderingList[m_nListCount] = object;
	m_nListCount++;
}

void RenderPiplineManager::removeObjectAtIndex(int idx)
{
	auto it = m_RenderingList.find(idx);
	if (it != m_RenderingList.end())
	{
		m_RenderingList.erase(it);
		return;
	}
	//OutputDebugString
	return;
}

void RenderPiplineManager::createSence(SenceType type)
{
	ISence* p = nullptr;

	switch (type)
	{
	case SenceType_Default:
		p = DefaultSence::create();
		break;
	default:
		break;
	}

	p->init();
}

RenderPiplineManager::RenderPiplineManager()
{
	m_RenderingList.clear();
	m_CameraList.clear();
	m_pDefaultCamera = 0;
	m_pProgramCatchInstance = GLShaderProgreamCatch::getInstance();
	m_WindowSize = { 0,0 };

}

RenderPiplineManager::~RenderPiplineManager()
{
	m_RenderingList.clear();
}
