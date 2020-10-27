#ifndef _TextureDecorator_h_
#define _TextureDecorator_h_

#include"ObjectDecorator.h"
#include"../Attribute/Texture.h"

class TextureDecorator : public ObjectDecorator
{
public:
	static TextureDecorator* create(ObjectBase* obj);
	TextureDecorator(ObjectBase* obj);

	virtual void update() override;
	virtual void draw() override;
public:

private:
	Texture2D texture;
};



#endif // !_MaterialDecorator_h_

