#include "Spotlight.h"
#include "../../Framework/LightManager.h"

Spotlight* Spotlight::create()
{
	Spotlight* p = new Spotlight();
	if (p)
	{
		p->init();
	}
	return p;
}

Spotlight* Spotlight::create(glmath::vec3 lightColor)
{
	Spotlight* p = new Spotlight(lightColor);
	if (p)
	{
		p->init();
	}
	return p;
}

Spotlight::Spotlight():direction(0.0f),position(0.0f),cutOff(0)
{
}

Spotlight::Spotlight(glmath::vec3 lightColor):Light(lightColor),direction(0.0f), position(0.0f), cutOff(0)
{
}

void Spotlight::draw()
{
}

void Spotlight::update()
{
}

void Spotlight::init()
{
}

void Spotlight::add()
{
	auto& spotlightList = LightManager::getInstance()->getSpotlightList();
	for (size_t i = 0; i < LIGHT_MAX; i++)
	{
		if (spotlightList.find(i) == spotlightList.end())
		{
			spotlightList[i] = this;
		}
	}
}

void Spotlight::remove()
{
	LightManager::getInstance()->getSpotlightList().erase(getTag());
}
