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
	//�ȴ���ƹ�ĸй��Ƿ���
	m_pDecorated->getProgram()->setUniformOneInt("useLight", m_pDecorated->getIsPhotosensitive());
	//�������еƹ���������ɫ
	LightManager::getInstance()->getParallelLight()->update();

	auto& pointLightList = LightManager::getInstance()->getPointLightList();
	for (auto light : pointLightList)
	{
		light.second->update();
	}
	auto& spotlightList = LightManager::getInstance()->getSpotlightList();
	for (auto light : spotlightList)
	{
		light.second->update();
	}
	/*for_each(spotlightList.begin(), spotlightList.end(), [](std::map<unsigned int, Spotlight*>::reference it) {
		it.second->update();
	});
	for_each(pointLightList.begin(), pointLightList.end(), [](std::map<unsigned int, PointLight*>::reference it) {
		it.second->update();
	});*/

	ObjectDecorator::update();
}

void LightDecorator::draw()
{
	ObjectDecorator::draw();
}
