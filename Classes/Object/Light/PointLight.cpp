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

PointLight* PointLight::create(glmath::vec3 pos,float constant,float linear,float quadratic ,glmath::vec3 lightColor)
{
	PointLight* p = new PointLight(pos,constant,linear,quadratic,lightColor);
	if (p)
	{
		p->init();
	}
	return p;
}

PointLight::PointLight()
{
}

PointLight::PointLight(glmath::vec3 pos, float c, float l, float q, glmath::vec3 lightColor):Light(lightColor),
	position(pos),constant(c),linear(l),quadratic(q)
{
	
}

void PointLight::draw()
{
}

void PointLight::update(GLProgram* program)
{
	program->setUniform3F("pointLight.position", position);
	program->setUniform4F("pointLight.lightColor", glmath::vec4(m_lightColor, 1));
	program->setUniformOneFloat("pointLight.constant", constant);
	program->setUniformOneFloat("pointLight.linear", linear);
	program->setUniformOneFloat("pointLight.quadratic", quadratic);
}

void PointLight::setPos(glmath::vec3 pos)
{
	position = pos;
}

void PointLight::setConstant(float c)
{
	constant = c;
}

void PointLight::setLinear(float l)
{
	linear = l;
}

void PointLight::setQuadratic(float q)
{
	quadratic = q;
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
			break;
		}
	}
}

void PointLight::remove()
{
	LightManager::getInstance()->getPointLightList().erase(getTag());
}
