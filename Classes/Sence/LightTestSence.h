
#ifndef _LightTestSence_h_
#define _LightTestSence_h_

#include"ISence.h"
#include"../Include/Include.h"

#include"../Include/GLObject.h"
USING_GL_OBJECT;

class LightTestSence :public ISence
{
public:
	static LightTestSence* create();
	virtual void init();
public:
	LightTestSence() = default;
};



#endif // !_DefaultSence_h_
