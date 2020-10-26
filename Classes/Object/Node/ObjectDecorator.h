#ifndef _ObjectDecorator_h_
#define _ObjectDecorator_h_

#include "ObjectBase.h"

class ObjectDecorator :
	public ObjectBase
{
public:
	static ObjectDecorator* create(ObjectBase* obj);
	ObjectDecorator(ObjectBase* obj);

	virtual void update() override;
	virtual void UpdateUniform() override;
	virtual void draw() override;

	virtual Transform& getTransform() override;
protected:
	ObjectBase* m_pDecorated;
};


#endif // !_ObjectDecorator_h_

