#include "RenderPipelineManager.h"
#include "ObjectBase.h"
#include "SenceInclude.h"
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
		(it->second)->draw();
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
	m_pProgramCatchInstance = GLShaderProgreamCatch::getInstance();
}

RenderPiplineManager::~RenderPiplineManager()
{
	m_RenderingList.clear();
}
