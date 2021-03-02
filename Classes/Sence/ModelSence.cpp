#include "ModelSence.h"

ModelTestSence* ModelTestSence::create()
{
	ModelTestSence* p = new ModelTestSence();
	return p;
}

void ModelTestSence::init()
{
	setSenceBackgroundColor({ 0.1,0.1,0.1,1 });
}
