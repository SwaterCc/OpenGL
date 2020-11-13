#include "Light.h"

Light* Light::create()
{
	Light* p = new Light();
	if (p)
	{
		return p;
	}
	return nullptr;
}

Light* Light::create(glmath::vec3 lightColor)
{
	Light* p = new Light(lightColor);
	if (p)
	{
		return p;
	}
	return nullptr;
}

Light::Light():m_lightColor(1)
{
	tag = -1;
}

Light::Light(glmath::vec3 lightColor):m_lightColor(lightColor)
{
	tag = -1;
}

void Light::draw()
{
}

void Light::update()
{

}
