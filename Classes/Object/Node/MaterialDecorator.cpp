#include "MaterialDecorator.h"

MaterialDecorator* MaterialDecorator::create(ObjectBase* obj)
{
	if (obj)
	{
		MaterialDecorator* p = new MaterialDecorator(obj);
		return p;
	}
	return nullptr;
}

MaterialDecorator* MaterialDecorator::create(ObjectBase* obj, Material* material)
{
	if (obj)
	{
		MaterialDecorator* p = new MaterialDecorator(obj, material);
		return p;
	}
	return nullptr;
}

MaterialDecorator::MaterialDecorator(ObjectBase* obj):ObjectDecorator(obj)
{
	material = new Material;
	material->ambientStrenght = 0.1;
	material->diffuseStrenght = 1.0;
	material->specularStrength = 0.5;
	material->shininess = 32;
}

MaterialDecorator::MaterialDecorator(ObjectBase* obj, Material* material):ObjectDecorator(obj)
{
	this->material = material;
}

void MaterialDecorator::update()
{
	ObjectDecorator::update();
	updateMaterialUniform();
}

void MaterialDecorator::draw()
{
	ObjectDecorator::draw();
}

void MaterialDecorator::setAmbientStrenght(float a)
{
	this->material->ambientStrenght = a;
}

void MaterialDecorator::setDiffuseStrenght(float d)
{
	this->material->diffuseStrenght = d;
}

void MaterialDecorator::setSpecularStrength(float s)
{
	this->material->specularStrength = s;
}

void MaterialDecorator::setShininess(float s)
{
	this->material->shininess = s;
}

Material* MaterialDecorator::getMaterial()
{
	return material;
}

void MaterialDecorator::updateMaterialUniform()
{
	m_pDecorated->getProgram()->setUniformOneFloat("material.ambientStrenght", material->ambientStrenght);
	m_pDecorated->getProgram()->setUniformOneFloat("material.diffuseStrenght", material->diffuseStrenght);
	m_pDecorated->getProgram()->setUniformOneFloat("material.specularStrength", material->specularStrength);
	m_pDecorated->getProgram()->setUniformOneFloat("material.shininess", material->shininess);
}
