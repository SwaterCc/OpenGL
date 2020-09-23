#include "LightHandleManager.h"

LightHandleManager* LightHandleManager::m_pInstance = nullptr;

LightHandleManager* LightHandleManager::getInstance()
{
	if (!m_pInstance)
	{
		m_pInstance = new LightHandleManager();
	}
	return m_pInstance;
}

void LightHandleManager::registerHandle(Handle* obj)
{
}

LightHandleManager::LightHandleManager()
{
}

