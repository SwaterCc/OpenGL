#include "TransformAdapter.h"
TransformAdapter * TransformAdapter::m_pInstance = nullptr;
TransformAdapter * TransformAdapter::getInstance()
{
	if (!m_pInstance)
	{
		m_pInstance = new TransformAdapter();
	}
	return m_pInstance;
}

void TransformAdapter::setPosition(ObjectBase * target, glmath::vec3 pos)
{
	target->getTransform().position = pos;
}

void TransformAdapter::setScale(ObjectBase * target, glmath::vec3 scale)
{
	target->getTransform().scale = scale;
}

void TransformAdapter::setScale(ObjectBase * target, float scale)
{
	target->getTransform().scale = glmath::vec3(scale);
}

void TransformAdapter::setRotate(ObjectBase * target, glmath::vec3 rotate)
{
	target->getTransform().rotate = rotate;
}
