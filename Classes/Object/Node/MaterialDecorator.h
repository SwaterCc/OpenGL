#ifndef _MaterialDecorator_h_
#define _MaterialDecorator_h_

#include"ObjectDecorator.h"
#include"../Attribute/Material.h"

#define MATERIAL_TEXTURE_DIFFUSE "Material.diffuseTex"
#define MATERIAL_TEXTURE_SPECULAR "Material.specularTex"

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
	void setDiffuseTex(Texture2D * tex);
	void setSpecularTex(Texture2D * tex);
	Material * getMaterial();
private:
	void updateMaterialUniform();

	Material* material;
};



#endif // !_MaterialDecorator_h_




