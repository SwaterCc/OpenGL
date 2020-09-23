#include "LightManager.h"

LightManager* LightManager::m_pInstance = nullptr;

LightManager* LightManager::getInstance()
{
	if (!m_pInstance)
	{
		m_pInstance = new LightManager();
	}
	return m_pInstance;
}

void LightManager::registerLight(Light* obj)
{
}

LightManager::LightManager()
{
}
