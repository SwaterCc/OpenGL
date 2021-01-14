#include "Spotlight.h"
#include "../../Framework/LightManager.h"
#include <cmath>

Spotlight* Spotlight::create()
{
	Spotlight* p = new Spotlight();
	if (p)
	{
		p->init();
	}
	return p;
}

Spotlight* Spotlight::create(glmath::vec3 pos, glmath::vec3 dir, float height, float radius, glmath::vec3 lightColor)
{
	Spotlight* p = new Spotlight(pos, dir, height, radius, lightColor);
	if (p)
	{
		p->init();
	}
	return p;
}

Spotlight::Spotlight():direction(0.0f),position(0.0f),cutOff(0)
{
}

Spotlight::Spotlight(glmath::vec3 pos, glmath::vec3 dir, float height, float radius, glmath::vec3 lightColor):Light(lightColor),direction(dir), position(pos)
{
	cutOff = height / sqrt(height * height + radius * radius);
}

void Spotlight::draw()
{
}

void Spotlight::update(GLProgram* program)
{
	program->setUniform3F("spotlight.position", position);
	program->setUniform4F("spotlight.lightColor", glmath::vec4(m_lightColor, 1));
	program->setUniform3F("spotlight.lightDir", direction);
	program->setUniformOneFloat("spotlight.cutOff", cutOff);
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
