#ifndef _LightDecorator_h_
#define _LightDecorator_h_

#include"ObjectDecorator.h"
#include"../Attribute/Texture.h"

class LightDecorator : public ObjectDecorator
{
public:
	static LightDecorator* create(ObjectBase* obj);
	LightDecorator(ObjectBase* obj);

	virtual void update() override;
	virtual void draw() override;
public:

private:
	Texture2D* texture;
};



#endif // !_MaterialDecorator_h_

