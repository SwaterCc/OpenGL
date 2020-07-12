#ifndef _DefaultSence_h_
#define _DefaultSence_h_

#include"ISence.h"
#include"../Include/Include.h"

#include"../Include/GLObject.h"
USING_GL_OBJECT;

class DefaultSence :public ISence
{
public:
	static DefaultSence* create();
	virtual void init();
public:
	DefaultSence() = default;
};



#endif // !_DefaultSence_h_


