#include "LightDecorator.h"

LightDecorator* LightDecorator::create(ObjectBase* obj)
{
	if(obj)
	{
		LightDecorator* p = new LightDecorator(obj);
		return p;
	}
	return nullptr;
}

LightDecorator::LightDecorator(ObjectBase* obj):ObjectDecorator(obj)
{
	obj->setIsPhotosensitive(1);
}

void LightDecorator::update()
{
	/*for_each(spotlightList.begin(), spotlightList.end(), [](std::map<unsigned int, Spotlight*>::reference it) {
		it.second->update();
	});
	for_each(pointLightList.begin(), pointLightList.end(), [](std::map<unsigned int, PointLight*>::reference it) {
		it.second->update();
	});*/

	ObjectDecorator::update();
}

void LightDecorator::updateUniform()
{
	ObjectDecorator::updateUniform();
	//先传入灯光的感光是否开启
	m_pDecorated->getProgram()->setUniformOneInt("useLight", m_pDecorated->getIsPhotosensitive());
	LightManager::getInstance()->getParallelLight()->update(m_pDecorated->getProgram());
	/*auto& pointLightList = LightManager::getInstance()->getPointLightList();
	for (auto light : pointLightList)
	{
		light.second->update(m_pDecorated->getProgram());
	}
	auto& spotlightList = LightManager::getInstance()->getSpotlightList();
	for (auto light : spotlightList)
	{
		light.second->update(m_pDecorated->getProgram());
	}*/
	auto& pointLightList = LightManager::getInstance()->getPointLightList();
	auto& spotlightList = LightManager::getInstance()->getSpotlightList();
	m_pDecorated->getProgram()->setUniformOneInt("pointLightInputCount", pointLightList.size());
	for_each(pointLightList.begin(), pointLightList.end(), [&](std::map<unsigned int, PointLight*>::reference it) {
		it.second->update(m_pDecorated->getProgram());
	});
	m_pDecorated->getProgram()->setUniformOneInt("spotlightInputCount", spotlightList.size());
	for_each(spotlightList.begin(), spotlightList.end(), [&](std::map<unsigned int, Spotlight*>::reference it) {
		it.second->update(m_pDecorated->getProgram());
	});
}

void LightDecorator::draw()
{
	ObjectDecorator::draw();
}
