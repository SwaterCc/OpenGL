#ifndef _TextureDecorator_h_
#define _TextureDecorator_h_

#include"ObjectDecorator.h"
#include"../Texture/Texture2D.h"

#include<map>

class TextureDecorator : public ObjectDecorator
{
public:
	static TextureDecorator* create(ObjectBase* obj);
	TextureDecorator(ObjectBase* obj);

	virtual void update() override;
	virtual void draw() override;
};



#endif // !_MaterialDecorator_h_

