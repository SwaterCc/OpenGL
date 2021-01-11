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
	direction = glmath::vec3(-0.2f, -1.0f, -0.3f);
	color = glmath::vec3(1);
}

ParallelLight::ParallelLight(glmath::vec3 d, glmath::vec3 lightColor):Light(lightColor)
{
	direction = glmath::vec3(0);
	color = glmath::vec3(lightColor);
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
