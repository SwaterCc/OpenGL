#ifndef _MaterialDecorator_h_
#define _MaterialDecorator_h_

#include"ObjectDecorator.h"
#include"../Attribute/Material.h"

class MaterialDecorator : public ObjectDecorator
{
public:
	static MaterialDecorator* create(ObjectBase* obj);
	static MaterialDecorator* create(ObjectBase* obj , Material * material);
	MaterialDecorator(ObjectBase* obj);
	MaterialDecorator(ObjectBase* obj, Material* material);
	virtual void update() override;
	virtual void draw() override;
public:
	void setAmbientStrenght(float a);
	void setDiffuseStrenght(float d);
	void setSpecularStrength(float s);
	void setShininess(float s);

	Material * getMaterial();
private:
	void updateMaterialUniform();

	Material* material;
};



#endif // !_MaterialDecorator_h_




