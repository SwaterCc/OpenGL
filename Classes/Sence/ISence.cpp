#include "ISence.h"
#include "../Object/ObjectBase.h"
#include"../Framework/RenderPipelineManager.h"

void ISence::addToRenderingList(ObjectBase* object)
{
	RenderPiplineManager::getInstance()->addObjectToList(object, (object->getRenderTag()));
}

void ISence::removeObjectOfTarget(int tag)
{
	RenderPiplineManager::getInstance()->removeObjectAtIndex(tag);
}
