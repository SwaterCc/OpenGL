#include "LightTestSence.h"

LightTestSence* LightTestSence::create()
{
	LightTestSence* p = new LightTestSence;
	return p;
}

void LightTestSence::init()
{
	setSenceBackgroundColor({ 0.1,0.2,0.5,0 });

	auto* light = Cube::create();
	this->addToRenderingList(light);
	light->setPosition({ -3,2,11 });
	light->setRotate(0.5, { 1,1,1 });
	light->setScale(0.4);
	light->setColor({ 1,1,1,1 });

	auto* cube = Cube::create();
	this->addToRenderingList(cube);
	cube->setPosition({ 1,-2,14 });
	cube->setRotate(0.1, { 0,1,0 });
	cube->setScale(3);
	cube->setColor({ 1,0.3,0.3,1 });
	/*auto* sprite = Sprite::create("1.jpg");
	this->addToRenderingList(sprite);
	sprite->setPosition({ 0,0,1350 });*/
}

