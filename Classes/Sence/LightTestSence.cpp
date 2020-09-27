#include "LightTestSence.h"

LightTestSence* LightTestSence::create()
{
	LightTestSence* p = new LightTestSence;
	return p;
}

void LightTestSence::init()
{
	setSenceBackgroundColor({ 0.0,0.0,0.0,1 });

	/*auto* light = Cube::create();
	this->addToRenderingList(light);
	light->setPosition({ 1,2,11 });
	light->setRotate(0.5, { 1,1,1 });
	light->setScale(0.4);
	light->setColor({ 1,1,1,1 });*/

	auto* cube = Cube::create();
	this->addToRenderingList(cube);
	_SOP(cube, v3(0, 0, 8.0));
	_SOS(cube, 4);
	//cube->setRotate(0.6, { 0,1,0 });
	cube->setColor({ 0.4,0.5,0.6,1 });
	/*auto* sprite = Sprite::create("1.jpg");
	this->addToRenderingList(sprite);
	sprite->setPosition({ 0,0,1350 });*/
}

