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
	
	//�������еƹ���������ɫ

	/*auto& pointLightList = LightManager::getInstance()->getPointLightList();
	for (auto light : pointLightList)
	{
		light.second->update();
	}
	auto& spotlightList = LightManager::getInstance()->getSpotlightList();
	for (auto light : spotlightList)
	{
		light.second->update();
	}*/
}

void LightDecorator::updateUniform()
{
	ObjectDecorator::updateUniform();
	//�ȴ���ƹ�ĸй��Ƿ���
	m_pDecorated->getProgram()->setUniformOneInt("useLight", m_pDecorated->getIsPhotosensitive());
	LightManager::getInstance()->getParallelLight()->update(m_pDecorated->getProgram());
	auto& pointLightList = LightManager::getInstance()->getPointLightList();
	for (auto light : pointLightList)
	{
		light.second->update(m_pDecorated->getProgram());
	}
}

void LightDecorator::draw()
{
	ObjectDecorator::draw();
}
