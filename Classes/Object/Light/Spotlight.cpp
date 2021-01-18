#include "Spotlight.h"
#include "../../Framework/LightManager.h"
#include <cmath>
#include "../../Utility/commonFunc.h"
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
	outCutOff = cos(radios(15));
}

void Spotlight::draw()
{
}

void Spotlight::update(GLProgram* program)
{
	program->setUniform3F(formatStr("spotlight[%d].position",getTag()), position);
	program->setUniform4F(formatStr("spotlight[%d].lightColor", getTag()), glmath::vec4(m_lightColor, 1));
	program->setUniform3F(formatStr("spotlight[%d].lightDir", getTag()), direction);
	program->setUniformOneFloat(formatStr("spotlight[%d].cutOff", getTag()), cutOff);
	program->setUniformOneFloat(formatStr("spotlight[%d].outCutOff", getTag()), outCutOff);
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
			setTag(i);
			break;
		}
	}
}

void Spotlight::remove()
{
	LightManager::getInstance()->getSpotlightList().erase(getTag());
}
