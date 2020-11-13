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
	m_pl = ParallelLight::create();//Ĭ�ϱ����л�����
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
	// TODO: �ڴ˴����� return ���
	return m_PointLight;
}

std::map<unsigned int, Spotlight*>& LightManager::getSpotlightList()
{
	// TODO: �ڴ˴����� return ���
	return m_Spotlight;
}

