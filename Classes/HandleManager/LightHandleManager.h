#ifndef _LightHandleManager_h_
#define _LightHandleManager_h_

#include "IHandleManager.h"

class LightHandleManager : public HandleManager
{
public:
	LightHandleManager* getInstance();
	virtual void registerHandle(Handle* obj) override;

private:
	LightHandleManager();
	static LightHandleManager* m_pInstance;
};



#endif // !_LightManager_h_