#ifndef _MaterialDecorator_h_
#define _MaterialDecorator_h_

#include"ObjectDecorator.h"
#include"../Attribute/Material.h"

class MaterialDecorator : public ObjectDecorator
{
public:
	static MaterialDecorator* create(ObjectBase* obj);
	MaterialDecorator(ObjectBase* obj);

	virtual void update() override;
	virtual void draw() override;
public:

private:
	Material material;
};



#endif // !_MaterialDecorator_h_




