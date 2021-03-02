#ifndef _ModelTestSence_h_
#define _ModelTestSence_h_

#include"ISence.h"
#include"../Include/Include.h"

#include"../Include/GLObject.h"

USING_GL_OBJECT;

class ModelTestSence :public ISence
{
public:
	static ModelTestSence* create();
	virtual void init();
public:
	ModelTestSence() = default;
};



#endif // !_ModelTestSence_h_
