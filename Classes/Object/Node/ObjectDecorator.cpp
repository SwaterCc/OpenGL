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

void ObjectDecorator::updateUniform()
{
	m_pDecorated->updateUniform();
}

void ObjectDecorator::draw()
{
	m_pDecorated->draw();
}

GLProgram* ObjectDecorator::getProgram()
{
	return m_pDecorated->getProgram();
}

Transform& ObjectDecorator::getTransform()
{
	return m_pDecorated->getTransform();
}
