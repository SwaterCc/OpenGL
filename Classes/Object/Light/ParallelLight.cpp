#include "ParallelLight.h"
#include "../../Framework/LightManager.h"

ParallelLight* ParallelLight::create()
{
	ParallelLight* p = new ParallelLight();
	if (p)
	{
		p->init();
	}
	return p;
}

ParallelLight* ParallelLight::create(glmath::vec3 d, glmath::vec3 lightColor)
{
	ParallelLight* p = new ParallelLight(d, lightColor);
	if (p)
	{
		p->init();
	}
	return p;
}

ParallelLight::ParallelLight()
{
	direction = glmath::vec3(0);
}

ParallelLight::ParallelLight(glmath::vec3 d, glmath::vec3 lightColor):Light(lightColor)
{
	direction = d;
}

void ParallelLight::draw()
{
}

void ParallelLight::update(GLProgram * program)
{
	program->setUniform4F("parallelLight.lightDir", glmath::vec4(direction, 0));
	program->setUniform4F("parallelLight.lightColor", glmath::vec4(m_lightColor, 1));
}

void ParallelLight::init()
{

}

void ParallelLight::add()
{
	LightManager::getInstance()->setParallelLight(this);
}

void ParallelLight::remove()
{
	LightManager::getInstance()->setParallelLight(nullptr);
}
