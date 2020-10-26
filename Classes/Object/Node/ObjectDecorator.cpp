#include "ObjectDecorator.h"

ObjectDecorator* ObjectDecorator::create(ObjectBase* obj)
{
	if (obj)
	{
		ObjectDecorator* p = new ObjectDecorator(obj);
		return p;
	}
}

ObjectDecorator::ObjectDecorator(ObjectBase* obj)
{
	m_pDecorated = obj;
}

void ObjectDecorator::update()
{
	m_pDecorated->update();
}

void ObjectDecorator::UpdateUniform()
{
	m_pDecorated->UpdateUniform();
}

void ObjectDecorator::draw()
{
	m_pDecorated->draw();
}

Transform& ObjectDecorator::getTransform()
{
	return m_pDecorated->getTransform();
}
