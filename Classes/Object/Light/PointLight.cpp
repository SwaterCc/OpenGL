#include "PointLight.h"
#include "../../Framework/LightManager.h"

PointLight* PointLight::create()
{
	PointLight* p = new PointLight();
	if (p)
	{
		p->init();
	}
	return p;
}

PointLight* PointLight::create(glmath::vec3 lightColor)
{
	PointLight* p = new PointLight(lightColor);
	if (p)
	{
		p->init();
	}
	return p;
}

PointLight::PointLight()
{
}

PointLight::PointLight(glmath::vec3 lightColor):Light(lightColor)
{
	
}

void PointLight::draw()
{
}

void PointLight::update()
{
}

void PointLight::init()
{
}

void PointLight::add()
{
	auto & pointLightList = LightManager::getInstance()->getPointLightList();
	for (size_t i = 0; i < LIGHT_MAX; i++)
	{
		if (pointLightList.find(i) == pointLightList.end())
		{
			pointLightList[i] = this;
		}
	}
}

void PointLight::remove()
{
	LightManager::getInstance()->getPointLightList().erase(getTag());
}
