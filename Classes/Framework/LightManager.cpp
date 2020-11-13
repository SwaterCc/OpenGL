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


LightManager::LightManager()
{
	m_pl = ParallelLight::create();//默认必须有环境光
	m_PointLight.clear();
	m_Spotlight.clear();
}


ParallelLight* LightManager::getParallelLight()
{
	return m_pl;
}

void LightManager::setParallelLight(ParallelLight* p)
{
	if (m_pl)
		delete m_pl;
	m_pl = p;
}

std::map<unsigned int, PointLight*>& LightManager::getPointLightList()
{
	// TODO: 在此处插入 return 语句
	return m_PointLight;
}

std::map<unsigned int, Spotlight*>& LightManager::getSpotlightList()
{
	// TODO: 在此处插入 return 语句
	return m_Spotlight;
}

