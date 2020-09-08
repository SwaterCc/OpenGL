#include "LightTestSence.h"

LightTestSence* LightTestSence::create()
{
	LightTestSence* p = new LightTestSence;
	return p;
}

void LightTestSence::init()
{
	auto* cube = Cube::create();
	this->addToRenderingList(cube);
	cube->setPosition({ 0,0,14 });
	cube->setRotate(-0.5, { 1,1,1 });
	cube->setScale(2);
	cube->setColor({ 0.2,0.7,0.5,1 });
	/*auto* sprite = Sprite::create("1.jpg");
	this->addToRenderingList(sprite);
	sprite->setPosition({ 0,0,1350 });*/
}

