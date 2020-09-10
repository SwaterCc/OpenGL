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
	m_pMainCamera = Camera::create({ 0,0,-10.0f });
	m_pMainCamera->setProjection(Projection_Perspective);
	m_pMainCamera->setView(m_WindowSize.width, m_WindowSize.height);
	m_pMainCamera->setNearPlane(1.0f);
	m_pMainCamera->setFarPlane(1500.0f);
	m_pMainCamera->setViewAngle(45);
	m_pMainCamera->init();
	m_CameraList[DEFAULT_CAMERA] = m_pMainCamera;
	m_pMainCamera->setActive(true);
}

void RenderPiplineManager::createSence(SenceType type)
{
	if (m_pRunningSence)
	{
		delete m_pRunningSence;
		m_pRunningSence = nullptr;
	}
	
	switch (type)
	{
	case SenceType_Default:
		m_pRunningSence = DefaultSence::create();
		break;
	case SenceType_LightTest:
		m_pRunningSence = LightTestSence::create();
		break;
	default:
		break;
	}

	m_pRunningSence->init();

	if (m_CameraList.size() < 1)
	{
		createMainCamera();
	}
}

glmath::vec4 RenderPiplineManager::getSenceBgColor()
{
	return m_pRunningSence->getSenceBackgroundColor();
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
	m_pRunningSence = nullptr;
}

RenderPiplineManager::~RenderPiplineManager()
{
	m_RenderingList.clear();
}
