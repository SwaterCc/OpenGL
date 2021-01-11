#include "LightTestSence.h"

LightTestSence* LightTestSence::create()
{
	LightTestSence* p = new LightTestSence;
	return p;
}

void LightTestSence::init()
{
	setSenceBackgroundColor({ 0.3,0.5,0.2,1 });

	//auto* pLight = ParallelLight::create();

	auto* cube = Cube::create();
	auto* mateDecorator = MaterialDecorator::create(cube);
	auto* lightDec = LightDecorator::create(mateDecorator);
	this->addToRenderingList(lightDec);
	mateDecorator->setShininess(64);
	mateDecorator->setDiffuseTex(Texture2D::create("container2.png", GL_TEXTURE0));
	mateDecorator->setSpecularTex(Texture2D::create("container2_specular.png", GL_TEXTURE1));
	_SOP(mateDecorator, v3(0, 0, 18.0));
	_SOS(mateDecorator, 4);

	auto* cube1 = Cube::create();
	auto* mateDecorator1 = MaterialDecorator::create(cube1);
	auto* lightDec1 = LightDecorator::create(mateDecorator1);
	this->addToRenderingList(lightDec1);
	mateDecorator1->setShininess(64);
	mateDecorator1->setDiffuseTex(Texture2D::create("container2.png", GL_TEXTURE0));
	mateDecorator1->setSpecularTex(Texture2D::create("container2_specular.png", GL_TEXTURE1));
	_SOP(mateDecorator1, v3(14, 3, 28.0));
	_SOS(mateDecorator1, 4);


	auto* cube2 = Cube::create();
	auto* mateDecorator2 = MaterialDecorator::create(cube2);
	auto* lightDec2 = LightDecorator::create(mateDecorator2);
	this->addToRenderingList(lightDec2);
	mateDecorator2->setShininess(64);
	mateDecorator2->setDiffuseTex(Texture2D::create("container2.png", GL_TEXTURE0));
	mateDecorator2->setSpecularTex(Texture2D::create("container2_specular.png", GL_TEXTURE1));
	_SOP(mateDecorator2, v3(12, -8, 35.0));
	_SOS(mateDecorator2, 4);
}

