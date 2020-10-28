#include "TextureDecorator.h"

TextureDecorator* TextureDecorator::create(ObjectBase* obj)
{
	return nullptr;
}

TextureDecorator::TextureDecorator(ObjectBase* obj):ObjectDecorator(obj)
{
}

void TextureDecorator::update()
{
}

void TextureDecorator::draw()
{
}
