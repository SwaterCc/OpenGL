#include "AttributeModule.h"

AttributeModule::AttributeModule(AttributeArray* array)
{
	registerModule(array);
}

void AttributeModule::registerModule(AttributeArray* array)
{
	array->add(this);
}
