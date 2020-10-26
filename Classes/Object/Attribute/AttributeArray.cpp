#include "AttributeArray.h"
#include "AttributeModule.h"
void AttributeArray::add(AttributeModule* att)
{
	int modelID = att->getModuleID();
	m_list.insert({modelID, att});
}

void AttributeArray::remove(AttributeModule* att)
{
	auto it = m_list.find(att->getModuleID());
	m_list.erase(it);
}
