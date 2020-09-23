#ifndef _LightManager_h_
#define _LightManager_h_

class Light;

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
