#ifndef _LightDecorator_h_
#define _LightDecorator_h_

#include"ObjectDecorator.h"
#include"../../Framework/LightManager.h"

class LightDecorator : public ObjectDecorator
{
public:
	static LightDecorator* create(ObjectBase* obj);
	LightDecorator(ObjectBase* obj);

	virtual void update() override;
	virtual void draw() override;
};



#endif // !_MaterialDecorator_h_

