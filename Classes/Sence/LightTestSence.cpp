#include "LightTestSence.h"

LightTestSence* LightTestSence::create()
{
	LightTestSence* p = new LightTestSence;
	return p;
}

void LightTestSence::init()
{
	setSenceBackgroundColor({ 0.1,0.1,0.1,1 });
	auto* pLight = ParallelLight::create({ 0,1,0 }, { 0,0,0 });
	addToRenderingList(pLight);

	auto* pointLight = PointLight::create({ -10,0,20 }, 1, 0.022, 0.0019, glmath::vec3(1,0,0));
	addToRenderingList(pointLight);

	auto* pointLight1 = PointLight::create({10,20,20 }, 1, 0.022, 0.0019, glmath::vec3(1, 1, 0));
	addToRenderingList(pointLight1);

	auto* spotlight = Spotlight::create({ 0,0,-10 }, { 0,0,1}, 80.0f, 15.0f, glmath::vec3(0, 0, 1));
	addToRenderingList(spotlight);

	auto* spotlight1 = Spotlight::create({ 0,0,-10 }, { 0,0,1 }, 80.0f, 5.0f, glmath::vec3(1, 0, 0));
	addToRenderingList(spotlight1);

	auto* cube = Cube::create();
	auto* mateDecorator = MaterialDecorator::create(cube);
	auto* lightDec = LightDecorator::create(mateDecorator);
	this->addToRenderingList(lightDec);
	mateDecorator->setShininess(64);
	mateDecorator->setDiffuseTex(Texture2D::create("container2.png", GL_TEXTURE0));
	mateDecorator->setSpecularTex(Texture2D::create("container2_specular.png", GL_TEXTURE1));
	_SOP(mateDecorator, v3(1, 0, 18.0));
	_SOS(mateDecorator, 4);

	auto* cube1 = Cube::create();
	auto* mateDecorator1 = MaterialDecorator::create(cube1);
	auto* lightDec1 = LightDecorator::create(mateDecorator1);
	this->addToRenderingList(lightDec1);
	mateDecorator1->setShininess(64);
	mateDecorator1->setDiffuseTex(Texture2D::create("container2.png", GL_TEXTURE0));
	mateDecorator1->setSpecularTex(Texture2D::create("container2_specular.png", GL_TEXTURE1));
	_SOP(mateDecorator1, v3(5, 3, 28.0));
	_SOS(mateDecorator1, 4);


	auto* cube2 = Cube::create();
	auto* mateDecorator2 = MaterialDecorator::create(cube2);
	auto* lightDec2 = LightDecorator::create(mateDecorator2);
	this->addToRenderingList(lightDec2);
	mateDecorator2->setShininess(64);
	mateDecorator2->setDiffuseTex(Texture2D::create("container2.png", GL_TEXTURE0));
	mateDecorator2->setSpecularTex(Texture2D::create("container2_specular.png", GL_TEXTURE1));
	_SOP(lightDec2, v3(-7, -8, 35.0));
	_SOS(lightDec2, 4);


	auto* cube3 = Cube::create();
	auto* mateDecorator3 = MaterialDecorator::create(cube3);
	auto* lightDec3 = LightDecorator::create(mateDecorator3);
	this->addToRenderingList(lightDec3);
	mateDecorator3->setShininess(64);
	mateDecorator3->setDiffuseTex(Texture2D::create("container2.png", GL_TEXTURE0));
	mateDecorator3->setSpecularTex(Texture2D::create("container2_specular.png", GL_TEXTURE1));
	_SOP(lightDec3, v3(20, -8, 65.0));
	_SOS(lightDec3, 8);
}

