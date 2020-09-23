#ifndef _LightHandle_h_
#define _LightHandle_h_

#include "Handle.h"

class LightHandle : public Handle
{
public:
	virtual void onTrigger() override;
};



#endif // !_LightHandle_h_

