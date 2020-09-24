#ifndef _LightManager_h_
#define _LightManager_h_

#include "../Object/Node/Light.h"

class LightManager
{
public:
	LightManager* getInstance();
	void registerLight(Light * obj);

private:
	LightManager();
	static LightManager* m_pInstance;
};



#endif // !_LightManager_h_
