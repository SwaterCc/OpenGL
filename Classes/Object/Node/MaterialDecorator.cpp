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

MaterialDecorator::MaterialDecorator(ObjectBase* obj):ObjectDecorator(obj)
{

}
