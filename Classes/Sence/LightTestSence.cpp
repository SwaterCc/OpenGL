#include "LightTestSence.h"

LightTestSence* LightTestSence::create()
{
	LightTestSence* p = new LightTestSence;
	return p;
}

void LightTestSence::init()
{
	setSenceBackgroundColor({ 0.3,0.5,0.2,1 });

	auto* cube = Cube::create();
	auto* mateDecorator = MaterialDecorator::create(cube);
	this->addToRenderingList(mateDecorator);
	//mateDecorator->setAmbientStrenght(0.2);
	//mateDecorator->setDiffuseStrenght(0.5);
	//mateDecorator->setSpecularStrength(0.5);
	mateDecorator->setShininess(64);
	mateDecorator->setDiffuseTex(Texture2D::create("container2.png", GL_TEXTURE0));
	mateDecorator->setSpecularTex(Texture2D::create("light.png", GL_TEXTURE1));
	_SOP(mateDecorator, v3(0, 0, 8.0));
	_SOS(mateDecorator, 4);
}

