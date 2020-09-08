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
	cube->setPosition({ 0,0,101 });
	cube->setRotate(-0.5, { 0,1,1 });
}

