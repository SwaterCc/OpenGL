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

ParallelLight* ParallelLight::create(glmath::vec3 lightColor)
{
	ParallelLight* p = new ParallelLight(lightColor);
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

ParallelLight::ParallelLight(glmath::vec3 lightColor):Light(lightColor)
{
	direction = glmath::vec3(0);
}

void ParallelLight::draw()
{
}

void ParallelLight::update()
{
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
