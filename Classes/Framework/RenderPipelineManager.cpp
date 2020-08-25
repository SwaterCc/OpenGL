#include "RenderPipelineManager.h"
#include "../Object/ObjectBase.h"
#include "../Sence/SenceInclude.h"
#include "GLShaderProgreamCatch.h"

constexpr int DEFAULT_CAMERA = 0;

RenderPiplineManager* RenderPiplineManager::m_pInstance = nullptr;

int RenderPiplineManager::m_nRenderListCount = 0;
int RenderPiplineManager::m_nCameraListCount = 1;

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
		if (m_pMainCamera && m_pMainCamera->getActive())
		{
			m_pMainCamera->makeObjectTransfomation(it->second);
		}
		else
		{
			std::cerr << "Wanning MainCamera Not Active or is NULL" << std::endl;
		}

		(it->second)->draw();
		glBindVertexArray(0);
	}
}

void RenderPiplineManager::addObjectToList(ObjectBase* object,int & tag)
{
	tag = m_nRenderListCount;
	m_RenderingList[m_nRenderListCount] = object;
	++m_nRenderListCount;
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

void RenderPiplineManager::addCameraToList(Camera* obj)
{
	obj->setTag(m_nCameraListCount);
	m_CameraList[m_nCameraListCount] = obj;
	++m_nCameraListCount;
}

void RenderPiplineManager::removeCameraAtIndex(int idx)
{
	auto it = m_CameraList.find(idx);
	if (it != m_CameraList.end())
	{
		m_CameraList.erase(it);
		return;
	}
	//OutputDebugString
	return;
}

void RenderPiplineManager::createMainCamera()
{
	m_pMainCamera = Camera::create({ 0,0,3 });
	m_pMainCamera->setView(m_WindowSize.width, m_WindowSize.height);
	m_pMainCamera->setNearPlane(10.0f);
	m_pMainCamera->setFarPlane(500.0f);

	m_CameraList[DEFAULT_CAMERA] = m_pMainCamera;
	m_pMainCamera->setActive(true);
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

	if (m_CameraList.size() < 1)
	{
		createMainCamera();
	}
}

void RenderPiplineManager::setMainCamera(Camera* c)
{
	assert(c);
	{
		m_CameraList[m_nCameraListCount] = c;
		m_pMainCamera = m_CameraList[m_nCameraListCount];
	}
	
}

RenderPiplineManager::RenderPiplineManager()
{
	m_RenderingList.clear();
	m_CameraList.clear();
	m_pMainCamera = nullptr;
	m_pProgramCatchInstance = GLShaderProgreamCatch::getInstance();
	m_WindowSize = { 0,0 };

}

RenderPiplineManager::~RenderPiplineManager()
{
	m_RenderingList.clear();
}
