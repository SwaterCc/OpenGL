#include "ISence.h"
#include "../Object/Node/ObjectBase.h"
#include"../Framework/RenderPipelineManager.h"
#include"../Camera/Camera.h"

ISence::ISence()
{
	m_objSenceColor = { 0,0,0,1 };
}

void ISence::addToRenderingList(ObjectBase* object)
{
	RenderPiplineManager::getInstance()->addObjectToList(object, (object->getRenderTag()));
}

void ISence::removeObjectOfTarget(int tag)
{
	RenderPiplineManager::getInstance()->removeObjectAtIndex(tag);
}

void ISence::addToRenderingList(Light* object)
{

}

void ISence::registerCamera(Camera* object)
{
	RenderPiplineManager::getInstance()->addCameraToList(object);
	object->setActive(true);
}

void ISence::registerMainCamera(Camera* object)
{
	RenderPiplineManager::getInstance()->setMainCamera(object);
	object->setActive(true);
}

void ISence::unregisterCamera(Camera* object)
{
	RenderPiplineManager::getInstance()->removeObjectAtIndex(object->getTag());
}
