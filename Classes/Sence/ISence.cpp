#include "ISence.h"
#include "../Object/ObjectBase.h"
#include"../Framework/RenderPipelineManager.h"
#include"../Camera/Camera.h"

void ISence::addToRenderingList(ObjectBase* object)
{
	RenderPiplineManager::getInstance()->addObjectToList(object, (object->getRenderTag()));
}

void ISence::removeObjectOfTarget(int tag)
{
	RenderPiplineManager::getInstance()->removeObjectAtIndex(tag);
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
