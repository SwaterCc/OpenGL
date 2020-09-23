#ifndef _I_HandleManager_h_
#define _I_HandleManager_h_

#include "../Handle/Handle.h"

class HandleManager
{
public:
	virtual void registerHandle(Handle* obj) = 0;
};

#endif // !_I_HandleManager_h_

