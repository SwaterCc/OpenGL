#include "LightTestSence.h"

LightTestSence* LightTestSence::create()
{
	LightTestSence* p = new LightTestSence;
	return p;
}

void LightTestSence::init()
{
	setSenceBackgroundColor({ 0.0,0.0,0.0,1 });

	auto* cube = Cube::create();
	auto* mateDecorator = MaterialDecorator::create(cube);
	this->addToRenderingList(mateDecorator);
	_SOP(mateDecorator, v3(0, 0, 8.0));
	_SOS(mateDecorator, 4);
}

